#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream meminfo("/proc/meminfo");
    string line;

    cout << "Memory Information:\n";
    int count = 0;
    while (getline(meminfo, line) && count < 5) {
        cout << line << endl;
        count++;
    }

    return 0;
}
