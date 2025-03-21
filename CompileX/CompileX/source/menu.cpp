#include "../header/menu.h"
#include "../header/planet.h"
#include "../header/main.h"
#include "../header/jstest.h"
#include "../header/instructions.h"  // Include the instructions header to call the DrawInstructionsScreen function
#include "raylib.h"
#include <stdio.h>  // For logging button clicks

using namespace std;

bool isStartClicked = false;
bool isJSQuizActive = false;
bool isHowToPlayActive = false;  // Flag to track if the instructions screen is active

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

        if (!isStartClicked && !isHowToPlayActive) {
            // Main menu screen
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

            if (CheckCollisionPointRec(GetMousePosition(), howToPlayButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                // Switch to instructions screen when clicked
                isHowToPlayActive = true;
            }
        }
        else if (isHowToPlayActive) {
            // Instructions screen
            DrawInstructionsScreen();  // This will now call the function from instructions.cpp
        }
        else if (isJSQuizActive) {
            DrawJSQuestionScreen();
        }
        else {
            DrawTestSelectionMenu();
        }

        EndDrawing();
    }

    CloseWindow();
}

// Function to draw a button
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
    isJSQuizActive = false;
    isHowToPlayActive = false;  // Reset flag to return to the main menu
}
