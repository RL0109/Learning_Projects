#include "raylib.h"
#include "sphere.h"
#include "raymath.h"
//#include <string>
#include <thread>

int main() {

    InitWindow(800, 400, "Raylib Hello World");

    SetTargetFPS(60);
    Vector3 loc1 = {0,0,1};
    Vector3 loc2 = {8,0,1};

    float rotationY = 0.0f;
    float rotationX = 0.0f;
    float modelScale = 1.0f;

    Sphere sphere1(loc1, 7, RED);
    Sphere sphere2(loc2, 7, BLUE);
    Vector3 startpos = {0,0,25};
    Vector3 upPosition = {0,1,0};
    Camera3D camera = {startpos, sphere1.position, upPosition, 110, CAMERA_PERSPECTIVE};

    while (!WindowShouldClose()) {

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mouseDelta = GetMouseDelta();
            rotationY += mouseDelta.x * 0.05f;
            rotationX += mouseDelta.y * 0.05f;
        }

        float scroll = GetMouseWheelMove();
        if(scroll != 0.0f) {
            modelScale += scroll * 0.05f;

            if (modelScale < 0.1f) 
            modelScale = 0.1f;
        }
        
        Vector3 rotationVector = {rotationX, rotationY, 0.0f};
        Matrix rotationMat = MatrixRotateXYZ(rotationVector);
        Matrix scaleMatrix = MatrixScale(modelScale, modelScale, modelScale);

        Matrix transformMatrix = MatrixMultiply(scaleMatrix, rotationMat);


        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);

            Vector3 rLoc1 = Vector3Transform(loc1, transformMatrix);
            Vector3 rLoc2 = Vector3Transform(loc2, transformMatrix);
            
            DrawSphere(rLoc1, sphere1.radius * modelScale * 0.5f, sphere1.color);
            DrawSphere(rLoc2, sphere2.radius * modelScale * 0.5f, sphere2.color);
            DrawTriangle3D({0, 7,1}, {0, 15, 15}, {0,7, 20}, GREEN);
            DrawTriangle3D({0, 7,1}, {0, 7, 20}, {0,15, 15}, GREEN);
            
            EndMode3D();
            DrawText("Testing Affine Transformations!", 20, 20, 20, LIGHTGRAY);
        EndDrawing();


    }

    CloseWindow();

    return 0;

}