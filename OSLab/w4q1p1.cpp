#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process {
public:
    int id;
    int arrivalTime;
    int priority;
    int burstTime;
    int remainingTime;
    bool isCompleted;

    Process(int id, int arrivalTime, int priority, int burstTime)
        : id(id), arrivalTime(arrivalTime), priority(priority), burstTime(burstTime), remainingTime(burstTime), isCompleted(false) {}
};

bool compareArrival(const Process &a, const Process &b) {
    return a.arrivalTime < b.arrivalTime;
}

void priorityScheduling(int n, vector<Process> &processes, double &avgWaitTime, double &avgTurnAroundTime) {
    sort(processes.begin(), processes.end(), compareArrival);
    avgWaitTime = 0;
    avgTurnAroundTime = 0;
    int currentTime = processes[0].arrivalTime;
    int completed = 0;
    int prev = -1;
    int j = 0;

    cout << "Priority Scheduling Gantt Chart: ";
    while (completed < n) {
        while (j < n && processes[j].arrivalTime <= currentTime)
            j++;
        int m = -1;
        for (int k = 0; k < j; k++)
            if (!processes[k].isCompleted && (m == -1 || processes[k].priority < processes[m].priority))
                m = k;
        if (m == -1) {
            currentTime = processes[j].arrivalTime;
            continue;
        }
        if (prev != processes[m].id) {
            cout << "P" << processes[m].id << " ";
            prev = processes[m].id;
        }
        int runTime = processes[m].remainingTime;
        if (j < n)
            runTime = min(runTime, processes[j].arrivalTime - currentTime);
        processes[m].remainingTime -= runTime;
        currentTime += runTime;
        if (processes[m].remainingTime == 0) {
            processes[m].isCompleted = true;
            avgWaitTime += currentTime - processes[m].arrivalTime - processes[m].burstTime;
            avgTurnAroundTime += currentTime - processes[m].arrivalTime;
            completed++;
        }
    }
    cout << endl;
    avgWaitTime /= n;
    avgTurnAroundTime /= n;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> processes;
    cout << "Enter burst times: ";
    for (int i = 0; i < n; i++) {
        int burstTime;
        cin >> burstTime;
        processes.emplace_back(i, 0, 0, burstTime);
    }
    cout << "Enter arrival times: ";
    for (int i = 0; i < n; i++) {
        cin >> processes[i].arrivalTime;
    }
    cout << "Enter priorities: ";
    for (int i = 0; i < n; i++) {
        cin >> processes[i].priority;
    }
    double avgWaitTime, avgTurnAroundTime;
    priorityScheduling(n, processes, avgWaitTime, avgTurnAroundTime);
    cout << "Average Waiting Time: " << avgWaitTime << endl;
    cout << "Average Turnaround Time: " << avgTurnAroundTime << endl;
    return 0;
}
