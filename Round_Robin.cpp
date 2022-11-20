#include <bits/stdc++.h>
using namespace std;

void findWT(int processes[], int n, int bt[], int wt[], int quantum)
{
    int rem_bt[100];

    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int t = 0;

    while (1)
    {
        bool done = true;

        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false;

                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }

                else
                {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (done == true)
            break;
    }
}

void findTAT(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAvg(int processes[], int n, int bt[], int quantum)
{
    int wt[100], tat[100], total_wt = 0, total_tat = 0;

    findWT(processes, n, bt, wt, quantum);
    findTAT(processes, n, bt, wt, tat);

    cout << "PN\tBT\tWT\tTAT" << endl;

    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];

        cout << i + 1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
    }

    cout << "Avg WT: " << (float)total_wt / n << endl;
    cout << "Avg TAT: " << (float)total_tat / n << endl;
}

int main()
{
    int processes[] = {1, 2, 3};

    int n = sizeof processes / sizeof processes[0];

    int burst_time[] = {10, 5, 8};

    int quantum = 2;

    findAvg(processes, n, burst_time, quantum);
    return 0;
}
