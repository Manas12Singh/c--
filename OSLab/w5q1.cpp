#include <iostream>
#include <vector>

using namespace std;

class Process {
public:
    int id;
    vector<int> maxReq;
    vector<int> allocated;

    Process(int id, int r) : id(id), maxReq(r), allocated(r) {}
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

    for (int i = 0; i < p; i++) {
        processes.emplace_back(i, r);
    }

    cout << "Enter maximum requirement:\n";
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            cin >> processes[i].maxReq[j];
        }
    }

    cout << "Enter allocated matrix:\n";
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            cin >> processes[i].allocated[j];
            available[j] -= processes[i].allocated[j];
        }
    }

    cout << "Enter resource vector: ";
    for (int i = 0; i < r; i++) {
        cin >> resource[i];
        available[i] += resource[i];
    }

    for (int i = 0; i < p; i++) {
        int canFinish = i;
        while (canFinish < p) {
            int j = 0;
            while (j < r) {
                if (processes[canFinish].maxReq[j] - processes[canFinish].allocated[j] > available[j])
                    break;
                j++;
            }
            if (j == r)
                break;
            canFinish++;
        }
        if (canFinish == p) {
            cout << "Request cannot be fulfilled\n";
            return 0;
        }
        while (canFinish > i) {
            swap(processes[canFinish], processes[canFinish - 1]);
            canFinish--;
        }
        for (int j = 0; j < r; j++) {
            available[j] += processes[i].allocated[j];
        }
    }

    cout << "Request can be fulfilled\n";
    cout << "Safe sequence: ";
    for (int i = 0; i < p; i++) {
        cout << "P" << processes[i].id << " ";
    }
    cout << endl;

    return 0;
}
