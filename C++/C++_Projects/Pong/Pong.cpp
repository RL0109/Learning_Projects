#include "master.h"
#include "paddle.h"
#include "ball.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("PONG", SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    Paddle player1(5.0f, 300.0f, PADDLE_WIDTH, PADDLE_HEIGHT,SCREEN_WIDTH,SCREEN_HEIGHT, true);
    Paddle player2(SCREEN_WIDTH- 15.0f, 300.0f, PADDLE_WIDTH, PADDLE_HEIGHT, SCREEN_WIDTH , SCREEN_HEIGHT, false);
    Ball ball( 350.0f, 250.0f, 10.0f, 10.0f, BALL_SPEED);

    float roundDelayTimer = 2.0f;


    // stride is the amount of data per line object stored in the array
    int const stride = 4;
    int const totalLines = 30;

    // lines is the array holding the info of the each line
    float lines[totalLines * stride];

    float yOffset = 5.0f;

    for (int i = 0; i < totalLines * stride; i += stride) {
        lines[i] = SCREEN_WIDTH/2;
        lines[i + 1] = yOffset;
        lines[i + 2] = 5;
        lines[i + 3] = 5;
        yOffset += SCREEN_HEIGHT/totalLines;
    }

    SDL_Event event;

    // Need loop to finish before exiting.
    bool running = true;

    // Gets the time in order to get deltaTime in loop.
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

        if (roundDelayTimer <= 0) {
            ball.moveBall(dt);
        }

        if (ball.ballPos.y > SCREEN_HEIGHT - 5.0f) {
            ball.ballPos.y = SCREEN_HEIGHT - 5.0f - 0.1f;
            ball.ballVy = -ball.ballVy;
        } 
        if (ball.ballPos.y < 0) {
            ball.ballPos.y = 0 + 0.1f;
            ball.ballVy  = -ball.ballVy;
        }

        if (ball.ballPos.x > SCREEN_WIDTH || ball.ballPos.x < 0) {
            ball.ballPos.x = SCREEN_WIDTH*0.5;
            ball.ballPos.y = SCREEN_HEIGHT*0.5;
            roundDelayTimer = 2.0f;
        }

        if (ball.ballPos.x > player1.player.x && ball.ballPos.x < player1.player.x + player1.width) {
            if (ball.ballPos.y > player1.player.y && ball.ballPos.y < player1.player.y + player1.height)
                {
                    float intersect = (ball.ballPos.y + (ball.height /2)) - (player1.player.y + (player1.height /2.0f)); 
                    float relIntersect = intersect / (player1.height/2.0f);
                    float bounceAngle = relIntersect * (M_PI /4.0f);
                    ball.ballPos.x = player1.player.x + player1.width + 1.0f;
                    ball.deflectBall(bounceAngle, true);
                }
                
        } 

        if (ball.ballPos.x < player2.player.x && ball.ballPos.x > player2.player.x - player2.width) {
            if (ball.ballPos.y > player2.player.y && ball.ballPos.y < player2.player.y + player2.height) 
            {
                float intersect = (ball.ballPos.y + (ball.height /2.0f)) - (player2.player.y + (player2.height /2.0f)); 
                float relIntersect = intersect / (player2.height/2.0f);
                float bounceAngle = relIntersect * (M_PI /4.0f);
                ball.ballPos.x = player2.player.x - player2.width - 1.0f;
                ball.deflectBall(bounceAngle, false);
            }
        } 

        // Draw a dark grey background
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &player1.player);

        
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &player2.player);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &ball.ballPos);

        for (int i = 0; i < totalLines * stride; i += 4) {
            SDL_FRect line = {lines[i], lines[i+1],lines[i+2],lines[i+3]};
            SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
            SDL_RenderFillRect(renderer, &line);
        }

        SDL_RenderPresent(renderer);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;

}