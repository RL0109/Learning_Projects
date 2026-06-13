#pragma once
#include "raylib.h"
#include <iostream>

class Sphere {
    public:
    Vector3 position;
    float radius;
    Color color;

    Sphere (Vector3 p, float r, Color c) {
        position = p;
        radius = r;
        color = c;
    }
};