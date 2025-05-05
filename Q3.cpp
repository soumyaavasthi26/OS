//process control
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        std::cout << "Child Process ID: " << getpid() << std::endl;
        sleep(5);
    } else {
        std::cout << "Parent Process ID: " << getpid() << std::endl;
        kill(pid, SIGTERM); // send termination signal to child
        wait(NULL);
    }
    return 0;
}

//pipe and i/o redirection
#include <iostream>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    char buffer[100];

    pipe(pipefd);
    pid_t pid = fork();

    if (pid == 0) {
        close(pipefd[0]);
        const char *msg = "Hello from child!";
        write(pipefd[1], msg, strlen(msg) + 1);
    } else {
        close(pipefd[1]);
        read(pipefd[0], buffer, sizeof(buffer));
        std::cout << "Received: " << buffer << std::endl;
    }

    return 0;
}

//protection commands
chmod 755 file.txt        # Change permissions
chown user file.txt       # Change owner
chgrp group file.txt      # Change group
