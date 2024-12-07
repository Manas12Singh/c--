#include <iostream>
#include <vector>

using namespace std;

class Process {
public:
    bool finish;
    int id;
    vector<int> maxReq;
    vector<int> allocated;

    Process(int id, int r) : id(id), finish(false), maxReq(r), allocated(r) {}
};

int main() {
    int p, r;
    cout << "Enter number of processes: ";
    cin >> p;
    cout << "Enter number of resources: ";
    cin >> r;

    vector<int> resource(r);
    vector<int> available(r, 0);
    vector<Process> processes;

    for (int i = 0; i < p; ++i) {
        processes.emplace_back(i, r);
    }

    cout << "Enter maximum requirement:\n";
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < r; ++j) {
            cin >> processes[i].maxReq[j];
        }
    }

    cout << "Enter allocated matrix:\n";
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < r; ++j) {
            cin >> processes[i].allocated[j];
            available[j] -= processes[i].allocated[j];
        }
    }

    cout << "Enter resource vector: ";
    for (int i = 0; i < r; ++i) {
        cin >> resource[i];
        available[i] += resource[i];
    }

    for (int i = 0; i < p; ++i) {
        int canFinish = -1;
        for (int j = 0; j < p; ++j) {
            if (!processes[j].finish) {
                int k;
                for (k = 0; k < r; ++k) {
                    if (processes[j].maxReq[k] - processes[j].allocated[k] > available[k]) {
                        break;
                    }
                }
                if (k == r) {
                    canFinish = j;
                    break;
                }
            }
        }
        if (canFinish == -1) {
            cout << "Deadlock detected\n";
            return 0;
        }
        for (int j = 0; j < r; ++j) {
            available[j] += processes[canFinish].allocated[j];
        }
        processes[canFinish].finish = true;
    }

    cout << "No deadlock detected\n";
    return 0;
}