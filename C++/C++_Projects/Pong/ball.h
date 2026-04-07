#include "master.h"

class Ball {

    public: 
    float width, height, speed, ballVx, ballVy;
    SDL_FRect ballPos;

    Ball(float x, float y, float w, float h, float s)
     {
        ballPos = SDL_FRect{x, y, w, h};
        width = w;
        height = h;
        speed = s;
    }
    
    void setSpeed() {
        ballVx = speed;
        ballVy = speed;
    }






};