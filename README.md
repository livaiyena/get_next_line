_This project has been created as part of the 42 curriculum by kapaydin_

## Description

The `get_next_line` project is a robust C function designed to read content from a file descriptor line by line. Subsequent calls to the function sequentially return the next available line from the file until the end-of-file (EOF) is reached. If an error occurs or the file is fully read, it safely returns `NULL`.

A core technical component of this project is the implementation of **static variables** for persistent state management between function calls, ensuring memory safety and precise data handling without the use of global variables.

## Instructions

### Compilation

To use the function in your project, compile the source files alongside your main application. You can define the buffer chunk size for the `read()` function using the `-D BUFFER_SIZE=n` flag during compilation.

```bash
# Example compilation with a buffer size of 100
cc -Wall -Wextra -Werror -D BUFFER_SIZE=100 get_next_line.c get_next_line_utils.c main.c -o gnl_test
```

If the `BUFFER_SIZE` flag is omitted, the program will automatically utilize a default value specified within the header file.

### Usage Example

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("text_file.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1);
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Algorithmic Overview

The solution utilizes a single `static char *` variable to persist string data across multiple function invocations. The processing logic is structured as follows:

1.  **Data Ingestion**: Data is read from the file descriptor in chunks corresponding to the `BUFFER_SIZE`. These chunks are dynamically concatenated to the static variable until a newline character (`\n`) is detected or EOF is reached.
2.  **Line Extraction**: Once a complete line is identified within the static buffer, the content up to and including the first newline character is extracted, allocated, and returned as the result.
3.  **Buffer Updating**: Any residual data remaining in the static buffer after the extracted line is isolated, duplicated into a new allocation, and stored back into the static variable for the next function call. The old buffer is subsequently freed to prevent memory leaks.

## Resources

*   [Static Variables in C (Wikipedia)](https://en.wikipedia.org/wiki/Static_variable)
*   [File Descriptors in C](https://en.wikipedia.org/wiki/File_descriptor)

## AI Usage Acknowledgment

AI tools were utilized during the development of this project for:
*   Generating edge-case testing structures to validate memory safety and function accuracy across various buffer configurations.
*   Assisting in formatting the markdown structure of this documentation.