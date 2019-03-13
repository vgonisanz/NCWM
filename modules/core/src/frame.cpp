#include "frame.h"

Frame::Frame(int initial)
{
    _win = newwin(initial, initial, initial, initial);
}

Frame::~Frame()
{
    delwin(_win);
}

void Frame::run()
{
    box(_win, 0, 0);

    int curr_x;
    int curr_y;
    int c;

    //cbreak();
	//noecho();
    //while(1)
	//{
    getbegyx(_win, curr_y, curr_x);
    c = wgetch(_win);
    waddch(_win, c);
	/*switch(c)
	{
        case KEY_UP:
            curr_y -= 1;
            waddstr(_win, "UP");
            break;
        case KEY_DOWN:
            curr_y += 1;
            waddstr(_win, "DOWN");
            break;
        case KEY_LEFT:
            curr_x -= 1;
            waddstr(_win, "LEFT");
            break;
        case KEY_RIGHT:
            curr_x += 1;
            waddstr(_win, "RIGHT");
            break;
        default:
            break;
    }*/
    //mvwin(_win, curr_y, curr_x);
    //wrefresh(_win);
    //wgetch(_win);
    //wgetch(_win);
    //}
}
