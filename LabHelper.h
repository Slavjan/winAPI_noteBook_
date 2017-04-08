#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string>

// �� ������:
// "��� ������� HWND � id? ����� ���������, ������� ����� ��������� � ���� ��� ��� ����������"
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

// ����� ��� ���� ��������� ��������
#define BUFSIZE 128
extern char buf[], buf2[], filename[];
