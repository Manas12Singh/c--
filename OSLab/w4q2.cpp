#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process {
public:
    int id;
    int arrivalTime;
    int burstTime;
    int type;

    Process(int id, int arrivalTime, int burstTime, int type)
        : id(id), arrivalTime(arrivalTime), burstTime(burstTime), type(type) {}
};

bool compareArrival(const Process &a, const Process &b) {
    return a.arrivalTime < b.arrivalTime;
}

class Scheduler {
public:
    static void multiLevel(vector<Process> &processes, double &avgWaitTime, double &avgTurnAroundTime) {
        sort(processes.begin(), processes.end(), compareArrival);
        avgWaitTime = 0;
        avgTurnAroundTime = 0;
        int currentTime = processes[0].arrivalTime;
        int i = 0, j = 0;
        int prev = -1;
        cout << "Gantt Chart: ";
        while (i < processes.size() || j < processes.size()) {
            while (i < processes.size() && processes[i].arrivalTime <= currentTime) {
                if (processes[i].type == 0)
                    break;
                i++;
            }
            while (j < processes.size() && processes[j].arrivalTime <= currentTime) {
                if (processes[j].type == 1)
                    break;
                j++;
            }
            if (i < processes.size() && processes[i].arrivalTime <= currentTime) {
                if (prev != processes[i].id) {
                    cout << "P" << processes[i].id << " ";
                    prev = processes[i].id;
                }
                currentTime = max(currentTime, processes[i].arrivalTime);
                currentTime += processes[i].burstTime;
                avgWaitTime += currentTime - processes[i].arrivalTime - processes[i].burstTime;
                avgTurnAroundTime += currentTime - processes[i].arrivalTime;
                i++;
            } else if (j < processes.size() && processes[j].arrivalTime <= currentTime) {
                if (prev != processes[j].id) {
                    cout << "P" << processes[j].id << " ";
                    prev = processes[j].id;
                }
                currentTime += processes[j].burstTime;
                avgWaitTime += currentTime - processes[j].arrivalTime - processes[j].burstTime;
                avgTurnAroundTime += currentTime - processes[j].arrivalTime;
                j++;
            }
        }
        cout << endl;
        avgWaitTime /= processes.size();
        avgTurnAroundTime /= processes.size();
    }
};

int main() {
    int n, sys, temp;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> processes;
    cout << "Enter burst times: ";
    for (int i = 0; i < n; i++) {
        int burstTime;
        cin >> burstTime;
        processes.emplace_back(i, 0, burstTime, 1);
    }
    cout << "Enter arrival times: ";
    for (int i = 0; i < n; i++) {
        int arrivalTime;
        cin >> arrivalTime;
        processes[i].arrivalTime = arrivalTime;
    }
    cout << "Enter no of system processes: ";
    cin >> sys;
    cout << "Enter System process : ";
    for (int i = 0; i < sys; i++) {
        cin >> temp;
        processes[temp].type = 0;
    }
    double avgWaitTime, avgTurnAroundTime;
    Scheduler::multiLevel(processes, avgWaitTime, avgTurnAroundTime);
    cout << "Average Waiting Time: " << avgWaitTime << endl;
    cout << "Average Turnaround Time: " << avgTurnAroundTime << endl;
    return 0;
}
