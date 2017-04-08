#pragma once
#include "CppComponent.h"

class TListBox : public CppComponent {
public:
	TListBox(HWND hwnd, int left, int top, int width, int height, void (*OnClickCallback)(HWND));
};
