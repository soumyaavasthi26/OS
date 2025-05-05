#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int id, bt;
};

bool compare(Process a, Process b) {
    return a.bt < b.bt;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter burst time for P" << i + 1 << ": ";
        cin >> p[i].bt;
    }

    sort(p, p + n, compare);

    int wt[n], tat[n];
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + p[i - 1].bt;
    }

    cout << "\nProcess\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        tat[i] = p[i].bt + wt[i];
        cout << "P" << p[i].id << "\t" << p[i].bt << "\t" << wt[i] << "\t" << tat[i] << endl;
    }

    return 0;
}
