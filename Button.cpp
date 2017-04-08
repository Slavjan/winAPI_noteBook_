#include "Button.h"
#include "TComponent.h"

TButton::TButton(HWND hWnd, int left, int top, int width, int height, char *text, void (*OnClickCallback)(HWND)) {
	component.component = CreateWindow(
		"BUTTON", // ��� ������ (�� ��� ��������������� � ��������)
		text, // �����
		WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // �����
		left, top, width, height, // ���������� � ������
		hWnd, // ����� ����
		(HMENU)component.id, //id ��������
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), // hInstance
		NULL // ��������� �������� ��� �� �����
	);
	onClick = OnClickCallback;
}
