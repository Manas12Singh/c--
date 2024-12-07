#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXTRACKS 200

class CSCAN {
public:
    CSCAN(int n, vector<int> requests, int currHead)
        : n(n), requests(requests), currHead(currHead) {}

    int calculateTotalSeek() {
        int totalSeek = 0;
        vector<bool> reqCompleted(n, false);
        int completed = 0;

        cout << "Seek sequence: ";
        while (completed < n) {
            int nextReq = -1;
            for (int j = 0; j < n; j++) {
                if (!reqCompleted[j] && requests[j] >= currHead) {
                    if (nextReq == -1 || requests[j] <= requests[nextReq])
                        nextReq = j;
                }
            }
            if (nextReq != -1) {
                totalSeek += requests[nextReq] - currHead;
                currHead = requests[nextReq];
                reqCompleted[nextReq] = true;
                completed++;
                cout << currHead << " ";
            } else {
                totalSeek += 2 * (MAXTRACKS - 1) - currHead;
                currHead = 0;
            }
        }
        cout << endl;
        return totalSeek;
    }

private:
    int n;
    vector<int> requests;
    int currHead;
};

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

    CSCAN cscan(n, requests, currHead);
    cout << "Total seek movement: " << cscan.calculateTotalSeek() << endl;

    return 0;
}
