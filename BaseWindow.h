#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "CppComponent.h"
#include <map>

typedef std::map<HWND, std::map<std::string, CppComponent*>> ComponentsMap;

class BaseWindow { 
protected:
	HWND hwnd; 
	virtual void InitializeComponent() = NULL; 
	static WNDCLASS wcl;
	static LPCSTR wcl_name;
	static HINSTANCE instance;
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 
	static void HandleEventsOn(HWND hwnd, WPARAM wParam); 

	
	static ComponentsMap _components;
	static CppComponent *GetComponent(HWND parent, std::string name);
	static std::map<HWND, BaseWindow*> _windows;

public:
	
	BaseWindow(HINSTANCE hInstance, int nCmdShow);
	virtual ~BaseWindow();
	MSG ListenMessages() const;
	void AddComponent(std::string name, CppComponent *comp);
	void SetEnabled(bool enabled);
	void SetActive();
	HWND getHWND();
	static void AddWindow(HWND hwnd, BaseWindow *window);
	static BaseWindow *GetWindow(HWND hwnd);
};
