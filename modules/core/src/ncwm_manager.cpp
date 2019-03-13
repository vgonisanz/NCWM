#include <sstream>

#include "ncwm_manager.h"
#include "frame.h"

WINDOW* NcwmManager::_stdscr = nullptr;

NcwmManager::NcwmManager()
{
    printf("Initializing NcwmManager");
    _stdscr = initscr();
    raw();				            /* Line buffering disabled */
	keypad(stdscr, TRUE);	        /* We get F1, F2... */
	noecho();			            /* Don't echo() while we do getch */
    curs_set(NCWM_CURSOR::INVISIBLE);
    if (has_colors())
    {
        start_color();                  /* Allow color */
        //use_default_colors();           /* Default colors */
        if (can_change_color())         // TODO pallete colors
            init_pair(1, COLOR_RED, COLOR_BLACK);
    }
}

NcwmManager::~NcwmManager()
{
    endwin();
    //printf("Destroying NcwmManager");
}

void NcwmManager::init()
{
    printw("Hello World !!!");
	refresh();
	getch();
}

void NcwmManager::info()
{
    std::stringstream color_stream;
    color_stream << "\n\t\t" << "Has color?: " << (has_colors() ? std::string("true") : "false");

    std::stringstream size_stream;
    int max_row, max_col;
    getmaxyx(_stdscr, max_row, max_col);
    size_stream << "\n\t\tSize: " << max_row << " rows, " << max_col << " cols";

    std::stringstream baud_rate_stream;
    baud_rate_stream << "\n\t\tBaud rate: " << baudrate();

    werase(_stdscr);
    waddstr(_stdscr, "\n\tTerminal info:");
    waddstr(_stdscr, color_stream.str().c_str());
    if (has_colors())
    {
        waddstr(_stdscr, "\n\t\tNumber of colors: ");
        attron(COLOR_PAIR(1));
        waddstr(_stdscr, std::to_string(COLOR_PAIRS).c_str());
        attroff(COLOR_PAIR(1));
    }
    waddstr(_stdscr, size_stream.str().c_str());
    waddstr(_stdscr, baud_rate_stream.str().c_str());
    waddstr(_stdscr, "\n\n\tPush a key to continue...");
    getch();
}

void NcwmManager::test()
{
    Frame frame(5);
    frame.run();
}
