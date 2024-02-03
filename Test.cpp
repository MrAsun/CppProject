#include "CppProject.h"


Color color = Color(24, 2434, 65);
#include <Windows.h>
#include <WinUser.h>


//#include <SFML/Graphics.hpp>

int n = 0;

int main() {
	for (int i = 0; i < 100; i++) {
		HDC hdc = GetDC(NULL);
		MoveToEx(hdc, 0, 0, NULL);
		LineTo(hdc, 1000, 1000);
		ReleaseDC(NULL, hdc);
		Sleep(100);
	}
	while (Update()) {
		Time::Wait(100);
		n++;
		print(Math::sin(n));
	}
}