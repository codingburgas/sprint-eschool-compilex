#include "../header/menu.h"
#include "../header/main.h"


using namespace std;

// ????????? ?? ?????
struct Button {
    Rectangle bounds;
    string text;
};

// ???????? ??????????
const int screenWidth = 800;
const int screenHeight = 600;
vector<Button> menuButtons;

void InitMenu() {
    menuButtons.push_back({ {300, 200, 200, 50}, "1. ???????????" });
    menuButtons.push_back({ {300, 270, 200, 50}, "2. ??? ?? ?????" });
    menuButtons.push_back({ {300, 340, 200, 50}, "3. ??????????" });
    menuButtons.push_back({ {300, 410, 200, 50}, "4. ?????" });
}

void HandleMenuClick(int buttonIndex) {
    switch (buttonIndex) {
    case 0:
        cout << "?? ???????????..." << endl;
        break;
    case 1:
        cout << "?? ??? ?? ?????..." << endl;
        break;
    case 2:
        cout << "?? ??????????..." << endl;
        break;
    case 3:
        CloseWindow();
        break;
    }
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

    DrawText("\u0414\u043e\u0431\u0440\u0435 \u0434\u043e\u0448\u043b\u0438 \u0432 E-School!", 220, 100, 30, DARKBLUE);

    Vector2 mousePoint = GetMousePosition();
    for (auto& button : menuButtons) {
        bool hovered = CheckCollisionPointRec(mousePoint, button.bounds);
        DrawButton(button, hovered);
    }

    EndDrawing();
}

void Menu() {
    InitWindow(screenWidth, screenHeight, "E-School - \u0415\u043b\u0435\u043a\u0442\u0440\u043e\u043d\u043d\u043e \u0443\u0447\u0438\u043b\u0438\u0449\u0435");
    SetTargetFPS(60);

    InitMenu();

    while (!WindowShouldClose()) {
        UpdateMenu();
        DrawMenu();
    }

    CloseWindow();
}


