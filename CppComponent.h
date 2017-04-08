#pragma once
#include "LabHelper.h"

class CppComponent {
protected:
	PairIdComponent component;
	CppComponent();

public:
	virtual ~CppComponent();
	int getId() const;
	HWND getHWND();

	void (*onClick)(HWND); // адрес на событие клика
};
