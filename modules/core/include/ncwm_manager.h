#ifndef __MODULE_NCWMMANAGER_HEADER_FILE_H
#define __MODULE_NCWMMANAGER_HEADER_FILE_H

#include <ncurses.h>

class NcwmManager
{
private:
    static WINDOW *_stdscr;

public:
    NcwmManager();
    ~NcwmManager();

    void init();
    static void info();
};

#endif  /* __MODULE_NCWMMANAGER_HEADER_FILE_H */
