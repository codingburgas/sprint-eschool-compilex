#include "../header/menu.h"
#include "../header/planet.h"
#include "../header/main.h"
#include "../header/jstest.h"
#include "../header/cppTest.h"  // Include cppTest.h
#include "../header/htmlTest.h"  // Include htmlTest.h
#include "raylib.h"
#include <stdio.h>  // For logging button clicks

using namespace std;

bool isStartClicked = false;
bool isJSQuizActive = false;
bool isCppQuizActive = false;  // Track if C++ quiz is active
bool isHtmlQuizActive = false;  // Track if HTML quiz is active
bool isHowToPlayActive = false;  // Flag to track if the instructions screen is active
bool isAboutUsActive = false;    // Flag to track if the About Us screen is active

void Menu() {
    int width = 800;
    int height = 600;
    const char* text = "Welcome to the CompileX Test System";

    InitWindow(width, height, text);
    SetExitKey(KEY_NULL); // Disable ESC from closing the window
    SetTargetFPS(60);

    Texture2D background = LoadTexture("../assets/galaxy-space.png");  // Make sure the file exists!

    Rectangle startButton = { 300, 200, 150, 40 };
    Rectangle howToPlayButton = { 300, 270, 150, 40 };
    Rectangle aboutUsButton = { 300, 340, 150, 40 };
    Rectangle exitButton = { 300, 410, 150, 40 };

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(background, 0, 0, WHITE); // Draw background

        if (!isStartClicked && !isHowToPlayActive && !isAboutUsActive) {
            // Main menu screen
            int textWidth = MeasureText(text, 20);
            int textHeight = 20;
            int x = (GetScreenWidth() - textWidth) / 2;
            int y = (GetScreenHeight() - textHeight) / 2 - 150;
            DrawText(text, x, y, 20, BLACK);

            // Draw the buttons
            DrawButton(startButton, "Start", false);
            DrawButton(howToPlayButton, "How to Play", isHowToPlayActive);
            DrawButton(aboutUsButton, "About Us", isAboutUsActive);
            DrawButton(exitButton, "Exit", false);

            // Button actions
            if (CheckCollisionPointRec(GetMousePosition(), exitButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                CloseWindow();
            }

            if (CheckCollisionPointRec(GetMousePosition(), startButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                isStartClicked = true;
            }

            if (CheckCollisionPointRec(GetMousePosition(), howToPlayButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                isHowToPlayActive = true;
            }

            if (CheckCollisionPointRec(GetMousePosition(), aboutUsButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                isAboutUsActive = true;
            }
        }
        else if (isHowToPlayActive) {
            // Instructions screen (How to Play)
            DrawText("How to Play:", 50, 50, 30, BLACK);
            DrawText("1. Use arrow keys to move.", 50, 100, 20, BLACK);
            DrawText("2. Avoid obstacles and collect points.", 50, 130, 20, BLACK);
            DrawText("3. Press 'Enter' to start the game.", 50, 160, 20, BLACK);
            DrawText("Press 'Escape' to go back.", 50, 200, 20, BLACK);

            if (IsKeyPressed(KEY_ESCAPE)) {
                returnToPreviousMenu();  // Go back to main menu
            }
        }
        else if (isAboutUsActive) {
            // About Us screen content
            DrawText("About Us", 300, 150, 30, BLACK);
            DrawText("This game is developed by CompileX Studios.", 50, 200, 20, BLACK);
            DrawText("We specialize in creating fun and educational games.", 50, 230, 20, BLACK);
            DrawText("Thank you for playing our game!", 50, 260, 20, BLACK);
            DrawText("Press 'Escape' to go back.", 50, 300, 20, BLACK);

            if (IsKeyPressed(KEY_ESCAPE)) {
                returnToPreviousMenu();  // Go back to main menu
            }
        }
        else if (isJSQuizActive) {
            DrawJSQuestionScreen();
        }
        else if (isCppQuizActive) {
            DrawCppQuestionScreen();  // Display C++ quiz screen
        }
        else if (isHtmlQuizActive) {
            DrawHtmlQuestionScreen();  // Display HTML quiz screen
        }
        else {
            DrawTestSelectionMenu();
        }

        EndDrawing();
    }

    CloseWindow();
}

// Function to draw a button with an additional 'isActive' argument
void DrawButton(Rectangle button, const char* text, bool isActive) {
    Color buttonColor = isActive ? DARKGRAY : LIGHTGRAY;  // Highlight button when active

    DrawRectangleRec(button, buttonColor);

    if (CheckCollisionPointRec(GetMousePosition(), button)) {
        DrawRectangleRec(button, GRAY);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("%s button clicked!\n", text);  // Log button click
        }
    }

    Vector2 textSize = MeasureTextEx(GetFontDefault(), text, 20, 1.0f);
    DrawText(text, button.x + (button.width - textSize.x) / 2, button.y + (button.height - textSize.y) / 2, 20, BLACK);
}

// Function to reset the menu state when returning from sub-menus
void returnToPreviousMenu() {
    isStartClicked = false;
    isJSQuizActive = false;
    isCppQuizActive = false;  // Reset C++ quiz state
    isHtmlQuizActive = false;  // Reset HTML quiz state
    isHowToPlayActive = false;  // Reset flag to return to the main menu
    isAboutUsActive = false;    // Reset flag to return to the main menu
}