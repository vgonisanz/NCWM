#ifndef __MODULE_NCWMTYPES_HEADER_FILE_H
#define __MODULE_NCWMTYPES_HEADER_FILE_H

#include <stdint.h>

enum NCWM_CURSOR : uint8_t {
    INVISIBLE = 0,
    VISIBLE = 1,
    VERY_VISIBLE = 2,
};

typedef struct Rect
{
    int x;
    int y;
    int width;
    int height;
} Rect;

#endif  /* __MODULE_NCWMTYPES_HEADER_FILE_H */
