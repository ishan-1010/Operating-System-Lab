#include <bits/stdc++.h>
using namespace std;

void findWT(int processes[], int n, int bt[], int wt[])
{
    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void findTAT(int processes[], int n, int bt[], int wt[], int tat[])
{

    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAVG(int processes[], int n, int bt[])
{
    int wt[100], tat[100], total_wt = 0, total_tat = 0;

    findWT(processes, n, bt, wt);
    findTAT(processes, n, bt, wt, tat);

    cout << "Process\tBurst Time\tWaiting Time\tTurn Around Time (TAT)" << endl;

    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];

        cout << i + 1 << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << "Avg WT: " << (float)total_wt / n << endl;
    cout << "AvgTAT: " << (float)total_tat / n << endl;
}

int main()
{
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
    int bt[] = {10, 5, 8};

    findAVG(processes, n, bt);
    return 0;
}
