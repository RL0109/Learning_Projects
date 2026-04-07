#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const float PADDLE_SPEED = 300.0f;
const float BALL_SPEED = 250.0f; 

const float PADDLE_HEIGHT = 100.0f;
const float PADDLE_WIDTH = 10.0f;