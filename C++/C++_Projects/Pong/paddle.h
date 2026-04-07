#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class Paddle {
    public: 
    float xLoc, yLoc, width, height, screen_width, screen_height;
    bool playerDirection;
    SDL_FRect player;

    Paddle(float x, float y, const float w, const float h) {
        player = SDL_FRect{x, y, w, h};
        xLoc = x;
        yLoc = y;
        width = w;
        height = h;
        //playerDirection = playerSide;

    }

    float getCenter() {
        return yLoc + (height / 2.0f);
    }

    void getScreenDimensions(float sw, float sh) {
        screen_width = sw;
        screen_height = sh;
    }

    void movePadde(float paddleSpeed, float dt, const bool* keys) {
        if (true) {
            if (keys[SDL_SCANCODE_W] && player.y > 0) {
            player.y -= paddleSpeed *dt;
        }

        if (keys[SDL_SCANCODE_S]&& player.y < screen_height - height) {
            player.y += paddleSpeed *dt;
        }
        } else {
            if (keys[SDL_SCANCODE_UP] && player.y > 0) {
                player.y -= paddleSpeed *dt;
            }

            if (keys[SDL_SCANCODE_DOWN]&& player.y < screen_height - height) {
                player.y += paddleSpeed *dt;
            }
        }
    }




};