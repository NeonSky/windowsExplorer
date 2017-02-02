#include <windows.h>
#include <iostream>
#include <time.h>

static const int cursorSpread = 50;

int main() {
  srand(time(0));

  POINT cursorPos;

  while(true) {

    GetCursorPos(&cursorPos);
    SetCursorPos(cursorPos.x + rand()%cursorSpread-cursorSpread/2,
                cursorPos.y + rand()%cursorSpread-cursorSpread/2);
    Sleep(100);

    // Quit on escape key
    if (GetAsyncKeyState(VK_ESCAPE)) {
			break;
			std::cin.ignore();
		}
  }

  return 0;
}
