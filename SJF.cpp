#include <bits/stdc++.h>
using namespace std;

int main()
{

    int A[100][4];

    int i, j, n, total = 0, index, temp;
    float avg_wt, avg_tat;

    cout << "Enter no. of processes" << endl;
    cin >> n;

    cout << "Enter Burst Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i][1];
        A[i][0] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        index = i;
        for (j = i + 1; j < n; j++)
            if (A[j][1] < A[index][1])
                index = j;

        swap(A[i][1], A[index][1]);
        swap(A[i][0], A[index][0]);
    }
    A[0][2] = 0;

    for (i = 1; i < n; i++)
    {
        A[i][2] = 0;

        for (j = 0; j < i; j++)
            A[i][2] += A[j][1];

        total += A[i][2];
    }

    avg_wt = (float)total / n;
    total = 0;

    cout << "P\tBT\tWT\tTAT\t" << endl;

    for (i = 0; i < n; i++)
    {
        A[i][3] = A[i][1] + A[i][2];
        total += A[i][3];

        cout << A[i][0] << "\t" << A[i][1] << "\t" << A[i][2] << "\t" << A[i][3] << endl;
    }

    avg_tat = (float)total / n;

    cout << "Avg WT: " << avg_wt << endl;
    cout << "Avg TAT: " << avg_tat << endl;

    return 0;
}
