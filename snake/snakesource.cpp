#include <cstdlib>
#include <iostream>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include "platform/compat.h"
#endif

#include "menu.h"

using namespace std;

int snaky()
{

    srand(time(NULL));
	system("title Snake");
     slapsh_screen();
    return EXIT_SUCCESS;
}
