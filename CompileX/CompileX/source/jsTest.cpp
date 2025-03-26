#include "../header/jstest.h"
#include "raylib.h"
#include <stdio.h>
#include "../header/menu.h"
#include "../header/planet.h"

bool isJsQuestionAnswered = false;
bool isJsAnswerCorrect = false;
int currentJsQuestionIndex = 0;

struct JsQuestion {
    const char* question;
    const char* answers[4];
    int correctAnswerIndex;
};

JsQuestion jsQuestions[] = {
    { "What is the output of console.log(2 + '2')?", {"4", "'22'", "undefined", "Error"}, 1 },
    { "Which keyword is used to declare a variable in JavaScript?", {"var", "let", "const", "All of the above"}, 3 },
    { "Which symbol is used for single-line comments in JavaScript?", {"//", "<!-- -->", "/* */", "--"}, 0 },
    { "Which function is used to print something to the console?", {"print()", "console.print()", "log()", "console.log()"}, 3 },
    { "Which operator is used for strict equality in JavaScript?", {"==", "===", "!=", "!=="}, 1 },
    { "What is the result of typeof null in JavaScript?", {"'null'", "'undefined'", "'object'", "'number'"}, 2 },
    { "Which method converts a string to an integer?", {"parseInt()", "parseFloat()", "Number()", "toInt()"}, 0 },
    { "How do you declare a function in JavaScript?", {"function myFunc() {}", "def myFunc() {}", "func myFunc() {}", "define myFunc() {}"}, 0 },
    { "Which keyword is used to return a value from a function?", {"return", "break", "continue", "exit"}, 0 },
    { "Which method removes the last element from an array?", {"pop()", "shift()", "splice()", "remove()"}, 0 },
    { "What will '5' + 3 evaluate to in JavaScript?", {"8", "'53'", "Error", "'5 + 3'"}, 1 },
    { "What does NaN stand for in JavaScript?", {"Not a Name", "Not a Number", "Negative and Null", "None"}, 1 },
    { "Which method adds a new element to the end of an array?", {"push()", "add()", "append()", "concat()"}, 0 },
    { "Which function is used to execute a function after a specified time?", {"setTimeout()", "setInterval()", "delay()", "wait()"}, 0 },
    { "How do you check if a variable is an array?", {"typeof var === 'array'", "isArray(var)", "Array.isArray(var)", "var instanceof Array"}, 2 },
    { "Which loop is used to iterate over an object's properties?", {"for", "forEach", "for in", "for of"}, 2 },
    { "Which event is triggered when a user clicks an HTML element?", {"onhover", "onmouseover", "onclick", "onpress"}, 2 },
    { "What is the purpose of JSON in JavaScript?", {"Storing and transporting data", "Styling web pages", "Interacting with databases", "Creating animations"}, 0 },
    { "Which JavaScript framework is developed by Facebook?", {"Angular", "Vue", "React", "Svelte"}, 2 }
};

const int totalJsQuestions = sizeof(jsQuestions) / sizeof(jsQuestions[0]);

void InitializeJSQuiz() {
    isJsQuestionAnswered = false;
    isJsAnswerCorrect = false;
    currentJsQuestionIndex = 0;
}

void DrawJSQuestionScreen() {
    JsQuestion currentQuestion = jsQuestions[currentJsQuestionIndex];

    Rectangle answerButtons[4] = {
        {100, 200, 30, 30},
        {100, 250, 30, 30},
        {100, 300, 30, 30},
        {100, 350, 30, 30}
    };
    Rectangle backButton = { 10, 10, 100, 40 };
    Rectangle nextButton = { 250, 450, 100, 40 };
    Rectangle prevButton = { 100, 450, 100, 40 };

    if (CheckCollisionPointRec(GetMousePosition(), backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        returnToPreviousMenu();
    }
    if (CheckCollisionPointRec(GetMousePosition(), nextButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && currentJsQuestionIndex < totalJsQuestions - 1) {
        currentJsQuestionIndex++;
        isJsQuestionAnswered = false;
    }
    if (CheckCollisionPointRec(GetMousePosition(), prevButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && currentJsQuestionIndex > 0) {
        currentJsQuestionIndex--;
        isJsQuestionAnswered = false;
    }

    DrawText(currentQuestion.question, 100, 150, 20, BLACK);

    for (int i = 0; i < 4; i++) {
        DrawButton(answerButtons[i], "", false);
        DrawText(currentQuestion.answers[i], answerButtons[i].x + 40, answerButtons[i].y, 20, BLACK);

        if (CheckCollisionPointRec(GetMousePosition(), answerButtons[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            isJsQuestionAnswered = true;
            isJsAnswerCorrect = (i == currentQuestion.correctAnswerIndex);
            printf("Answer %d clicked! %s answer.\n", i + 1, isJsAnswerCorrect ? "Correct" : "Incorrect");
        }
    }

    DrawButton(backButton, "Back", false);
    DrawButton(nextButton, "Next", false);
    DrawButton(prevButton, "Previous", false);

    if (isJsQuestionAnswered) {
        DrawText(isJsAnswerCorrect ? "Correct answer!" : "Incorrect answer! Try again.", 100, 400, 20, isJsAnswerCorrect ? GREEN : RED);
    }
}