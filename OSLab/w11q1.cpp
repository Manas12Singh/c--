#include <iostream>
#include <vector>
#include <cmath>

#define MAXTRACKS 200

using namespace std;

class DiskScheduler {
public:
    DiskScheduler(int currHead) : currHead(currHead) {}

    int fcfs(const vector<int>& requests) {
        int totalSeek = 0;
        cout << "Seek sequence: ";
        for (int request : requests) {
            totalSeek += abs(request - currHead);
            currHead = request;
            cout << currHead << " ";
        }
        cout << endl;
        return totalSeek;
    }

private:
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

    DiskScheduler scheduler(currHead);
    cout << "Total seek movement: " << scheduler.fcfs(requests) << endl;

    return 0;
}
