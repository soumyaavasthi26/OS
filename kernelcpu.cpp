#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream version("/proc/version");
    ifstream cpuinfo("/proc/cpuinfo");

    string line;

    cout << "Kernel Version:\n";
    while (getline(version, line)) {
        cout << line << endl;
        break; // Only first line
    }

    cout << "\nCPU Information:\n";
    while (getline(cpuinfo, line)) {
        if (line.find("model name") != string::npos || line.find("cpu MHz") != string::npos) {
            cout << line << endl;
        }
    }

    return 0;
}
