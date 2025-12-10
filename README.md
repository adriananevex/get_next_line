*This project has been created as part of the 42 curriculum by <aneves>.*

# get_next_line

## Description

The **get_next_line** project consists of implementing a function capable of **reading a file descriptor line by line**, returning one line per call, including the newline character (`\n`) when present.

Its main goal is to teach the management of static variables, file descriptors, memory allocation, and buffered reading in C.  
This project reinforces string manipulation and algorithmic thinking for efficient reading of text streams.

The core function of this project is:

```c
char *get_next_line(int fd);
```
It returns:
One line per call,
NULL when no more lines can be read or when an error occurs.

## Instructions

### Compilation

To compile the project:
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl

To specify another buffer size:
cc -Wall -Wextra -Werror -D BUFFER_SIZE=100 get_next_line.c get_next_line_utils.c -o gnl

### Example of Execution

Create a simple main.c to test:

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}

Compile and run:
cc main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42 && ./a.out

### Algorithm Explanation & Justification

The algorithm follows a classic and efficient structure for buffered line reading using a static internal buffer.

1. Static Buffer

A static array stores leftover bytes between calls.

✔ Avoids re-reading data
✔ Keeps state between calls
✔ Required by the subject

2. Buffered Reading

Data is read from the file descriptor in chunks of BUFFER_SIZE only when the static buffer is empty.

✔ Reduces system calls
✔ Handles large files efficiently

3. Line Assembly

The function ft_join_b() reallocates and concatenates previously stored data with newly read content.

✔ Memory-safe dynamic concatenation
✔ Handles arbitrarily long lines

4. Stopping When a Line is Complete

As soon as a newline (\n) is found inside the assembled line, the function returns promptly.

✔ Mimics standard line readers
✔ Prevents unnecessary reads

5. Leftover Buffer Shift

After returning a complete line, ft_left() shifts the remaining characters after the newline to the beginning of the static buffer.

✔ Preserves unread data
✔ Ensures next call starts at the correct point

### File Structure
get_next_line.h
get_next_line.c
get_next_line_utils.c
README.md

## Resources

### Classic References

C standard library documentation (malloc, free, pointers)
Tutorials about file descriptors in Unix
Official 42 subject PDF for get_next_line

### AI Usage Disclosure

AI was used to clarify conceptual doubts and, after the logic was fully implemented, to help clean up the code and ensure compliance with the Norminette rules.

AI was also used for writing and organizing documentation, specifically:
Formatting and structuring this README
Expanding explanations clearly

AI did NOT write or design the C logic, which was fully implemented manually by the student together with classmates.

## Additional Notes

This project reinforces:

Understanding of static variables
Memory management
Efficient low-level read operations

Handling edge cases:
Empty files
Large lines
Partial reads
Different buffer sizes