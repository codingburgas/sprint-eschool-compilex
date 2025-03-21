#pragma once

#include "raylib.h"  // Include raylib for Rectangle and Vector2

// Declare global flags
extern bool isStartClicked;
extern bool isJSQuizActive;
extern bool isHowToPlayActive;

// Function declarations
void Menu();  // Main menu function
void DrawButton(Rectangle button, const char* text);  // Declare DrawButton here
void returnToPreviousMenu();  // Function to go back to the previous menu
void OpenInstructionsWindow();  // Declare OpenInstructionsWindow here
