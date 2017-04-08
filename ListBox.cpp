#include "ListBox.h"

TListBox::TListBox(HWND hwnd, int left, int top, int width, int height, void(*OnClickCallback)(HWND)) {
	component.component = CreateWindow(
		"LISTBOX", // ��� ������ (�� ��� ��������������� � ��������)
		NULL, // �����
		(WS_CHILD | WS_VISIBLE | LBS_STANDARD) ^ LBS_SORT, // �����, ��������� ����������
		left, top, width, height, // ���������� � ������
		hwnd, // ����� ����
		(HMENU)component.id, //id ��������
		(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), // hInstance
		NULL // ��������� �������� ��� �� �����
	);
	onClick = OnClickCallback;
}
