#pragma once
#include "TComponent.h"

class TListBox : public TComponent {
public:
	TListBox(HWND hwnd, int left, int top, int width, int height, void (*OnClickCallback)(HWND));
};
