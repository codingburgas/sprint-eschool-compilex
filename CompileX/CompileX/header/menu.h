#pragma once

#include "raylib.h"  // Include raylib for Rectangle and Vector2

// Declare the global variables as extern
extern bool isStartClicked;
extern bool isJSQuizActive;

// Function declarations
void Menu();  // Main menu function
void DrawButton(Rectangle button, const char* text);  // Draw individual buttons

void returnToPreviousMenu();
