#include "raylib.h"
#include "sphere.h"
//#include <string>
#include <thread>

int main() {

    InitWindow(800, 400, "Raylib Hello World");

    SetTargetFPS(60);
    Vector3 loc1 = {0,0,1};
    Vector3 loc2 = {8,0,1};
    Sphere sphere1(loc1, 7, RED);
    Sphere sphere2(loc2, 7, BLUE);
    Vector3 startpos = {0,0,25};
    Vector3 upPosition = {0,1,0};
    Camera3D camera = {startpos, sphere1.position, upPosition, 90, 1};

    while (!WindowShouldClose()) {

        
        
        BeginDrawing();
            BeginMode3D(camera);
            UpdateCamera(&camera, CAMERA_ORBITAL);
            ClearBackground(RAYWHITE);
            DrawSphere(sphere1.position, sphere1.radius, sphere1.color);
            DrawSphere(sphere2.position, sphere2.radius, sphere2.color);
            DrawText("Hello, World!", 190, 200, 20, LIGHTGRAY);
            EndMode3D();
        EndDrawing();


    }

    CloseWindow();

    return 0;

}