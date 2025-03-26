#include "../header/cpptest.h"
#include "raylib.h"
#include <stdio.h>
#include "../header/menu.h"
#include "../header/planet.h"

bool isCppQuestionAnswered = false;
bool isCppAnswerCorrect = false;
int currentQuestionIndex = 0;

struct Question {
    const char* question;
    const char* answers[4];
    int correctAnswerIndex;
};

Question cppQuestions[] = {
    { "What will be the output of the following C++ code: cout << 2 + '2';",
      {"4", "50", "Error", "undefined"}, 1 },
    { "Which keyword is used to define a constant variable in C++?",
      {"const", "static", "define", "final"}, 0 },
    { "What is the size of an int in most 64-bit systems?",
      {"2 bytes", "4 bytes", "8 bytes", "Depends on compiler"}, 1 },
    { "Which of the following is NOT a valid loop construct in C++?",
      {"for", "foreach", "while", "do-while"}, 1 },
    { "What is the default access specifier for class members in C++?",
      {"public", "private", "protected", "none"}, 1 },
    { "Which operator is used to allocate memory dynamically in C++?",
      {"malloc", "alloc", "new", "calloc"}, 2 },
    { "Which function is used to deallocate memory allocated by new?",
      {"delete", "free", "remove", "release"}, 0 },
    { "Which of the following is NOT a valid C++ data type?",
      {"int", "double", "float32", "char"}, 2 },
    { "What is the output of: cout << (5 & 3);?",
      {"1", "2", "3", "5"}, 1 },
    { "What is a destructor in C++?",
      {"A function called when an object is deleted", "A function that initializes an object", "A function that copies an object", "None of the above"}, 0 },
    { "Which of the following is not a valid access specifier in C++?",
      {"public", "internal", "private", "protected"}, 1 },
    { "What does the keyword 'virtual' signify in C++?",
      {"A function can be overridden in derived classes", "A function cannot be inherited", "A function is executed immediately", "None of the above"}, 0 },
    { "Which of the following is used to define a template in C++?",
      {"template", "define", "typename", "class"}, 0 },
    { "Which header file is required for using std::vector in C++?",
      {"<vector>", "<array>", "<list>", "<map>"}, 0 },
    { "What will be the output of: cout << sizeof(char);?",
      {"1", "2", "4", "8"}, 0 },
    { "Which function is used to read a line of text in C++?",
      {"scanf", "getline", "readline", "gets"}, 1 },
    { "What is function overloading in C++?",
      {"Using multiple functions with the same name but different parameters", "Using a function inside another function", "Using a function with different return types", "None of the above"}, 0 },
    { "Which keyword is used to prevent a variable from being modified in C++?",
      {"const", "volatile", "immutable", "static"}, 0 },
    { "Which C++ feature allows defining multiple functions with the same name but different parameters?",
      {"Function Overriding", "Function Overloading", "Operator Overloading", "Lambda Functions"}, 1 }
};

const int totalQuestions = sizeof(cppQuestions) / sizeof(cppQuestions[0]);

void InitializeCppQuiz() {
    isCppQuestionAnswered = false;
    isCppAnswerCorrect = false;
    currentQuestionIndex = 0;
}

void DrawCppQuestionScreen() {
    Question currentQuestion = cppQuestions[currentQuestionIndex];

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
    if (CheckCollisionPointRec(GetMousePosition(), nextButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && currentQuestionIndex < totalQuestions - 1) {
        currentQuestionIndex++;
        isCppQuestionAnswered = false;
    }
    if (CheckCollisionPointRec(GetMousePosition(), prevButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && currentQuestionIndex > 0) {
        currentQuestionIndex--;
        isCppQuestionAnswered = false;
    }

    DrawText(currentQuestion.question, 100, 150, 20, BLACK);

    for (int i = 0; i < 4; i++) {
        DrawButton(answerButtons[i], "", false);
        DrawText(currentQuestion.answers[i], answerButtons[i].x + 40, answerButtons[i].y, 20, BLACK);

        if (CheckCollisionPointRec(GetMousePosition(), answerButtons[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            isCppQuestionAnswered = true;
            isCppAnswerCorrect = (i == currentQuestion.correctAnswerIndex);
            printf("Answer %d clicked! %s answer.\n", i + 1, isCppAnswerCorrect ? "Correct" : "Incorrect");
        }
    }

    DrawButton(backButton, "Back", false);
    DrawButton(nextButton, "Next", false);
    DrawButton(prevButton, "Previous", false);

    if (isCppQuestionAnswered) {
        DrawText(isCppAnswerCorrect ? "Correct answer!" : "Incorrect answer! Try again.", 100, 400, 20, isCppAnswerCorrect ? GREEN : RED);
    }
}