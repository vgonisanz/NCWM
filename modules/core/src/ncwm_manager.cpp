#include "ncwm_manager.h"

NcwmManager::NcwmManager()
{
    printf("Initializing NcwmManager");
    initscr();
}

NcwmManager::~NcwmManager()
{
    endwin();
    printf("Destroying NcwmManager");
}

void NcwmManager::init()
{
    printw("Hello World !!!");
	refresh();
	getch();
}
