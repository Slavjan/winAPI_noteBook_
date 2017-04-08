#include "Button.h"
#include "TComponent.h"

TButton::TButton(HWND hWnd, int left, int top, int width, int height, char *text, void (*OnClickCallback)(HWND)) {
	component.component = CreateWindow(
		"BUTTON", // имя класса (он уже зарегистрирован и настроен)
		text, // текст
		WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // стили
		left, top, width, height, // координаты и размер
		hWnd, // хэндл окна
		(HMENU)component.id, //id элемента
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), // hInstance
		NULL // последний параметр нам не нужен
	);
	onClick = OnClickCallback;
}
