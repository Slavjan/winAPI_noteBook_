#pragma once
#include "TComponent.h"

class TEdit : public TComponent {
public:
	TEdit(HWND hwnd, int left, int top, int width, int height, void (*OnClickCallback)(HWND));
};
