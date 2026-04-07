#include "master.h"

class Ball {

    public: 
    float xLoc, yLoc, width, height, screen_width, screen_height;
    bool isPlayer1;
    SDL_FRect ball;

    Ball(float x, float y, const float w, const float h, float sw, float sh)
        : screen_width(sw) , screen_height(sh)
     {
        ball = SDL_FRect{x, y, w, h};
        xLoc = x;
        yLoc = y;
        width = w;
        height = h;

    }




}