#include "MainWindow.h"

// Главная функция приложения (WinMain для оконных; main для консольных).
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE /*hPrev*/, LPSTR lpCmdLine, int nCmdShow) {
	// как в лекциях
    MainWindow mw(hInstance, nCmdShow);
    return mw.ListenMessages().wParam;
}
