#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <ctime>

using namespace std;

bool gameOver;
const int width = 40;
const int height = 22;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
vector<pair<int, int>> snake;

void HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void ClearScreen() {
    COORD topLeft = {0, 0};
    DWORD written, cells = width * height;
    FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', cells, topLeft, &written);
    FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07, cells, topLeft, &written);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), topLeft);
}

void gotoxy(int x, int y) {
    COORD coord = {(short)x, (short)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void startScreen() {
    system("cls");
    string message = "Press ENTER to start the game";
    gotoxy((width - message.length()) / 2, height / 2);
    cout << message;
    while (_getch() != 13); // Wait for ENTER
}

void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % (width - 2) + 1;
    fruitY = rand() % (height - 2) + 1;
    score = 0;
    snake.clear();
    snake.push_back({x, y});
}

void Draw() {
    gotoxy(0, 0);
    for (int i = 0; i < width; i++) cout << "#";
    cout << endl;

    for (int i = 0; i < height - 2; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) cout << "#";
            else if (i == fruitY && j == fruitX) cout << "F";
            else {
                bool printed = false;
                for (auto s : snake) {
                    if (s.first == j && s.second == i) {
                        cout << "O";
                        printed = true;
                        break;
                    }
                }
                if (!printed) cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width; i++) cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;
}

void input() {
    if (_kbhit()) {
        int key = _getch();
        if (key == 224) { // Arrow keys
            switch (_getch()) {
                case 72: if (dir != DOWN) dir = UP; break;
                case 80: if (dir != UP) dir = DOWN; break;
                case 75: if (dir != RIGHT) dir = LEFT; break;
                case 77: if (dir != LEFT) dir = RIGHT; break;
            }
        } else {
            switch (key) {
                case 'a': case 'A': if (dir != RIGHT) dir = LEFT; break;
                case 'd': case 'D': if (dir != LEFT) dir = RIGHT; break;
                case 'w': case 'W': if (dir != DOWN) dir = UP; break;
                case 's': case 'S': if (dir != UP) dir = DOWN; break;
                case 'x': case 'X': gameOver = true; break;
            }
        }
    }
}

void Logic() {
    int prevX = snake[0].first;
    int prevY = snake[0].second;
    int newX = prevX, newY = prevY;

    switch (dir) {
        case LEFT: newX--; break;
        case RIGHT: newX++; break;
        case UP: newY--; break;
        case DOWN: newY++; break;
        default: return;
    }

    if (newX <= 0 || newX >= width - 1 || newY < 0 || newY >= height - 2) {
        gameOver = true;
        return;
    }

    for (int i = 1; i < snake.size(); i++) {
        if (snake[i].first == newX && snake[i].second == newY) {
            gameOver = true;
            return;
        }
    }

    snake.insert(snake.begin(), {newX, newY});
    if (newX == fruitX && newY == fruitY) {
        score += 10;
        fruitX = rand() % (width - 2) + 1;
        fruitY = rand() % (height - 2) + 1;
    } else {
        snake.pop_back();
    }
}

void GameOverScreen() {
    system("cls");
    string gameOverMsg = "GAME OVER";
    string scoreMsg = "Final Score: " + to_string(score);
    gotoxy((width - gameOverMsg.length()) / 2, height / 2 - 1);
    cout << gameOverMsg;
    gotoxy((width - scoreMsg.length()) / 2, height / 2 + 1);
    cout << scoreMsg;
    gotoxy((width - 26) / 2, height / 2 + 3);
    cout << "Press ENTER to exit the game";
    while (_getch() != 13); // Wait for ENTER
}

int main() {
    srand((unsigned)time(0));
    HideCursor();
    startScreen();
    Setup();

    while (!gameOver) {
        Draw();
        input();
        Logic();
        Sleep(100); // Game speed
    }

    GameOverScreen();
    return 0;
}
