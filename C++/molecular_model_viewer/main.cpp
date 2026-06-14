#include <iostream>
#include "atom.h"
#include "raylib.h"
#include "raymath.h"



int main () {

    InitWindow(800, 450, "Molecular Model Viewer");
    SetTargetFPS(60);

    Vector3 loc1 = {-25,0,1};
    Vector3 loc2 = {25, 0, 1};

    Vector3 startPos = {0,0,50};
    Vector3 upPos = {0, 1, 0};
    Camera3D camera = {startPos, loc1, upPos, 90, CAMERA_PERSPECTIVE};

    float atomicSizeToSize = 0.15f;
    float modelScale = 1.0f;
    float rotationX = 0.0f;
    float rotationY = 0.0f;


    Atom Nitrogen= Atom();
    Nitrogen.atomName = "Nitrogen";
    Nitrogen.position = loc1;
    Nitrogen.radius = 56.0f * atomicSizeToSize;
    Nitrogen.color = BLUE; 

    Atom Oxygen;
    Oxygen.atomName = "Oxygen";
    Oxygen.position = loc2;
    Oxygen.radius = 48.0f * atomicSizeToSize;
    Oxygen.color = RED;

    while (!WindowShouldClose()) {

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mouseDelta = GetMouseDelta();
            rotationX += mouseDelta.x * 0.05f;
            rotationY += mouseDelta.y * 0.05f;
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

        Matrix transformMatrix = MatrixMultiply(rotationMat, scaleMatrix);



        BeginDrawing();
            //Indentation for clarity
            ClearBackground(WHITE);
            BeginMode3D(camera);

            Vector3 tloc1 = Vector3Transform(loc1, transformMatrix);
            Vector3 tloc2 = Vector3Transform(loc2, transformMatrix);


            DrawSphere(tloc1, Nitrogen.radius * modelScale, Nitrogen.color);
            DrawSphere(tloc2, Oxygen.radius * modelScale, Oxygen.color);
            DrawCylinderEx(tloc1, tloc2, 1 * modelScale, 1 * modelScale, 8, LIGHTGRAY);

            EndMode3D();
            DrawText("An Oxygen and Nitrogen in a molecular viewer!", 20, 20, 20, LIGHTGRAY);
        EndDrawing();

    }








}