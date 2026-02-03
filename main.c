#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        write(2, "Usage: ./main <file>\n", 23);
        return 1;
    }


    char buffer[1024];
    int open_file = open(argv[1], O_RDONLY);
    if (open_file == -1) {
        perror("Error opening file");
        return 1;
    }

    ssize_t bytes_read;

    while ((bytes_read = read(open_file, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytes_read);
    }

    if (bytes_read == -1) {
        perror("Error reading file");
        close(open_file);
        return 1;
    }

    close(open_file);
    return 0;
}
