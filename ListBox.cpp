#include "ListBox.h"

TListBox::TListBox(HWND hwnd, int left, int top, int width, int height, void(*OnClickCallback)(HWND)) {
	component.component = CreateWindow(
		"LISTBOX", // имя класса (он уже зарегистрирован и настроен)
		NULL, // текст
		(WS_CHILD | WS_VISIBLE | LBS_STANDARD) ^ LBS_SORT, // стили, ВЫКЛЮЧИТЬ СОРТИРОВКУ
		left, top, width, height, // координаты и размер
		hwnd, // хэндл окна
		(HMENU)component.id, //id элемента
		(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), // hInstance
		NULL // последний параметр нам не нужен
	);
	onClick = OnClickCallback;
}
