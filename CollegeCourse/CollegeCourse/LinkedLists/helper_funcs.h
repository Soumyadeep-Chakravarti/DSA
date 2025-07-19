#include <stdlib.h>

void clear_screen() {
    #ifdef _WIN32
        system("cls");    // Windows
    #else
        system("clear");  // Unix/Linux/macOS
    #endif
}