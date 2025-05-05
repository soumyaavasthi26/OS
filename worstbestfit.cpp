#include <iostream>
using namespace std;

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    fill(allocation, allocation + n, -1);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }

    cout << "\nFirst Fit Allocation:\nProcess\tBlock\n";
    for (int i = 0; i < n; i++)
        cout << "P" << i + 1 << "\t" << (allocation[i] != -1 ? to_string(allocation[i] + 1) : "Not Allocated") << endl;
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    fill(allocation, allocation + n, -1);

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
            if (blockSize[j] >= processSize[i])
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    cout << "\nBest Fit Allocation:\nProcess\tBlock\n";
    for (int i = 0; i < n; i++)
        cout << "P" << i + 1 << "\t" << (allocation[i] != -1 ? to_string(allocation[i] + 1) : "Not Allocated") << endl;
}

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    fill(allocation, allocation + n, -1);

    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++)
            if (blockSize[j] >= processSize[i])
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    cout << "\nWorst Fit Allocation:\nProcess\tBlock\n";
    for (int i = 0; i < n; i++)
        cout << "P" << i + 1 << "\t" << (allocation[i] != -1 ? to_string(allocation[i] + 1) : "Not Allocated") << endl;
}

int main() {
    int m, n;
    cout << "Enter number of blocks: ";
    cin >> m;
    int blockSize[m];
    cout << "Enter block sizes:\n";
    for (int i = 0; i < m; i++) cin >> blockSize[i];

    cout << "Enter number of processes: ";
    cin >> n;
    int processSize[n];
    cout << "Enter process sizes:\n";
    for (int i = 0; i < n; i++) cin >> processSize[i];

    int blockCopy1[m], blockCopy2[m];
    copy(blockSize, blockSize + m, blockCopy1);
    copy(blockSize, blockSize + m, blockCopy2);

    firstFit(blockSize, m, processSize, n);
    bestFit(blockCopy1, m, processSize, n);
    worstFit(blockCopy2, m, processSize, n);

    return 0;
}
