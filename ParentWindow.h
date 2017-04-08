#include "LabHelper.h"
#include "BaseWindow.h"

class ParentWindow : public BaseWindow {
private:
	// окно
	void InitializeComponent() override; // создание визуальных компонентов (кнопок и т.д.)

public:
	ParentWindow(HINSTANCE hInstance, int nCmdShow);
	virtual ~ParentWindow() {}
};
