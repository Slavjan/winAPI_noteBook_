#include "TComponent.h"

TComponent::TComponent() {
	component = NULL;
	onClick = NULL;
}

TComponent::~TComponent() {
	
}

int TComponent::getId() const { return component.id; }
HWND TComponent::getHWND() { return component.component; }
