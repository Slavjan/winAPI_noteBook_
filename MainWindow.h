#pragma once
#include "BaseWindow.h"

class MainWindow : public BaseWindow
{
private:
	
	void InitializeComponent() override; 

	
	static void buttonAdd_Click(HWND sender);
	static void buttonDel_Click(HWND sender);
	static void listBox1_Click(HWND sender);
	static void UpdateListBox(HWND sender);

public:
	MainWindow(HINSTANCE hInstance, int nCmdShow);
	virtual ~MainWindow();
};

namespace mainCmpNames{
    const std::string btnAdd = "BUTTONADD";
    const std::string btnDel = "BUTTONDEL";
    const std::string editTitle = "editTitle";
    const std::string listBox = "listBox";
}
