#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MemoryAllocation {
public:
    void bestFit(vector<int>& blockSize, vector<int>& processSize) {
        int m = blockSize.size();
        int n = processSize.size();
        vector<int> allocation(n, -1);
        vector<bool> available(m, true);

        for (int i = 0; i < n; i++) {
            int bestIdx = -1;
            for (int j = 0; j < m; j++) {
                if (available[j] && blockSize[j] >= processSize[i]) {
                    if (bestIdx == -1 || blockSize[bestIdx] > blockSize[j]) {
                        bestIdx = j;
                    }
                }
            }
            if (bestIdx != -1) {
                allocation[i] = bestIdx;
                available[bestIdx] = false;
            }
        }

        cout << "Best Fit\n";
        printAllocation(processSize, allocation);
    }

    void firstFit(vector<int>& blockSize, vector<int>& processSize) {
        int m = blockSize.size();
        int n = processSize.size();
        vector<int> allocation(n, -1);
        vector<bool> available(m, true);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (available[j] && blockSize[j] >= processSize[i]) {
                    allocation[i] = j;
                    available[j] = false;
                    break;
                }
            }
        }

        cout << "First Fit\n";
        printAllocation(processSize, allocation);
    }

    void worstFit(vector<int>& blockSize, vector<int>& processSize) {
        int m = blockSize.size();
        int n = processSize.size();
        vector<int> allocation(n, -1);
        vector<bool> available(m, true);

        for (int i = 0; i < n; i++) {
            int worstIdx = -1;
            for (int j = 0; j < m; j++) {
                if (available[j] && blockSize[j] >= processSize[i]) {
                    if (worstIdx == -1 || blockSize[worstIdx] < blockSize[j]) {
                        worstIdx = j;
                    }
                }
            }
            if (worstIdx != -1) {
                allocation[i] = worstIdx;
                available[worstIdx] = false;
            }
        }

        cout << "Worst Fit\n";
        printAllocation(processSize, allocation);
    }

private:
    void printAllocation(const vector<int>& processSize, const vector<int>& allocation) {
        for (size_t i = 0; i < processSize.size(); i++) {
            cout << processSize[i] << " - ";
            if (allocation[i] != -1) {
                cout << allocation[i] + 1 << endl;
            } else {
                cout << "no free block allocated\n";
            }
        }
        cout << endl;
    }
};

int main() {
    int m, n;
    cout << "Enter the number of free blocks available: ";
    cin >> m;
    vector<int> blockSize(m);
    for (int i = 0; i < m; i++) {
        cin >> blockSize[i];
    }
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<int> processSize(n);
    for (int i = 0; i < n; i++) {
        cin >> processSize[i];
    }

    MemoryAllocation allocator;
    allocator.bestFit(blockSize, processSize);
    allocator.firstFit(blockSize, processSize);
    allocator.worstFit(blockSize, processSize);

    return 0;
}
