#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class PageReplacement {
public:
    PageReplacement(int memorySize) : memorySize(memorySize), pageFaults(0) {}

    int fifo(const vector<int>& pages) {
        queue<int> memory;
        unordered_set<int> s;
        cout << "Page Faults: ";
        for (int page : pages) {
            if (s.find(page) == s.end()) {
                pageFaults++;
                if (memory.size() == memorySize) {
                    int front = memory.front();
                    memory.pop();
                    s.erase(front);
                }
                memory.push(page);
                s.insert(page);
                cout << page << " ";
            }
        }
        return pageFaults;
    }

private:
    int memorySize;
    int pageFaults;
};

int main() {
    int n, memorySize;
    cout << "Enter number of frames available: ";
    cin >> memorySize;
    cout << "Enter number of requests: ";
    cin >> n;
    vector<int> pages(n);
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    PageReplacement pr(memorySize);
    cout << "\nNo of Page Faults: " << pr.fifo(pages) << endl;
    return 0;
}
