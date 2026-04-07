#include "master.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("PONG", 800, 600, 0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    Paddle player1(5.0f, 300.0f, PADDLE_WIDTH, PADDLE_HEIGHT,SCREEN_WIDTH,SCREEN_HEIGHT, true);
    Paddle player2 = {785.0f, 300.0f, PADDLE_WIDTH, PADDLE_HEIGHT, SCREEN_WIDTH , SCREEN_HEIGHT, false};
    SDL_FRect ball = { 350.0f, 250.0f, 10.0f, 10.0f };

    float roundDelayTimer = 2.0f;


    // stride is the amount of data per line object stored in the array
    int const stride = 4;
    int const totalLines = 30;

    // lines is the array holding the info of the each line
    float lines[totalLines * stride];

    float yOffset = 5.0f;

    for (int i = 0; i < totalLines * stride; i += 4) {
        lines[i] = SCREEN_WIDTH/2;
        lines[i + 1] = yOffset;
        lines[i + 2] = 5;
        lines[i + 3] = 5;
        yOffset += SCREEN_HEIGHT/totalLines;
    }




    float ballVX = BALL_SPEED;
    float ballVY = BALL_SPEED;

    SDL_Event event;
    bool running = true;
    bool ballBounced = false;
    bool inBounds = true;
    Uint64 lastTime = SDL_GetTicks();

    while (running) {

        Uint64 now = SDL_GetTicks();
        float dt = (now - lastTime) / 1000.0f;
        lastTime = now;

        while (SDL_PollEvent(&event)) 
            if (event.type == SDL_EVENT_QUIT)
                running = false;

        const bool* keys = SDL_GetKeyboardState(NULL);

        if (roundDelayTimer > 0) {
            roundDelayTimer -= dt;
        }


        player1.movePadde(PADDLE_SPEED, dt, keys);
        player2.movePadde(PADDLE_SPEED, dt, keys);

        // if (keys[SDL_SCANCODE_W] && player1.y > 0) {
        //     player1.y -= PADDLE_SPEED *dt;
        // }

        // if (keys[SDL_SCANCODE_S]&& player1.y < SCREEN_HEIGHT - PADDLE_HEIGHT) {
        //     player1.y += PADDLE_SPEED *dt;
        // }

        // if (keys[SDL_SCANCODE_UP] && player2.y > 0) {
        //     player2.y -= PADDLE_SPEED *dt;
        // }

        // if (keys[SDL_SCANCODE_DOWN]&& player2.y < SCREEN_HEIGHT - PADDLE_HEIGHT) {
        //     player2.y += PADDLE_SPEED *dt;
        // }

        if (roundDelayTimer <= 0) {
            ball.y += ballVY * dt;
            ball.x += ballVX * dt;
        }

        if (ball.y > SCREEN_HEIGHT || ball.y < 0) {
            if (inBounds) {
                ballVY = -ballVY;
                inBounds = false;
            }
        } else {
            inBounds = true;
        }

        if (ball.x > SCREEN_WIDTH || ball.x < 0) {
            
            ball.x = SCREEN_HEIGHT*0.5;
            ball.y = SCREEN_WIDTH*0.5;
            roundDelayTimer = 2.0f;
        }

        if (ball.x > player1.xLoc && ball.x < player1.xLoc + player1.width) {
            if (ball.y > player1.yLoc && ball.y < player1.yLoc + player1.height)
                {
                    float intersect = ball.y + (ball.h /2) - player1.yLoc + (player1.height /2); 
                    float relIntersect = intersect / player1.height/2;
                    float bounceAngle = relIntersect * (M_PI *4);
                    ball.x = player1.xLoc + player1.width + 1.0f;
                    ballVX = -ballVX * cos(bounceAngle);
                }
                
        } 

        if (ball.x < player2.xLoc && ball.x > player2.xLoc - PADDLE_WIDTH) {
            if (ball.y > player2.yLoc && ball.y < player2.yLoc + PADDLE_HEIGHT)
                ball.x = player2.xLoc - player2.width - 1.0f;
                ballVX = -ballVX;
                
        } 

        // Draw a dark grey background
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &player1.player);

        
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &player2.player);



        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &ball);

        for (int i = 0; i < totalLines * stride; i += 4) {
            SDL_FRect line = {lines[i], lines[i+1],lines[i+2],lines[i+3]};
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &line);
        }

        SDL_RenderPresent(renderer);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;

}