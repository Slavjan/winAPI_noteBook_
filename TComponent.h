#pragma once
#include "LabHelper.h"

class TComponent {
protected:
	PairIdComponent component;
	TComponent();

public:
	virtual ~TComponent();
	int getId() const;
	HWND getHWND();

	void (*onClick)(HWND); // адрес на событие клика
};
