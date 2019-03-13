#ifndef __MODULE_NCWMFRAME_HEADER_FILE_H
#define __MODULE_NCWMFRAME_HEADER_FILE_H

#include <ncurses.h>

class Frame
{
private:
    WINDOW *_win;

public:
    Frame(int initial);
    ~Frame();

    void run();
};


#endif  /* __MODULE_NCWMFRAME_HEADER_FILE_H */
