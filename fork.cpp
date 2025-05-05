#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    pid_t pid = fork();  // Create child process

    if (pid < 0) {
        cerr << "Fork failed!" << endl;
        return 1;
    }

    else if (pid == 0) {
        // ----------------------------
        // CHILD PROCESS
        // ----------------------------
        cout << "[Child] PID: " << getpid() << ", Parent PID: " << getppid() << endl;

        // i. Same program, same code: both print their PIDs above

        // ii. Same program, different code (child does something unique)
        cout << "[Child] I am performing a child-specific task..." << endl;
        for (int i = 1; i <= 5; i++) {
            cout << "[Child] Counting: " << i << endl;
            sleep(1);
        }

        cout << "[Child] Finished task.\n";
    }

    else {
        // ----------------------------
        // PARENT PROCESS
        // ----------------------------
        cout << "[Parent] PID: " << getpid() << ", Waiting for child to finish...\n";

        // iii. Parent waits for child before continuing
        wait(NULL); // Wait for child to complete

        cout << "[Parent] Child finished. Now parent resumes and exits.\n";
    }

    return 0;
}
