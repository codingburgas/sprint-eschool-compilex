#include "../header/planet.h"
#include "raylib.h"
#include <stdio.h>  // Include for printf
#include "../header/menu.h"
#include "../header/jsTest.h"
#include "../header/cppTest.h"
#include "../header/htmlTest.h"  // Include htmlTest.h for handling HTML test

extern bool isCppQuizActive;  // Declare C++ quiz flag
extern bool isHtmlQuizActive; // Declare HTML quiz flag

void DrawTestSelectionMenu() {
    Rectangle jsButton = { 200, 150, 120, 120 };
    Rectangle cppButton = { 330, 200, 120, 120 };
    Rectangle htmlCssButton = { 460, 150, 120, 120 };
    Rectangle backButton = { 10, 10, 100, 40 };

    // Update the calls to DrawButton to include the isActive argument (set to false)
    DrawButton(jsButton, "JS", false);
    DrawButton(cppButton, "C++", false);
    DrawButton(htmlCssButton, "HTML", false);
    DrawButton(backButton, "Back", false);

    if (CheckCollisionPointRec(GetMousePosition(), jsButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        printf("JavaScript test selected!\n");
        isJSQuizActive = true;  // Set the flag to true when JS button is clicked
        InitializeJSQuiz();  // Initialize the JS quiz
    }
    if (CheckCollisionPointRec(GetMousePosition(), cppButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        printf("C++ test selected!\n");
        isCppQuizActive = true;  // Set the flag to true when C++ button is clicked
        InitializeCppQuiz();  // Initialize the C++ quiz
    }
    if (CheckCollisionPointRec(GetMousePosition(), htmlCssButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        printf("HTML & CSS test selected!\n");
        isHtmlQuizActive = true;  // Set the flag to true when HTML button is clicked
        InitializeHtmlQuiz();  // Initialize the HTML quiz
    }
    if (CheckCollisionPointRec(GetMousePosition(), backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        returnToPreviousMenu();  // Go back to the previous menu
    }
}

void DrawButtonPlanet(Rectangle button, const char* text) {
    DrawCircle(button.x + button.width / 2, button.y + button.height / 2, button.width / 2, DARKGRAY);

    if (CheckCollisionPointRec(GetMousePosition(), button)) {
        DrawCircle(button.x + button.width / 2, button.y + button.height / 2, button.width / 2, GRAY);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("%s test button clicked!\n", text);  // Log test button click
        }
    }

    Vector2 textSize = MeasureTextEx(GetFontDefault(), text, 20, 1.0f);
    DrawText(text, button.x + (button.width - textSize.x) / 2 + 10, button.y + (button.height - textSize.y) / 2 + 5, 20, WHITE);
}