#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int bt;
    int priority;
};

bool comparison(process a, process b)
{
    return (a.priority > b.priority);
}

void findWT(process proc[], int n, int wt[])
{
    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = proc[i - 1].bt + wt[i - 1];
}

void findTAT(process proc[], int n, int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findAvg(process proc[], int n)
{
    int wt[100], tat[100], total_wt = 0, total_tat = 0;

    findWT(proc, n, wt);
    findTAT(proc, n, wt, tat);

    cout << "Process\tBT\tWT\tTAT" << endl;

    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];

        cout << proc[i].pid << "\t" << proc[i].bt << "\t" << wt[i] << "\t" << tat[i] << endl;
    }

    cout << "Avg WT: " << (float)total_wt / n << endl;
    cout << "Avg TAT: " << (float)total_tat / n << endl;
}

void PriorityScheduling(process proc[], int n)
{
    sort(proc, proc + n, comparison);

    cout << "Processes get executed as: " << endl;

    for (int i = 0; i < n; i++)
        cout << proc[i].pid << " ";

    cout << endl;
    findAvg(proc, n);
}

int main()
{
    process proc[] = {{1, 10, 2}, {2, 5, 0}, {3, 8, 1}};
    int n = sizeof proc / sizeof proc[0];
    PriorityScheduling(proc, n);
    return 0;
}
