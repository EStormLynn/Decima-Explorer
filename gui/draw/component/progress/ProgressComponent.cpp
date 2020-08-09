#include "ProgressComponent.h"

ProgressComponent::ProgressComponent() {

}

ProgressComponent::~ProgressComponent() {

}

void ProgressComponent::create(HWND parent, Dimensions dimensions, Origin origin) {
    DWORD style = WS_CHILD | WS_VISIBLE;
    HWND hwnd = CreateWindow(PROGRESS_CLASS, "Loading file", style, origin.x, origin.y, dimensions.width, dimensions.height, parent, NULL, NULL, this);
    setHandle(hwnd);
}

void ProgressComponent::setRange(int32_t maxRange) {
    SendMessage(getHandle(), PBM_SETRANGE32, 0, maxRange);
}

void ProgressComponent::setIncrement() {
    SendMessage(getHandle(), PBM_SETSTEP, (WPARAM)1, 0);
}

void ProgressComponent::increment() {
    SendMessage(getHandle(), PBM_STEPIT, 0, 0);
}
