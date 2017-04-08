#pragma once
#include "TComponent.h"

class TButton : public TComponent {
public:
	TButton(HWND hWnd, int left, int top, int width, int height, char *text, void (*OnClickCallback)(HWND));
};
