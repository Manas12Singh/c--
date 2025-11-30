#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct Order {
    int id;
    int arrival;
    int packing;
    int priority;

    Order(int i, int a, int p, int v) : id(i), arrival(a), packing(p), priority(v) {}
};

bool compareOrders(const Order& a, const Order& b) {
    if (a.priority != b.priority) {
        return a.priority > b.priority;
    }

    if (a.arrival != b.arrival) {
        return a.arrival < b.arrival;
    }

    return a.packing < b.packing;
}

int main() {
    int n;
    cin >> n;

    vector<Order> orders;
    for (int i = 0; i < n; ++i) {
        int arrival, packing, priority;
        cin >> arrival >> packing >> priority;
        orders.emplace_back(i, arrival, packing, priority);
    }

    sort(orders.begin(), orders.end(), compareOrders);

    long long currentTime = 0;
    int maxChairs = 0;
    
    priority_queue<long long, vector<long long>, greater<long long>> chairDepartureTimes;

    for (int i = 0; i < n; ++i) {
        int arrivalTime = orders[i].arrival;
        int packingTime = orders[i].packing;

        while (!chairDepartureTimes.empty() && chairDepartureTimes.top() <= arrivalTime) {
            chairDepartureTimes.pop();
        }

        long long startTime = max((long long)arrivalTime, currentTime);
        long long finishTime = startTime + packingTime;
        currentTime = finishTime;

        if (arrivalTime < startTime) {
            chairDepartureTimes.push(startTime);
        }

        maxChairs = max(maxChairs, (int)chairDepartureTimes.size());
    }

    cout << maxChairs << endl;

    return 0;
}