//same code same output
#include <iostream>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0 || pid > 0) {
        std::cout << "Process ID: " << getpid() << " executing same code." << std::endl;
    }

    return 0;
}

//same code different output 
#include <iostream>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        std::cout << "Child Process: " << getpid() << std::endl;
    } else {
        std::cout << "Parent Process: " << getpid() << std::endl;
    }

    return 0;
}

//parent waits for child
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        std::cout << "Child running...\n";
        sleep(2);
        std::cout << "Child done.\n";
    } else {
        wait(NULL);
        std::cout << "Parent resumes after child.\n";
    }

    return 0;
}
