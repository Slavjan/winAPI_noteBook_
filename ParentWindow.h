#include "LabHelper.h"
#include "BaseWindow.h"

class ParentWindow : public BaseWindow {
private:
	// ����
	void InitializeComponent() override; // �������� ���������� ����������� (������ � �.�.)

public:
	ParentWindow(HINSTANCE hInstance, int nCmdShow);
	virtual ~ParentWindow() {}
};
