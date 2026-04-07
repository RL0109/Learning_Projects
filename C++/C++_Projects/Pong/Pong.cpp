#include "master.h"
#include "paddle.h"
#include "ball.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("PONG", SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    Paddle player1(5.0f, 300.0f, PADDLE_WIDTH, PADDLE_HEIGHT,SCREEN_WIDTH,SCREEN_HEIGHT, true);
    Paddle player2 = {SCREEN_WIDTH- 15.0f, 300.0f, PADDLE_WIDTH, PADDLE_HEIGHT, SCREEN_WIDTH , SCREEN_HEIGHT, false};
    SDL_FRect ball = { 350.0f, 250.0f, 10.0f, 10.0f };

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




    float ballVX = BALL_SPEED;
    float ballVY = BALL_SPEED;

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

        if (ball.y > SCREEN_HEIGHT - 5.0f) {
            ball.y = SCREEN_HEIGHT - 5.0f - 0.1f;
            ballVY = -ballVY;
        } 
        if (ball.y < 0) {
            ball.y = 0 + 0.1f;
            ballVY  = -ballVY;
        }

        if (ball.x > SCREEN_WIDTH || ball.x < 0) {
            
            ball.x = SCREEN_WIDTH*0.5;
            ball.y = SCREEN_HEIGHT*0.5;
            roundDelayTimer = 2.0f;
        }

        if (ball.x > player1.player.x && ball.x < player1.player.x + player1.width) {
            if (ball.y > player1.player.y && ball.y < player1.player.y + player1.height)
                {
                    float intersect = (ball.y + (ball.h /2)) - (player1.player.y + (player1.height /2.0f)); 
                    float relIntersect = intersect / (player1.height/2.0f);
                    float bounceAngle = relIntersect * (M_PI /4.0f);
                    ball.x = player1.player.x + player1.width + 1.0f;
                    ballVX = BALL_SPEED * cos(bounceAngle);
                    ballVY = BALL_SPEED * sin(bounceAngle);
                    
                }
                
        } 

        if (ball.x < player2.player.x && ball.x > player2.player.x - player2.width) {
            if (ball.y > player2.player.y && ball.y < player2.player.y + player2.height) {
                float intersect = (ball.y + (ball.h /2.0f)) - (player2.player.y + (player2.height /2.0f)); 
                float relIntersect = intersect / (player2.height/2.0f);
                float bounceAngle = relIntersect * (M_PI /4.0f);
                ball.x = player2.player.x - player2.width - 1.0f;
                ballVX = -BALL_SPEED * cos(bounceAngle);
                ballVY = BALL_SPEED * sin(bounceAngle);
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
        SDL_RenderFillRect(renderer, &ball);

        for (int i = 0; i < totalLines * stride; i += 4) {
            SDL_FRect line = {lines[i], lines[i+1],lines[i+2],lines[i+3]};
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 200);
            SDL_RenderFillRect(renderer, &line);
        }

        SDL_RenderPresent(renderer);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;

}