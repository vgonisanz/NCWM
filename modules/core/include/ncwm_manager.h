#ifndef __MODULE_NCWMMANAGER_HEADER_FILE_H
#define __MODULE_NCWMMANAGER_HEADER_FILE_H

#include <ncurses.h>

#include "ncwm_types.h"

class NcwmManager
{
private:
    static WINDOW *_stdscr;

public:
    NcwmManager();
    ~NcwmManager();

    void init();
    void test();
    static void info();
};

#endif  /* __MODULE_NCWMMANAGER_HEADER_FILE_H */
