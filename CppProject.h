//
#pragma once

//
#include <iostream>
#include "math.h"
#include <conio.h>
#include <string>

namespace Project {
	static string pizda;
	static string huy;
	static string zaluoda;
	static string chlen;
}

template <class printClass>
void print(printClass value) {
	std::cout << value << std::endl;
};

// =============== MODULS
#pragma region MODULS
// TIME
namespace Time {
	//
	static int last_delta_time = 0;

	// Time point
	class TimePoint {
	private:
		double ticks = 0;

	public:
		// Initializition
		TimePoint() {
			Reset();
		}

		// Get Ticks
		double Ticks() {
			return ticks;
		}

		// Reset
		void Reset() {
			ticks = clock();
		}

		// DeltaTime(bool reset - return and reset ticks)
		double DeltaTime(bool reset = false) {
			// Save delta
			double delta = clock() - ticks;

			// Reset
			if (reset) {
				Reset();
			}

			// Return
			return delta;
		}

		// Timer(float currentTime - time for timer, bool reset - return and reset ticks)
		bool Timer(float currentTime, bool reset = false) {
			// Save delta
			double delta = DeltaTime();

			// Reset
			if (reset && delta > currentTime) {
				Reset();
			}

			// Return
			return delta > currentTime;
		}
	};

	// Main time functions
	int Time() {
		return clock();
	}

	float DeltaTime() {
		return (Time() - last_delta_time);
	}

	int Wait(int time) {
		TimePoint timePoint = TimePoint();

		while (true)
		{
			if (timePoint.Timer(time)) {
				return 1;
			}
		}
	}

	// Addition time functions
	void ReloadDeltaTime() {
		last_delta_time = Time();
	}
};

// INPUT
namespace Input {
	//
	bool GetKey(char Key) {
		if (_kbhit()) {
			return (_getch() == Key);
		}
		return false;
	}

	//
	bool GetCode(int Key) {
		if (_kbhit()) {
			return (_getch() == Key);
		}
		return false;
	}
}

// MATH
namespace Math {
	// attributes
	const double pi = 3.141592;

	// Main values operators
	float Absolute(float a) {
		if (a < 0) { a = -a; }
		return a;
	};
	float Clamp(float value, float min, float max) {
		if (value < min) { value = min; }
		if (value > max) { value = max; }
		return value;
	};

	// Addition values operators
	float Degree(float a, float b = 2) {
		return pow(a, b);
	};
	float Root(float a, float b = 2) {
		return Degree(a, 1 / b);
	};

	// Angles
		// Converting | direction - angle
	/*
	float DirectionToAngle(Vector2 dir) {
		float angle = arccos(dir.y);

		if (dir.x > 0 && dir.y < 0) { angle += 270; }
		if (dir.x < 0 && dir.y > 0) { angle += 90; }
		if (dir.x < 0 && dir.y < 0) { angle += 180; }

		return angle;
	};*/

	// Converting
	float DegreesToRadians(float Degrees) {
		return Degrees * 0.01745;
	};
	float RadiansToDegrees(float Radians) {
		return Radians / 0.01745;
	};
	// Cos | Sin | Tan
	float cosRadians(float angle) {
		return std::cos(angle);
	};
	float cos(float angle) {
		return std::cos(DegreesToRadians(angle));
	};
	float sinRadians(float angle) {
		return std::sin(angle);
	};
	float sin(float angle) {
		return std::sin(DegreesToRadians(angle));
	};
	// Arc cos | Arc sin | Arctan
	float arccos(float cos) {
		return RadiansToDegrees(acos(cos));
	}
	float arccosRadians(float cos) {
		return acos(cos);
	}
	float arcsin(float sin) {
		return RadiansToDegrees(asin(sin));
	}
	float arcsinRadians(float sin) {
		return asin(sin);
	}
}

// RANDOM
namespace Random {
	//
	int Range(int min, int max) {
		return rand() % (max - min) + min;
	}

	bool Chance(double chance) {
		return (Range(0, 10000000) + 1) / 100000.0 < chance;
	}
}

#pragma endregion

// =============== ADDITION CLASSES
#pragma region ADDITION CLASSES
// VECTOR 2
class Vector2 {
public:
	// Attributes
	float x = 0;
	float y = 0;

	// initialization
	Vector2(float x, float y) {
		this->x = x;
		this->y = y;
	};

	// Operations
#pragma region Operation region
	// print
	friend std::ostream& operator<<(std::ostream& os, const Vector2& self) {
		return os << '(' << self.x << ',' << self.y << ')';
	};
	// Plus
	friend Vector2 operator+(const Vector2& v1, const Vector2& v2) {
		return Vector2(v1.x + v2.x, v1.y + v2.y);
	};
	friend Vector2 operator+(const Vector2& v, const float value) {
		return Vector2(v.x + value, v.y + value);
	};
	// Minus
	friend Vector2 operator-(const Vector2& v1, const Vector2& v2) {
		return Vector2(v1.x - v2.x, v1.y - v2.y);
	};
	friend Vector2 operator-(const Vector2& v, const float value) {
		return Vector2(v.x - value, v.y - value);
	};
	// Multiplication
	friend Vector2 operator*(const Vector2& v1, const Vector2& v2) {
		return Vector2(v1.x * v2.x, v1.y * v2.y);
	};
	friend Vector2 operator*(const Vector2& v, const float value) {
		return Vector2(v.x * value, v.y * value);
	};
	// Division
	friend Vector2 operator/(const Vector2& v1, const Vector2& v2) {
		return Vector2(v1.x / v2.x, v1.y / v2.y);
	};
	friend Vector2 operator/(const Vector2& v, const float value) {
		return Vector2(v.x / value, v.y / value);
	};
#pragma endregion

	// Static Values
#pragma region Static values region
	static Vector2 Up() { return Vector2(0, 1); }
	static Vector2 Down() { return Vector2(0, -1); }
	static Vector2 Right() { return Vector2(1, 0); }
	static Vector2 Left() { return Vector2(-1, 0); }
#pragma endregion

	// Other functions
	static float Distance(Vector2& v1, Vector2& v2) {
		return Math::Root(Math::Degree(v1.x - v2.x) + Math::Degree(v1.y - v2.y));
	};
};

// COLOR
class Color {
public:
	// Attributes
	float red = 0;
	float green = 0;
	float blue = 0;

	// initialization
	Color(float red, float green, float blue) {
		this->red = Math::Clamp(red, 0, 256);
		this->green = Math::Clamp(green, 0, 256);
		this->blue = Math::Clamp(blue, 0, 256);
	};

	// Operations
#pragma region Operation region
	// print
	friend std::ostream& operator<<(std::ostream& os, const Color& self) {
		return os << '(' << self.red << ',' << self.green << ',' << self.blue << ')';
	};
#pragma endregion

	// Static Values
#pragma region Static values region
	static Color White() { return Color(256, 256, 256); }
	static Color Black() { return Color(0, 0, 0); }

	static Color Red() { return Color(256, 0, 0); }
	static Color Green() { return Color(0, 256, 0); }
	static Color Blue() { return Color(0, 0, 256); }
#pragma endregion
};

#pragma endregion

int maxFPS = 69;
static bool Update() {
	//
	Time::Wait((1000 / maxFPS) - Time::DeltaTime());
	Time::ReloadDeltaTime();

	if (Input::GetKey('q')) { return false; }
	return true;
}