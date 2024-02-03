#include "CppProject.h"

Color color = Color(24, 2434, 65);
#include <Windows.h>
#include <WinUser.h>

//#include <SFML/Graphics.hpp>

int n = 0;

int main() {
	while (Update()) {
		//anus gay
		print(Project::MaxFPS);
		if (Input::GetKey('f')) { Project::MaxFPS++; }
		if (Input::GetKey('x')) { Project::MaxFPS--; }
	}
}