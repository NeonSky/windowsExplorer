#include <windows.h>
#include <iostream>
#include <time.h>

#define isDebugging true

static const int cursorSpread = 10;
bool isRunning = true;

POINT moveCursor() {
  POINT cursorPos;
  GetCursorPos(&cursorPos);
  SetCursorPos(cursorPos.x + rand()%cursorSpread-cursorSpread/2,
              cursorPos.y + rand()%cursorSpread-cursorSpread/2);
  return cursorPos;
}

void leftClick() {
  INPUT Input={0};
  Input.type = INPUT_MOUSE;
  Input.mi.dwFlags =  MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;

  SendInput(1, &Input, sizeof(INPUT));
}

void rightClick() {
  INPUT Input={0};
  Input.type = INPUT_MOUSE;
  Input.mi.dwFlags =  MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP;

  SendInput(1, &Input, sizeof(INPUT));
}

bool isBreakKeyPressed() {
  if(GetAsyncKeyState(VK_ESCAPE)) { return true; }
  return false;
}

void update() {

  moveCursor();
  rightClick();
  leftClick();
  Sleep(10);

  // Quit on escape key
  #ifdef isDebugging
    if(isBreakKeyPressed()) {
      isRunning = false;
      std::cin.ignore();
    }
  #endif
}

int main() {
  srand(time(0));

  while(isRunning) {
    update();
  }

  return 0;
}
