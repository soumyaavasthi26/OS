#include <iostream>
#include <pthread.h>
using namespace std;

int *arr, sum = 0, n;

void* compute_sum(void* arg) {
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    pthread_exit(NULL);
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;
    arr = new int[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    pthread_t tid;
    pthread_create(&tid, NULL, compute_sum, NULL);
    pthread_join(tid, NULL);

    cout << "Sum: " << sum << endl;
    delete[] arr;
    return 0;
}
