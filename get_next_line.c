#include "get_next_line.h"

static char  *fill_line(int fd, char *left_c, char *buffer),
static char  *set_line(char *line),

char  *get_next_line(int fd)
