#include "MainWindow.h"

// ������� ������� ���������� (WinMain ��� �������; main ��� ����������).
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE /*hPrev*/, LPSTR lpCmdLine, int nCmdShow) {
	// ��� � �������
    MainWindow mw(hInstance, nCmdShow);
    return mw.ListenMessages().wParam;
}
