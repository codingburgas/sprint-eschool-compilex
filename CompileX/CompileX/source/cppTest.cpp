#include "../header/cpptest.h"
#include "raylib.h"
#include <stdio.h>  // Include for printf
#include "../header/menu.h"
#include "../header/planet.h"

bool isCppQuestionAnswered = false;
bool isCppAnswerCorrect = false;  // Track if the selected answer is correct

void InitializeCppQuiz() {
    isCppQuestionAnswered = false;
    isCppAnswerCorrect = false;
}

void DrawCppQuestionScreen() {
    const char* question = "What will be the output of the following C++ code: cout << 2 + '2';";
    const char* answer1 = "4";  // Incorrect answer
    const char* answer2 = "50";  // Correct answer
    const char* answer3 = "Error";  // Incorrect answer
    const char* answer4 = "undefined";  // Incorrect answer

    Rectangle answerButton1 = { 100, 200, 30, 30 };
    Rectangle answerButton2 = { 100, 250, 30, 30 };
    Rectangle answerButton3 = { 100, 300, 30, 30 };
    Rectangle answerButton4 = { 100, 350, 30, 30 };
    Rectangle backButton = { 10, 10, 100, 40 };

    if (CheckCollisionPointRec(GetMousePosition(), backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        returnToPreviousMenu();  // Go back to the previous menu
    }

    int textOffsetX = 40;
    int textOffsetY = 200;

    DrawText(question, 100, 150, 20, BLACK);
    DrawButton(answerButton1, "", false);
    DrawButton(answerButton2, "", false);
    DrawButton(answerButton3, "", false);
    DrawButton(answerButton4, "", false);
    DrawText(answer1, answerButton1.x + textOffsetX, textOffsetY, 20, BLACK);
    DrawText(answer2, answerButton2.x + textOffsetX, textOffsetY + 50, 20, BLACK);
    DrawText(answer3, answerButton3.x + textOffsetX, textOffsetY + 100, 20, BLACK);
    DrawText(answer4, answerButton4.x + textOffsetX, textOffsetY + 150, 20, BLACK);
    DrawButton(backButton, "Back", false);

    if (CheckCollisionPointRec(GetMousePosition(), answerButton1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isCppQuestionAnswered = true;
        isCppAnswerCorrect = false;
        printf("Answer 1 clicked! Incorrect answer.\n");
    }
    if (CheckCollisionPointRec(GetMousePosition(), answerButton2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isCppQuestionAnswered = true;
        isCppAnswerCorrect = true;
        printf("Answer 2 clicked! Correct answer.\n");
    }
    if (CheckCollisionPointRec(GetMousePosition(), answerButton3) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isCppQuestionAnswered = true;
        isCppAnswerCorrect = false;
        printf("Answer 3 clicked! Incorrect answer.\n");
    }
    if (CheckCollisionPointRec(GetMousePosition(), answerButton4) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isCppQuestionAnswered = true;
        isCppAnswerCorrect = false;
        printf("Answer 4 clicked! Incorrect answer.\n");
    }

    if (isCppQuestionAnswered) {
        if (isCppAnswerCorrect) {
            DrawText("Correct answer!", 100, 400, 20, GREEN);
        }
        else {
            DrawText("Incorrect answer! Try again.", 100, 400, 20, RED);
        }
    }
}
