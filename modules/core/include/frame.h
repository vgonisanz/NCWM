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
    int _ch;            /* Store last character readed */

    Rect _rect;
    Rect _constraint;   /* Max movable position. In example: Parent size. */

    bool _movable;
    bool _resizable;

    std::function<void()> _notify;  /* Callback to notify important changes */
    std::map<std::string, std::function<void()> > _mode_callbacks;

public:
    Frame(Rect rect, Rect constraint, bool movable = false, bool resizable = false);
    ~Frame();

    void run();
    void draw_win();
    void refresh_win();
    void set_notify(std::function<void()> notify);  /* Callback to notify a interface change */

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
