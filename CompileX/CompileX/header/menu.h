#pragma once

#include "raylib.h"  // Include raylib for Rectangle and Vector2

void Menu();  // Main menu function
void DrawButton(Rectangle button, const char* text);  // Draw individual buttons
void DrawTestSelectionMenu();  // Draw test selection screen
void DrawButtonPlanet(Rectangle button, const char* text);  // Draw planet-shaped buttons
void returnToPreviousMenu();

