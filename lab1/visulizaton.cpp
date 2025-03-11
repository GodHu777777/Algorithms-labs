#include <iostream>
#include <fstream>
#include <string>
#include "macro.h"

// ANSI escape sequences (colors) - These are still defined for potential console output
#define BG_COLOR_BLACK   "\033[40m"
#define BG_COLOR_RED     "\033[41m"
#define BG_COLOR_GREEN   "\033[42m"
#define BG_COLOR_YELLOW  "\033[43m"
#define BG_COLOR_BLUE    "\033[44m"
#define BG_COLOR_MAGENTA "\033[45m"
#define BG_COLOR_CYAN    "\033[46m"
#define BG_COLOR_WHITE   "\033[47m"

bool isOpen[NN + 20];
bool isFull[NN + 20];
