#pragma once
#include "raylib.h"


void InitializeJSQuiz();  // Function to initialize the JS quiz
void DrawButton(Rectangle button, const char* text, bool isActive);  // Declare DrawButton here
void DrawJSQuestionScreen();  // Function to draw the JS quiz screen
void Update();// Handle switching screens based on the current screen
void GameLoop();// Game Loop function - this is the entry point of the game.
void returnToPreviousMenu();








