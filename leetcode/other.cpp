// alt_tab_single.cpp
#include <windows.h>
#include <iostream>

void AltTabOnce()
{
    // Prepare two INPUTs for Alt down + Tab down/up; then Alt up
    INPUT inputs[4] = {};

    // Alt down
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_MENU; // Alt
    inputs[0].ki.dwFlags = 0;

    // Tab down
    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = VK_TAB;
    inputs[1].ki.dwFlags = 0;

    // Tab up
    inputs[2].type = INPUT_KEYBOARD;
    inputs[2].ki.wVk = VK_TAB;
    inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

    // Alt up
    inputs[3].type = INPUT_KEYBOARD;
    inputs[3].ki.wVk = VK_MENU;
    inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

    // Send the sequence
    UINT sent = SendInput(4, inputs, sizeof(INPUT));
    if (sent != 4) {
        std::cerr << "SendInput sent " << sent << " events\n";
    }
}

int main()
{
    std::cout << "Switching to next window (Alt+Tab)...\n";
    Sleep(300); // small delay so you can focus the current window if needed
    AltTabOnce();
    Sleep(300); // small delay so you can focus the current window if needed
    AltTabOnce();
    return 0;
}
