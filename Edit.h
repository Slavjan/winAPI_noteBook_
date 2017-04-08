#pragma once
#include "CppComponent.h"

class CppEdit : public CppComponent {
public:
	CppEdit(HWND hwnd, int left, int top, int width, int height, void (*OnClickCallback)(HWND));
};
