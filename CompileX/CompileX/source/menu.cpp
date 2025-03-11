#include "../header/planet.h"  // Include the header where DrawTestSelectionMenu and DrawButtonPlanet are declared
#include "../header/menu.h"
#include "../header/main.h"
#include "../header/jstest.h"  // Include the JavaScript test header
#include "raylib.h"
#include <stdio.h>  // Include for printf

using namespace std;

bool isStartClicked = false;  // Declare globally to track the menu state
bool isJSQuizActive = false;  // Track if the JavaScript test screen is active

void Menu() {
    int width = 800;
    int height = 600;
    const char* text = "Welcome to the CompileX Test System";

    InitWindow(width, height, text);
    SetTargetFPS(60);

    Rectangle startButton = { 300, 200, 150, 40 };
    Rectangle howToPlayButton = { 300, 270, 150, 40 };
    Rectangle aboutUsButton = { 300, 340, 150, 40 };
    Rectangle exitButton = { 300, 410, 150, 40 };

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (!isStartClicked) {
            int textWidth = MeasureText(text, 20);
            int textHeight = 20;
            int x = (GetScreenWidth() - textWidth) / 2;
            int y = (GetScreenHeight() - textHeight) / 2 - 150;
            DrawText(text, x, y, 20, BLACK);

            DrawButton(startButton, "Start");
            DrawButton(howToPlayButton, "How to Play");
            DrawButton(aboutUsButton, "About Us");
            DrawButton(exitButton, "Exit");

            if (CheckCollisionPointRec(GetMousePosition(), exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
            }

            if (CheckCollisionPointRec(GetMousePosition(), startButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                isStartClicked = true;
            }
        }
        else if (isJSQuizActive) {
            DrawJSQuestionScreen();  // Call the JavaScript question screen when active
        }
        else {
            DrawTestSelectionMenu();  // Draw the test selection menu
        }

        EndDrawing();
    }

    CloseWindow();
}

void DrawButton(Rectangle button, const char* text) {
    DrawRectangleRec(button, LIGHTGRAY);

    if (CheckCollisionPointRec(GetMousePosition(), button)) {
        DrawRectangleRec(button, GRAY);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("%s button clicked!\n", text);  // Log button click
        }
    }

    Vector2 textSize = MeasureTextEx(GetFontDefault(), text, 20, 1.0f);
    DrawText(text, button.x + (button.width - textSize.x) / 2, button.y + (button.height - textSize.y) / 2, 20, BLACK);
}

void returnToPreviousMenu() {
    isStartClicked = false;
    isJSQuizActive = false;  // Reset JS quiz flag to go back to the test selection menu
}


