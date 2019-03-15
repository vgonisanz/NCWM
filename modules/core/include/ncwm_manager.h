#ifndef __MODULE_NCWMMANAGER_HEADER_FILE_H
#define __MODULE_NCWMMANAGER_HEADER_FILE_H

#include <ncurses.h>
#include <memory>
#include <vector>

#include "ncwm_types.h"
#include "frame.h"

class NcwmManager
{
private:
    static WINDOW *_stdscr;
    int _ch;            /* Store last character readed */
    bool _end_execution;
    std::vector<std::shared_ptr<Frame> > _frames;

public:
    NcwmManager();
    ~NcwmManager();

    void init();
    void add_frame(std::shared_ptr<Frame> frame);
    void redraw();
    bool run();

    Rect get_size();    /* Return stdscr size */
    void test();
    static void info();
};

#endif  /* __MODULE_NCWMMANAGER_HEADER_FILE_H */
