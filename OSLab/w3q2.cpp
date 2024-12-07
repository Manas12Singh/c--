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
    bool isCompleted;

    Process(int id, int arrivalTime, int burstTime)
        : id(id), arrivalTime(arrivalTime), burstTime(burstTime), isCompleted(false) {}
};

bool compare(const Process &a, const Process &b)
{
    return a.arrivalTime < b.arrivalTime;
}

void sjf(vector<Process> &processes, double &avgWaitTime, double &avgTurnAroundTime)
{
    sort(processes.begin(), processes.end(), compare);
    avgWaitTime = 0;
    avgTurnAroundTime = 0;
    int currentTime = processes[0].arrivalTime;
    cout << "Gantt Chart: ";
    for (size_t i = 0; i < processes.size(); i++)
    {
        int m = -1;
        size_t j;
        for (j = 0; j < processes.size() && processes[j].arrivalTime <= currentTime; j++)
        {
            if (!processes[j].isCompleted && (m == -1 || processes[j].burstTime < processes[m].burstTime))
                m = j;
        }
        if (m == -1)
        {
            currentTime = processes[j].arrivalTime;
            i--;
            continue;
        }
        cout << "P" << processes[m].id << " ";
        currentTime = max(currentTime, processes[m].arrivalTime);
        avgWaitTime += currentTime - processes[m].arrivalTime;
        avgTurnAroundTime += currentTime - processes[m].arrivalTime + processes[m].burstTime;
        currentTime += processes[m].burstTime;
        processes[m].isCompleted = true;
    }
    cout << endl;
    avgWaitTime /= processes.size();
    avgTurnAroundTime /= processes.size();
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
    sjf(processes, avgWaitTime, avgTurnAroundTime);

    cout << "Average Waiting Time: " << avgWaitTime << endl;
    cout << "Average Turnaround Time: " << avgTurnAroundTime << endl;

    return 0;
}
