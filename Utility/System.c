#include <stdio.h>
#include <stdlib.h>
#include "Utility/System.h"

#if defined(SYSTEM_WINDOWS)
# include <windows.h>
#elif defined(SYSTEM_LINUX)
# include <unistd.h>
#endif

void clearConsole(void) {

#if defined(SYSTEM_WINDOWS)
    system("cls");
#elif defined(SYSTEM_LINUX)
    system("clear");
#endif

}
