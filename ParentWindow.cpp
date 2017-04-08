#include "ParentWindow.h"
#include "Edit.h"

ParentWindow::ParentWindow(HINSTANCE hInstance, int nCmdShow): BaseWindow(hInstance, nCmdShow) {
	hwnd = CreateWindow(
		wcl_name, "Note Ed",
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		0, 0, 230, 180, HWND_DESKTOP, NULL, hInstance, NULL
	);
	if (!hwnd) return;

	ParentWindow::InitializeComponent();
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
}

void ParentWindow::InitializeComponent() {
	AddComponent("editHeader", new TEdit(hwnd, 0, 0, 80, 20, NULL));
}