import scipy.io as sc

key_name = []
key_data = []

mat_data = sc.loadmat('dataset_amb.mat')

print(mat_data.keys())

key_name.append("Fault Label")
key_data.append(mat_data['f_nv'])

key_name.append("Irradiance")
key_data.append(mat_data['irr'])

key_name.append("PVT")
key_data.append(mat_data['pvt'])

for i, j in zip(key_name, key_data):
    print (i)
    print (j)
    print ("\n")

print("--------------------")