#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    MessageBoxW(NULL, L"Hello from SD Card!", L"Test App", MB_OK);
    return 0;
}
