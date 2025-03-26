#include "../header/htmlTest.h"
#include "raylib.h"
#include <stdio.h>
#include "../header/menu.h"

bool isHtmlQuestionAnswered = false;
bool isHtmlAnswerCorrect = false;
int currentHtmlQuestionIndex = 0;

struct HtmlQuestion {
    const char* question;
    const char* answers[4];
    int correctAnswerIndex;
};

HtmlQuestion htmlQuestions[] = {
    { "What does CSS stand for?", {"Computer Style Sheets", "Creative Style Sheets", "Cascading Style Sheets", "Colorful Style Sheets"}, 2 },
    { "What is the correct HTML element for the largest heading?", {"<head>", "<h6>", "<h1>", "<header>"}, 2 },
    { "Which HTML attribute specifies an alternate text for an image?", {"alt", "title", "src", "href"}, 0 },
    { "What does HTML stand for?", {"Hyperlinks and Text Markup Language", "Home Tool Markup Language", "Hyper Text Markup Language", "High Tech Markup Language"}, 2 },
    { "Which HTML tag is used to define an internal style sheet?", {"<css>", "<style>", "<script>", "<styles>"}, 1 },
    { "Which HTML element is used to specify a footer for a document or section?", {"<bottom>", "<footer>", "<section>", "<foot>"}, 1 },
    { "Which tag is used to define a table row in HTML?", {"<td>", "<tr>", "<th>", "<table>"}, 1 },
    { "Which HTML tag is used to make text bold?", {"<strong>", "<b>", "<bold>", "<em>"}, 1 },
    { "Which of the following is an inline element in HTML?", {"<div>", "<span>", "<section>", "<article>"}, 1 },
    { "Which HTML tag is used to create a hyperlink?", {"<link>", "<a>", "<href>", "<hlink>"}, 1 },
    { "Which HTML tag is used to insert a line break?", {"<break>", "<br>", "<lb>", "<line>"}, 1 },
    { "Which tag is used to create a numbered list in HTML?", {"<ul>", "<list>", "<ol>", "<li>"}, 2 },
    { "Which tag is used to define an unordered list in HTML?", {"<ul>", "<ol>", "<li>", "<list>"}, 0 },
    { "What is the correct way to comment in HTML?", {"<!-- Comment -->", "// Comment", "/* Comment */", "# Comment"}, 0 },
    { "Which attribute is used to open a link in a new tab?", {"newtab", "_self", "_blank", "target"}, 2 },
    { "What does the <meta> tag provide in HTML?", {"Metadata", "CSS styles", "External links", "JavaScript code"}, 0 },
    { "Which of these elements is used to create a dropdown list?", {"<input>", "<dropdown>", "<select>", "<list>"}, 2 },
    { "Which tag is used to define a navigation link?", {"<nav>", "<a>", "<link>", "<navigate>"}, 0 },
    { "Which tag is used to define a division or section in HTML?", {"<div>", "<section>", "<span>", "<article>"}, 0 }
};

const int totalHtmlQuestions = sizeof(htmlQuestions) / sizeof(htmlQuestions[0]);

void InitializeHtmlQuiz() {
    isHtmlQuestionAnswered = false;
    isHtmlAnswerCorrect = false;
    currentHtmlQuestionIndex = 0;
}

void DrawHtmlQuestionScreen() {
    HtmlQuestion currentQuestion = htmlQuestions[currentHtmlQuestionIndex];

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
    if (CheckCollisionPointRec(GetMousePosition(), nextButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && currentHtmlQuestionIndex < totalHtmlQuestions - 1) {
        currentHtmlQuestionIndex++;
        isHtmlQuestionAnswered = false;
    }
    if (CheckCollisionPointRec(GetMousePosition(), prevButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && currentHtmlQuestionIndex > 0) {
        currentHtmlQuestionIndex--;
        isHtmlQuestionAnswered = false;
    }

    DrawText(currentQuestion.question, 100, 150, 20, BLACK);

    for (int i = 0; i < 4; i++) {
        DrawButton(answerButtons[i], "", false);
        DrawText(currentQuestion.answers[i], answerButtons[i].x + 40, answerButtons[i].y, 20, BLACK);

        if (CheckCollisionPointRec(GetMousePosition(), answerButtons[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            isHtmlQuestionAnswered = true;
            isHtmlAnswerCorrect = (i == currentQuestion.correctAnswerIndex);
            printf("Answer %d clicked! %s answer.\n", i + 1, isHtmlAnswerCorrect ? "Correct" : "Incorrect");
        }
    }

    DrawButton(backButton, "Back", false);
    DrawButton(nextButton, "Next", false);
    DrawButton(prevButton, "Previous", false);

    if (isHtmlQuestionAnswered) {
        DrawText(isHtmlAnswerCorrect ? "Correct answer!" : "Incorrect answer! Try again.", 100, 400, 20, isHtmlAnswerCorrect ? GREEN : RED);
    }
}