#ifndef __MODULE_NCWMFRAME_HEADER_FILE_H
#define __MODULE_NCWMFRAME_HEADER_FILE_H

#include <ncurses.h>
#include <map>
#include <functional>

#include "ncwm_types.h"

class Frame
{
private:
    WINDOW *_win;
    Rect _rect;
    Rect _constraint;   /* Max movable position. In example: Parent size. */
    int _ch;            /* Store last character readed */

    std::map<std::string, std::function<void()> > _mode_callbacks;

public:
    Frame(Rect rect, Rect constraint);
    ~Frame();

    void run();
    void refresh_win();

private:
    void create_win();          /* Create win using _rect data */
    void move_win();
    void update_win();
    void destroy_win();

    bool set_mode(std::string mode);

    void mode_normal();
    void mode_movement();
    void mode_resize();
};


#endif  /* __MODULE_NCWMFRAME_HEADER_FILE_H */
