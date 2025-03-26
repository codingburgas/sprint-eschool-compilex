#pragma once
#include "raylib.h"

// Global Variables
extern bool isJSQuestionAnswered;
extern bool isJSAnswerCorrect;

// Function Declarations
void InitializeJSQuiz();  // Function to initialize the JavaScript quiz
void DrawButton(Rectangle button, const char* text, bool isActive);  // Draw button UI
void DrawJSQuestionScreen();  // Function to draw the JavaScript quiz screen
void Update();  // Handle switching screens based on the current screen
void GameLoop();  // Game Loop function - entry point of the game
void returnToPreviousMenu();  // Return to the previous menu