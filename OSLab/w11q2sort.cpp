#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAXTRACKS 200

int scan(int n, vector<int> requests, int currHead) {
    sort(requests.begin(), requests.end());
    int totalSeek = 0;
    cout << "Seek sequence: ";
    int idx = 0;
    while (idx < n && requests[idx] < currHead) {
        idx++;
    }
    int i = idx;
    while (i < n) {
        totalSeek += abs(requests[i] - currHead);
        currHead = requests[i];
        cout << currHead << " ";
        i++;
    }
    if (idx > 0) {
        totalSeek += abs(MAXTRACKS - 1 - currHead);
        currHead = MAXTRACKS - 1;
        i = idx - 1;
        while (i >= 0) {
            totalSeek += abs(requests[i] - currHead);
            currHead = requests[i];
            cout << currHead << " ";
            i--;
        }
    }
    cout << endl;
    return totalSeek;
}

int main() {
    int n;
    cout << "Enter the number of disk requests: ";
    cin >> n;
    vector<int> requests(n);
    cout << "Enter the disk requests: ";
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
        if (requests[i] >= MAXTRACKS || requests[i] < 0) {
            cout << "Error: Requested track is out of range." << endl;
            return 1;
        }
    }
    int currHead;
    cout << "Enter the current head position: ";
    cin >> currHead;

    cout << "Total seek movement: " << scan(n, requests, currHead) << endl;

    return 0;
}
