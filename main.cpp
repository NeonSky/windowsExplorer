#include <windows.h>
#include <iostream>
#include <time.h>

static const int cursorSpread = 500;


void moveCursor() {
  POINT cursorPos;
  GetCursorPos(&cursorPos);
  SetCursorPos(cursorPos.x + rand()%cursorSpread-cursorSpread/2,
              cursorPos.y + rand()%cursorSpread-cursorSpread/2);
}

bool isBreakKeyPressed() {
  if(GetAsyncKeyState(VK_ESCAPE)) { return true; }
  return false;
}

void update() {

  moveCursor();
  Sleep(10);

  // Quit on escape key
  if(isBreakKeyPressed()) {
    break;
    std::cin.ignore();
  }

}

int main() {
  srand(time(0));

  while(true) {
    update();
  }

  return 0;
}
