#include <iostream>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int src = open("source.txt", O_RDONLY);
    int dest = open("copy.txt", O_WRONLY | O_CREAT, 0644);

    if (src < 0 || dest < 0) {
        std::cerr << "Error opening files." << std::endl;
        return 1;
    }

    char buffer[1024];
    ssize_t bytes;

    while ((bytes = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytes);
    }

    close(src);
    close(dest);
    std::cout << "File copied successfully.\n";

    return 0;
}
