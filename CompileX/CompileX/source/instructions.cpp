#include "../header/instructions.h"
#include "raylib.h"
#include <stdio.h>

void DrawInstructionsScreen() {
    const char* instructionsText = "Here are the instructions on how to play...\n\nStep 1: Do this\nStep 2: Do that...\n";

    // Draw instructions screen
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Display instructions text
    DrawText(instructionsText, 100, 100, 20, BLACK);

    // Draw the "Back" button to return to the main menu
    Rectangle backButton = { 300, 400, 150, 40 };
    DrawButton(backButton, "Back");

    // Handle the click on the Back button
    if (CheckCollisionPointRec(GetMousePosition(), backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        returnToPreviousMenu();  // Go back to the main menu
    }

    EndDrawing();
}
