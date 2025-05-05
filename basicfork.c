#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        cerr << "Fork failed!" << endl;
        return 1;
    } else if (pid == 0) {
        cout << "Child Process (PID: " << getpid() << ") running." << endl;
    } else {
        wait(NULL); // Parent waits for child
        cout << "Parent Process (PID: " << getpid() << ") resumes after child." << endl;
    }

    return 0;
}
