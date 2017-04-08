#include "Edit.h"

CppEdit::CppEdit(HWND hwnd, int left, int top, int width, int height, void(*OnClickCallback)(HWND)) {
	component.component = CreateWindow(
		"EDIT",
		NULL,
		WS_BORDER | WS_VISIBLE | WS_CHILD | ES_LEFT | ES_MULTILINE,
		left, top, width, height,
		hwnd,
		(HMENU)component.id,
		NULL,
		NULL
	);
	onClick = OnClickCallback;
}
