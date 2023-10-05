# get_next_line - Read Lines from File Descriptors - ⭐Grade 125/100

#### Grade rating
- ✅ = Okay project
- ⭐ = Outstanding project

The `get_next_line` function is designed to read text files pointed to by file descriptors, one line at a time. It allows repeated calls (e.g., using a loop) to read a file or standard input sequentially.

## Functionality

- Repeated Calls: You can use `get_next_line` in a loop to read a text file or standard input one line at a time.

- Return Value: The function returns the line that was read. If there is nothing else to read or if an error occurred, it returns NULL.

- Line Termination: The returned line includes the terminating `\n` character, except if the end of the file was reached, and it does not end with a `\n` character.

## Buffer Size

To define the buffer size for reading, compile your code with the `-D BUFFER_SIZE=n` option, where `n` is the desired buffer size.

Example Compilation:

~~~shell
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
~~~

## Behavior Considerations

- Undefined Behavior: `get_next_line` has undefined behavior if the file pointed to by the file descriptor changed since the last call, and `read()` didn’t reach the end of the file.

- Binary Files: `get_next_line` is not designed for reading binary files.

## Managing Multiple File Descriptors

`get_next_line` can manage multiple file descriptors simultaneously. For example, if you can read from file descriptors 3, 4, and 5, you should be able to read from a different file descriptor per call without losing the reading thread of each file descriptor or returning a line from another file descriptor. This was achieved by using linked lists to store the state of each file descriptor.

## Example Usage

Here's an example of how to use `get_next_line`:

```c
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return (0);
}
```

This code opens a file named "example.txt," reads it line by line, and prints each line to the standard output. Feel free to use get_next_line to read text files and customize your code as needed.
