#include "raylib.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Структура за бутон
struct Button {
    Rectangle bounds;
    string text;
};

// Глобални променливи
const int screenWidth = 800;
const int screenHeight = 600;
vector<Button> menuButtons;

// Декларации на функциите
void InitMenu() {
    menuButtons.push_back({ {300, 200, 200, 50}, "1. Регистрация" });
    menuButtons.push_back({ {300, 270, 200, 50}, "2. Как се играе" });
    menuButtons.push_back({ {300, 340, 200, 50}, "3. Статистики" });
    menuButtons.push_back({ {300, 410, 200, 50}, "4. Изход" });
}

void UpdateMenu() {
    Vector2 mousePoint = GetMousePosition();

    for (int i = 0; i < menuButtons.size(); i++) {
        if (CheckCollisionPointRec(mousePoint, menuButtons[i].bounds) &&
            IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            HandleMenuClick(i);
        }
    }
}

void DrawButton(Button button, bool hovered) {
    DrawRectangleRec(button.bounds, hovered ? GRAY : LIGHTGRAY);
    DrawRectangleLinesEx(button.bounds, 2, DARKGRAY);
    DrawText(button.text.c_str(), button.bounds.x + 20, button.bounds.y + 15, 20, BLACK);
}

void DrawMenu() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText("Добре дошли в E-School!", 220, 100, 30, DARKBLUE);

    Vector2 mousePoint = GetMousePosition();

    for (auto& button : menuButtons) {
        bool hovered = CheckCollisionPointRec(mousePoint, button.bounds);
        DrawButton(button, hovered);
    }

    EndDrawing();
}

void HandleMenuClick(int buttonIndex) {
    switch (buttonIndex) {
    case 0:
        cout << "🔹 Регистрация..." << endl;
        // TODO: Викай регистрационен екран
        break;
    case 1:
        cout << "🔹 Как се играе..." << endl;
        // TODO: Викай екран с инструкции
        break;
    case 2:
        cout << "🔹 Статистики..." << endl;
        // TODO: Викай екран със статистики
        break;
    case 3:
        CloseWindow();
        break;
    }
}

void CloseGame() {
    cout << "Излизане от играта. Благодарим, че използвахте E-School!" << endl;
    CloseWindow();
}


int main() {
    InitWindow(screenWidth, screenHeight, "E-School - Електронно училище");
    SetTargetFPS(60);

    InitMenu();

    while (!WindowShouldClose()) {
        UpdateMenu();
        DrawMenu();
    }

    CloseGame();
    return 0;
}
