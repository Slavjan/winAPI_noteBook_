#pragma once
#include "LabHelper.h"
#include "BaseWindow.h"

class ChildWindow : public BaseWindow
{
private:
	void InitializeComponent() override; 
	HWND _parent;
	int  _noteId;

public:
	ChildWindow(HINSTANCE hInstance, HWND parent, int nCmdShow, int extra = NULL);
	virtual ~ChildWindow();
	int GetExtra();
	static void ButtonSaveClick(HWND sender);
};

namespace childCmpNames{
    const std::string btnSave = "BUTTONSAVE";
    const std::string editTitle = "editTitle";
    const std::string editText = "editText";
}