#include "../header/htmlTest.h"
#include "raylib.h"
#include <stdio.h>
#include "../header/menu.h"

bool isHtmlQuestionAnswered = false;
bool isHtmlAnswerCorrect = false;

void InitializeHtmlQuiz() {
    isHtmlQuestionAnswered = false;
    isHtmlAnswerCorrect = false;
}

void DrawHtmlQuestionScreen() {
    const char* question = "What does CSS stand for?";
    const char* answer1 = "Computer Style Sheets";  // Incorrect
    const char* answer2 = "Creative Style Sheets";  // Incorrect
    const char* answer3 = "Cascading Style Sheets";  // Correct
    const char* answer4 = "Colorful Style Sheets";  // Incorrect

    Rectangle answerButton1 = { 100, 200, 30, 30 };
    Rectangle answerButton2 = { 100, 250, 30, 30 };
    Rectangle answerButton3 = { 100, 300, 30, 30 };
    Rectangle answerButton4 = { 100, 350, 30, 30 };
    Rectangle backButton = { 10, 10, 100, 40 };

    if (CheckCollisionPointRec(GetMousePosition(), backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        returnToPreviousMenu();
    }

    DrawText(question, 100, 150, 20, BLACK);

    DrawButton(answerButton1, "", false);
    DrawButton(answerButton2, "", false);
    DrawButton(answerButton3, "", false);
    DrawButton(answerButton4, "", false);
    DrawButton(backButton, "Back", false);

    DrawText(answer1, answerButton1.x + 40, 200, 20, BLACK);
    DrawText(answer2, answerButton2.x + 40, 250, 20, BLACK);
    DrawText(answer3, answerButton3.x + 40, 300, 20, BLACK);
    DrawText(answer4, answerButton4.x + 40, 350, 20, BLACK);

    if (CheckCollisionPointRec(GetMousePosition(), answerButton1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isHtmlQuestionAnswered = true;
        isHtmlAnswerCorrect = false;
    }
    if (CheckCollisionPointRec(GetMousePosition(), answerButton2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isHtmlQuestionAnswered = true;
        isHtmlAnswerCorrect = false;
    }
    if (CheckCollisionPointRec(GetMousePosition(), answerButton3) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isHtmlQuestionAnswered = true;
        isHtmlAnswerCorrect = true;
    }
    if (CheckCollisionPointRec(GetMousePosition(), answerButton4) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isHtmlQuestionAnswered = true;
        isHtmlAnswerCorrect = false;
    }

    if (isHtmlQuestionAnswered) {
        if (isHtmlAnswerCorrect) {
            DrawText("Correct answer!", 100, 400, 20, GREEN);
        }
        else {
            DrawText("Incorrect answer! Try again.", 100, 400, 20, RED);
        }
    }
}