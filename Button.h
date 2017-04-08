#pragma once
#include "CppComponent.h"

class CppButton : public CppComponent {
public:
	CppButton(HWND hWnd, int left, int top, int width, int height, char *text, void (*OnClickCallback)(HWND));
};
