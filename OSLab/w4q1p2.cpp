#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Process {
public:
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;

    Process(int id, int arrivalTime, int burstTime)
        : id(id), arrivalTime(arrivalTime), burstTime(burstTime), remainingTime(burstTime) {}
};

bool compareArrival(const Process &a, const Process &b) {
    return a.arrivalTime < b.arrivalTime;
}

void roundRobin(int n, vector<Process> &processes, double &avgWaitTime, double &avgTurnAroundTime, int timeQuantum) {
    for (auto &process : processes) {
        process.remainingTime = process.burstTime;
    }
    sort(processes.begin(), processes.end(), compareArrival);

    avgWaitTime = 0;
    avgTurnAroundTime = 0;
    queue<int> q;
    int currentTime = processes[0].arrivalTime;
    int prev = -1;
    int completed = 0;
    int j = 1;
    q.push(0);
    cout << "Round Robin Gantt Chart: ";
    while (completed < n) {
        if (q.empty()) {
            currentTime = processes[j].arrivalTime;
            q.push(j++);
            continue;
        }
        int i = q.front();
        q.pop();
        if (prev != processes[i].id) {
            cout << "P" << processes[i].id << " ";
            prev = processes[i].id;
        }
        int runTime = min(processes[i].remainingTime, timeQuantum);
        processes[i].remainingTime -= runTime;
        currentTime += runTime;
        while (j < n && processes[j].arrivalTime <= currentTime) {
            q.push(j++);
        }
        if (processes[i].remainingTime == 0) {
            avgWaitTime += currentTime - processes[i].arrivalTime - processes[i].burstTime;
            avgTurnAroundTime += currentTime - processes[i].arrivalTime;
            completed++;
        } else {
            q.push(i);
        }
    }
    cout << endl;
    avgWaitTime /= n;
    avgTurnAroundTime /= n;
}

int main() {
    int n, timeQuantum;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> processes;
    cout << "Enter burst times: ";
    for (int i = 0; i < n; i++) {
        int burstTime;
        cin >> burstTime;
        processes.emplace_back(i, 0, burstTime);
    }
    cout << "Enter arrival times: ";
    for (int i = 0; i < n; i++) {
        cin >> processes[i].arrivalTime;
    }
    cout << "Enter time quantum: ";
    cin >> timeQuantum;
    double avgWaitTime, avgTurnAroundTime;
    roundRobin(n, processes, avgWaitTime, avgTurnAroundTime, timeQuantum);
    cout << "Average Waiting Time: " << avgWaitTime << endl;
    cout << "Average Turnaround Time: " << avgTurnAroundTime << endl;
    return 0;
}
