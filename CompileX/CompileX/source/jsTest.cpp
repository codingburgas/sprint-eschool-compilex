#include "../header/jstest.h"
#include "raylib.h"
#include <stdio.h>  // Include for printf
#include "../header/menu.h"

using namespace std;

bool isQuestionAnswered = false;
bool isAnswerCorrect = false;  // Track if the selected answer is correct

void InitializeJSQuiz() {
    // Initialize any data or variables needed for the JS quiz here
    isQuestionAnswered = false;
    isAnswerCorrect = false;
}

void DrawJSQuestionScreen() {
    const char* question = "What is the output of the following JavaScript code: console.log(2 + '2');";
    const char* answer1 = "4";  // Incorrect answer
    const char* answer2 = "'22'";  // Correct answer
    const char* answer3 = "undefined";  // Incorrect answer
    const char* answer4 = "Error";  // Incorrect answer

    Rectangle answerButton1 = { 100, 200, 30, 30 };  // Smaller checkboxes
    Rectangle answerButton2 = { 100, 250, 30, 30 };  // Smaller checkboxes
    Rectangle answerButton3 = { 100, 300, 30, 30 };  // Smaller checkboxes
    Rectangle answerButton4 = { 100, 350, 30, 30 };  // Smaller checkboxes
    Rectangle backButton = { 10, 10, 100, 40 };  // Position for the back button

    if (CheckCollisionPointRec(GetMousePosition(), backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        returnToPreviousMenu();  // Go back to the previous menu
    }

    // Declare the offset for positioning the answer text
    int textOffsetX = 40;  // Offset to move text to the right of the buttons
    int textOffsetY = 200;  // Start position for the first answer text

    // Draw the question
    DrawText(question, 100, 150, 20, BLACK);

    // Draw the answer buttons without displaying the answer text
    DrawButtonPlanet(answerButton1, "");
    DrawButtonPlanet(answerButton2, "");
    DrawButtonPlanet(answerButton3, "");
    DrawButtonPlanet(answerButton4, "");

    // Draw the answers to the right of the buttons
    // Display the answer texts in black, adjusted to the right of the checkboxes
    DrawText(answer1, answerButton1.x + textOffsetX, textOffsetY, 20, BLACK);
    DrawText(answer2, answerButton2.x + textOffsetX, textOffsetY + 50, 20, BLACK);
    DrawText(answer3, answerButton3.x + textOffsetX, textOffsetY + 100, 20, BLACK);
    DrawText(answer4, answerButton4.x + textOffsetX, textOffsetY + 150, 20, BLACK);
    DrawButton(backButton, "Back");

    // Handle answer clicks
    if (CheckCollisionPointRec(GetMousePosition(), answerButton1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isQuestionAnswered = true;
        isAnswerCorrect = false;  // Incorrect answer
        printf("Answer 1 clicked! Incorrect answer.\n");
    }
    if (CheckCollisionPointRec(GetMousePosition(), answerButton2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isQuestionAnswered = true;
        isAnswerCorrect = true;  // Correct answer
        printf("Answer 2 clicked! Correct answer.\n");
    }
    if (CheckCollisionPointRec(GetMousePosition(), answerButton3) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isQuestionAnswered = true;
        isAnswerCorrect = false;  // Incorrect answer
        printf("Answer 3 clicked! Incorrect answer.\n");
    }
    if (CheckCollisionPointRec(GetMousePosition(), answerButton4) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isQuestionAnswered = true;
        isAnswerCorrect = false;  // Incorrect answer
        printf("Answer 4 clicked! Incorrect answer.\n");
    }
    if (CheckCollisionPointRec(GetMousePosition(), backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        returnToPreviousMenu();  // Go back to the previous menu
    }

    // Display feedback message
    if (isQuestionAnswered) {
        if (isAnswerCorrect) {
            DrawText("Correct answer!", 100, 400, 20, GREEN);  // Correct answer message
        }
        else {
            DrawText("Incorrect answer! Try again.", 100, 400, 20, RED);  // Incorrect answer message
        }
    }

    // Handle back button click
    if (CheckCollisionPointRec(GetMousePosition(), backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isQuestionAnswered = false;
        printf("Going back to the main menu\n");
    }
}

