#ifndef __MODULE_NCWMMANAGER_HEADER_FILE_H
#define __MODULE_NCWMMANAGER_HEADER_FILE_H

#include <ncurses.h>
#include <vector>

#include "ncwm_types.h"
#include "frame.h"

class NcwmManager
{
private:
    static WINDOW *_stdscr;
    int _ch;            /* Store last character readed */
    std::vector<Frame> _frames;

public:
    NcwmManager();
    ~NcwmManager();

    void init();
    bool run();

    Rect get_size();    /* Return stdscr size */
    void test();
    static void info();
};

#endif  /* __MODULE_NCWMMANAGER_HEADER_FILE_H */
