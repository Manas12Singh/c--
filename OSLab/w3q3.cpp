#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process {
public:
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    bool isCompleted;

    Process(int id, int arrivalTime, int burstTime)
        : id(id), arrivalTime(arrivalTime), burstTime(burstTime), remainingTime(burstTime), isCompleted(false) {}
};

bool compareArrival(const Process &a, const Process &b) {
    return a.arrivalTime < b.arrivalTime;
}

void srt(vector<Process> &processes, double &avgWaitTime, double &avgTurnAroundTime) {
    sort(processes.begin(), processes.end(), compareArrival);
    avgWaitTime = 0;
    avgTurnAroundTime = 0;
    int currentTime = processes[0].arrivalTime;
    int completed = 0, j = 0, prev = -1;
    cout << "Gantt Chart: ";
    while (completed < processes.size()) {
        while (j < processes.size() && processes[j].arrivalTime <= currentTime)
            j++;
        int minIndex = -1;
        for (int k = 0; k < j; k++)
            if (!processes[k].isCompleted && (minIndex == -1 || processes[k].remainingTime < processes[minIndex].remainingTime))
                minIndex = k;
        if (minIndex == -1) {
            currentTime = processes[j].arrivalTime;
            continue;
        }
        if (prev != processes[minIndex].id) {
            cout << "P" << processes[minIndex].id << " ";
            prev = processes[minIndex].id;
        }
        int runTime = processes[minIndex].remainingTime;
        if (j < processes.size())
            runTime = min(processes[minIndex].remainingTime, processes[j].arrivalTime - currentTime);
        processes[minIndex].remainingTime -= runTime;
        currentTime += runTime;
        if (processes[minIndex].remainingTime == 0) {
            processes[minIndex].isCompleted = true;
            avgWaitTime += currentTime - processes[minIndex].arrivalTime - processes[minIndex].burstTime;
            avgTurnAroundTime += currentTime - processes[minIndex].arrivalTime;
            completed++;
        }
    }
    cout << endl;
    avgWaitTime /= processes.size();
    avgTurnAroundTime /= processes.size();
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes;
    processes.reserve(n);

    cout << "Enter burst times: ";
    for (int i = 0; i < n; i++) {
        int burstTime;
        cin >> burstTime;
        processes.emplace_back(i, 0, burstTime);
    }

    cout << "Enter arrival times: ";
    for (int i = 0; i < n; i++) {
        int arrivalTime;
        cin >> arrivalTime;
        processes[i].arrivalTime = arrivalTime;
    }

    double avgWaitTime, avgTurnAroundTime;
    srt(processes, avgWaitTime, avgTurnAroundTime);

    cout << "Average Waiting Time: " << avgWaitTime << endl;
    cout << "Average Turnaround Time: " << avgTurnAroundTime << endl;

    return 0;
}
