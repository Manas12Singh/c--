#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAXTRACKS 200

class DiskScheduler {
public:
    DiskScheduler(int n, vector<int> requests, int currHead)
        : n(n), requests(requests), currHead(currHead), totalSeek(0), direction(1), completed(0) {
        reqCompleted.resize(n, false);
    }

    int scan() {
        cout << "Seek sequence: ";
        while (completed < n) {
            int nextReq = -1;
            for (int j = 0; j < n; j++) {
                if (!reqCompleted[j] && direction * requests[j] >= direction * currHead) {
                    if (nextReq == -1 || direction * requests[j] <= direction * requests[nextReq])
                        nextReq = j;
                }
            }
            if (nextReq == -1) {
                if (direction == 1) {
                    totalSeek += MAXTRACKS - 1 - currHead;
                    currHead = MAXTRACKS - 1;
                } else {
                    totalSeek += currHead;
                    currHead = 0;
                }
                direction *= -1;
            } else {
                totalSeek += abs(requests[nextReq] - currHead);
                currHead = requests[nextReq];
                reqCompleted[nextReq] = true;
                completed++;
                cout << currHead << " ";
            }
        }
        cout << endl;
        return totalSeek;
    }

private:
    int n;
    vector<int> requests;
    int currHead;
    int totalSeek;
    int direction;
    int completed;
    vector<bool> reqCompleted;
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

    DiskScheduler scheduler(n, requests, currHead);
    cout << "Total seek movement: " << scheduler.scan() << endl;

    return 0;
}
