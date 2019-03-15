#include "frame.h"

Frame::Frame(Rect rect, Rect constraint, bool movable, bool resizable):
_notify(nullptr),
_rect(rect),
_constraint(constraint),
_movable(movable),
_resizable(resizable)
{
    create_win();

    _mode_callbacks[std::string("normal")] = std::bind(&Frame::mode_normal, this);
    _mode_callbacks[std::string("movement")] = std::bind(&Frame::mode_movement, this);
    _mode_callbacks[std::string("resize")] = std::bind(&Frame::mode_resize, this);
}

Frame::~Frame()
{
    destroy_win();
}

void Frame::set_notify(std::function<void()> notify)
{
    _notify = notify;
}

void Frame::create_win()
{
    _win = newwin(_rect.height, _rect.width, _rect.y, _rect.x);
    draw_win();
    refresh_win();
}

void Frame::move_win()
{
    mvwin(_win, _rect.y, _rect.x);
    draw_win();
    refresh_win();
}

void Frame::destroy_win()
{
    delwin(_win);
}

void Frame::draw_win()
{
    box(_win, 0, 0);    /*debug purpose */
    wrefresh(_win);     /* Force refresh after draw */
}

void Frame::update_win()
{
    // Update internal rect struct with win data. Use only if win is changed externally
    getbegyx(_win, _rect.y, _rect.x);
    getmaxyx(_win, _rect.height, _rect.width);
}

void Frame::refresh_win()
{
    if(_notify != nullptr)
        _notify();
    wrefresh(_win);
}

void Frame::run()
{
    set_mode("normal");
}

bool Frame::set_mode(std::string mode)
{
    if ( _mode_callbacks.find(mode) == _mode_callbacks.end() )
        return false;

    auto callback_mode = _mode_callbacks[mode];
    callback_mode();
    return true;
}

void Frame::mode_normal()
{
    draw_win();
    refresh_win();
    while((_ch = getch()) != 'q')
    {
        switch(_ch)
        {
            case 'm':
                if (_movable)
                    set_mode("movement");
                break;
            case 'r':
                if (_resizable)
                    set_mode("resize");
                break;
        }
    }
}

void Frame::mode_resize()
{
    while((_ch = getch()) != 'q')
    {
        switch(_ch)
        {
            case KEY_LEFT:
                if (_rect.width > 2)
                    _rect.width -= 1;
                break;
            case KEY_RIGHT:
                if (_rect.x + _rect.width < _constraint.width)
                    _rect.width += 1;
                break;
            case KEY_UP:
                if (_rect.height > 2)
                    _rect.height -= 1;
                break;
            case KEY_DOWN:
                if (_rect.y + _rect.height < _constraint.height)
                    _rect.height += 1;
                break;
        }
        //clear();
        //refresh();
        destroy_win();
        create_win();
        refresh_win();
    }
}

void Frame::mode_movement()
{
    while((_ch = getch()) != 'q')
    {
        switch(_ch)
        {
            case KEY_LEFT:
                if (_rect.x > _constraint.x)
                    _rect.x -= 1;
                break;
            case KEY_RIGHT:
                if (_rect.x + _rect.width < _constraint.width)
                    _rect.x += 1;
                break;
            case KEY_UP:
                if (_rect.y > _constraint.y)
                    _rect.y -= 1;
                break;
            case KEY_DOWN:
                if (_rect.y + _rect.height < _constraint.height)
                    _rect.y += 1;
                break;
            default:
                break;
        }
        //clear();
        //refresh();
        refresh();
        move_win();
        refresh_win();
    }
}
