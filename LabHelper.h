#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string>

// из лекций:
// "Как связать HWND и id? Нужна структура, которая будет содержать в себе эти две переменных"
struct PairIdComponent {
	PairIdComponent() {
		component = NULL;
		id = count++;
	}
	PairIdComponent(HWND hwnd) {
		component = hwnd;
		id = count++;
	}
	int id;
	HWND component;
private:
	static int count;
};

/*struct comparer {
public:
    bool operator()(const std::string x, const std::string y) {
         return x.compare(y) < 0;
    }
};*/

// буфер для всех строковых операций
#define BUFSIZE 128
extern char buf[], buf2[], filename[];
