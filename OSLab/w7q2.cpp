#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), pageFaults(0) {}

    void processPages(int n, int* pages) {
        for (int i = 0; i < n; ++i) {
            accessPage(pages[i]);
        }
        cout << "\nNo of Page Faults: " << pageFaults << endl;
    }

private:
    int capacity;
    int pageFaults;
    list<int> memory;
    unordered_map<int, list<int>::iterator> pageMap;

    void accessPage(int page) {
        auto it = pageMap.find(page);
        if (it == pageMap.end()) {
            pageFaults++;
            if (memory.size() == capacity) {
                int oldPage = memory.back();
                pageMap.erase(oldPage);
                memory.pop_back();
            }
            memory.push_front(page);
            pageMap[page] = memory.begin();
            cout << page << " ";
        } else {
            memory.erase(it->second);
            memory.push_front(page);
            pageMap[page] = memory.begin();
        }
    }
};

int main() {
    int n, memorySize;
    cout << "Enter number of frames available: ";
    cin >> memorySize;
    cout << "Enter number of requests: ";
    cin >> n;
    int* pages = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> pages[i];

    LRUCache lruCache(memorySize);
    lruCache.processPages(n, pages);

    delete[] pages;
    return 0;
}
