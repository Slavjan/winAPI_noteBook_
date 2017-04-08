#include "BaseWindow.h"

BaseWindow::BaseWindow(HINSTANCE hInstance, int nCmdShow) {
	hwnd = NULL;
	if (wcl_name == NULL) {
		instance = hInstance;
		wcl_name = "SampleClass33";
		wcl.hInstance = hInstance; 
		wcl.lpszClassName = wcl_name; 
		wcl.lpfnWndProc = BaseWindow::WndProc; 
		wcl.style = CS_VREDRAW | CS_HREDRAW;
		wcl.hIcon = NULL;   
		wcl.hCursor = NULL; 
		wcl.lpszMenuName = NULL;
		wcl.cbClsExtra = NULL;
		wcl.cbWndExtra = NULL;
		wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); 
		if (!RegisterClass(&wcl)) { 
			MessageBox(NULL, "Could not register class", "Fatal error", MB_OK);
			exit(1);
		}
	}
}

BaseWindow::~BaseWindow() {
	for (auto i = this->_components[hwnd].begin(); i != _components[hwnd].end(); ++i) {
		delete (i->second);
	}
}

LRESULT BaseWindow::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) 
    {
	case WM_DESTROY: 
        PostQuitMessage( EXIT_SUCCESS ); 
    break;
	case WM_COMMAND: 
        HandleEventsOn( hWnd, wParam );
    break;
	default: return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return wParam;
}


MSG BaseWindow::ListenMessages() const {
	
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg;
}

void BaseWindow::AddComponent(std::string name, TComponent *comp) {
	_components[hwnd][name] = comp;
}

TComponent *BaseWindow::GetComponent(HWND parent, std::string name) {
	if (!_components.count(parent)) return nullptr;
	if (!_components[parent].count(name)) return nullptr;
	return _components[parent][name];
}

void BaseWindow::HandleEventsOn(HWND hwnd, WPARAM wParam) {
	
	void (*handler)(HWND);
	for (auto i = _components[hwnd].begin(); i != _components[hwnd].end(); ++i) {
		auto component = i->second;
		if (component->getId() == LOWORD(wParam)) {
			switch (HIWORD(wParam)) { 
				case BN_CLICKED: 
				case LBN_DBLCLK:  handler = component->onClick;
					break;
				default: handler = NULL;
			}
			if (handler != NULL)
				handler(hwnd);
			break;
		}
	}
}

void BaseWindow::SetEnabled(bool enabled) {
	EnableWindow(hwnd, enabled);
}

void BaseWindow::SetActive() {
	SetActiveWindow(hwnd);
}

HWND BaseWindow::getHWND() {
	return hwnd;
}

void BaseWindow::AddWindow(HWND hwnd, BaseWindow *window) {
	_windows[hwnd] = window;
}

BaseWindow *BaseWindow::GetWindow(HWND hwnd) {
	return _windows[hwnd];
}


ComponentsMap BaseWindow::_components;
std::map<HWND, BaseWindow*> BaseWindow::_windows;
WNDCLASS BaseWindow::wcl;
LPCSTR BaseWindow::wcl_name = NULL;
HINSTANCE BaseWindow::instance = NULL;
