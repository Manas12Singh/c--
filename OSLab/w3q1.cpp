#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process
{
public:
    int id;
    int arrivalTime;
    int burstTime;

    Process(int id, int arrivalTime, int burstTime)
        : id(id), arrivalTime(arrivalTime), burstTime(burstTime) {}
};

bool compare(const Process &a, const Process &b)
{
    return a.arrivalTime < b.arrivalTime;
}

void fcfs(int n, vector<Process> &processes, double &avgWaitTime, double &avgTurnAroundTime)
{
    sort(processes.begin(), processes.end(), compare);

    avgWaitTime = 0;
    avgTurnAroundTime = 0;
    int currentTime = 0;
    cout << "Gantt Chart: ";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << processes[i].id << " ";
        currentTime = max(currentTime, processes[i].arrivalTime);
        int waitTime = currentTime - processes[i].arrivalTime;
        avgWaitTime += waitTime;
        avgTurnAroundTime += waitTime + processes[i].burstTime;
        currentTime += processes[i].burstTime;
    }
    cout << endl;
    avgWaitTime /= n;
    avgTurnAroundTime /= n;
}

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes;
    processes.reserve(n);

    cout << "Enter burst times: ";
    for (int i = 0; i < n; i++)
    {
        int burstTime;
        cin >> burstTime;
        processes.emplace_back(i, 0, burstTime);
    }

    cout << "Enter arrival times: ";
    for (int i = 0; i < n; i++)
    {
        int arrivalTime;
        cin >> arrivalTime;
        processes[i].arrivalTime = arrivalTime;
    }

    double avgWaitTime, avgTurnAroundTime;
    fcfs(n, processes, avgWaitTime, avgTurnAroundTime);

    cout << "Average Waiting Time: " << avgWaitTime << endl;
    cout << "Average Turnaround Time: " << avgTurnAroundTime << endl;

    return 0;
}
