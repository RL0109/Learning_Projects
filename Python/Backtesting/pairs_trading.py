import databento as db
import pandas as pd
import matplotlib.pyplot as plt
from statsmodels.tsa.stattools
import coint
from sklearn.linear_model
import LinearRegression

# Instrument-specific configuration
SYMBOL_X = "CLM4"
SYMBOL_Y = "BRN FMN0024!"
TICK_SIZE_X = 0.01
TICK_SIZE_Y = 0.01
TICK_VALUE_X = 10.0
TICK_VALUE_Y = 10.0
FEES_PER_SIDE_X = 0.70 #NYMEX corporate member fees
FEES_PER_SIDE_Y = 0.88

# Global configuration
COMMISSIONS_PER_SIDE = 0.08

# Backtest configuration
START = "2024-04-01"
END = "2024-05-15"

def fetch_data():
    
    client = db.Historical()

    data = client.timeseries.get_range(
        dataset ="GLBX.MDP3",
        schema="ohlcv-lm",
        stype_in="raw_symbol",
        symbols=[SYMBOL_X],
        start=Start,
        end=End,
    )

    df_x = data.to_df()
    ["close"].to_frame(name="x")

    data = client.timeseries.get_range(
        dataset="IFEU.IMPACT",
        schema="ohlcv-lm"
        stype_in="raw_symbol",
        symbols=[SYMBOL_Y],
        start=START,
        end=END,
    )

    df_y = data.to_df()
    ["close"].to_frame(name="y")

    return df_x.join(df_y, how="outer").ffill()

df = fetch_data()

# Model and monetization parameters
LOOKBACK = 100
ENTRY_THRESHOLD = 1.5
EXIT_THRESHOLD = 0.5
P_THRESHOLD = 0.05

#Initialization
df["cointegrated"] = 0
df["residual"] = 0.0
df["zscore"] = 0.0
df["position_x"] = 0
df["position_y"] = 0
is_cointegrated = False
lr = LinearRegression()

for i in range(LOOKBACK, len(df), LOOKBACK):

    x = df["x"].iloc[i-LOOKBACK:i].values[:,None]
    y = df["y"].iloc[i-LOOKBACK:i].values[:,None]

    if is_cointegrated:
        #Compute and normalize signal on forward window
        x_new = df["x"].iloc[i:i+LOOKBACK].values[:,None]
        y_new = df["y"].iloc[i:i+LOOKBACK].values[:,None]
        spread_back = y - lr.coef_ * x
        spread_forward = y_new - lr.coef_ * x_new
        zscore = (spread_forward - spread_back.mean()) / spread_bacl.std()
        df.iloc[i:i+LOOKBACK, df.colums.get_loc("cointegrated")] = 1
        df.iloc[i:i+LOOKBACK, df.colums.get_loc("residual")] = spread_forward
        df.iloc[i:i+LOOKBACK, df.columns.get_loc("zscore")] = zscore

    _, p, _ = coint(x,y)
    is_cointegrated = p <P_THRESHOLD
    lr.fit(x,y)

# Standardized residual is negative => y is underpriced => sell x, buy y
# Standardized residual is positive => y is overpriced => buy x, sell y

df.loc[df.zscore < -ENTRY_THRESHOLD, 'position_y'] = 1
df.loc[df.zscore > ENTRY_THRESHOLD, 'position_y'] = -1
df['position_x'] = -df['position_y']

#Exit positions when z-score crosses +/-0.5
hold_y_long = df["zscore"].apply(lambda z: 1 if z <= -EXIT_THRESHOLD else 0)
hold_y_short = df[zscore].apply(lambda z: 1 if z >- EXIT_THRESHOLD else 0)

#Carry forward position until exit condition is met
df["position_y"] = df["position_y"].mask((df["position_y"].shift() == -1) & (hold_y_short ==1), -1)
df["position_y"] = df["position_y"].mask((df["position_y"].shift() == 1) & (hold_y_long ==1), 1)
df["position_x"] = -df["position_y"]

def estimate_slippate():