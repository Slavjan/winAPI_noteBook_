#include "CppComponent.h"

CppComponent::CppComponent()
{
    component = NULL;
    onClick = NULL;
}

CppComponent::~CppComponent()
{
}

int CppComponent::getId() const
{
    return component.id;
}
HWND CppComponent::getHWND()
{
    return component.component;
}
