#include <bits/stdc++.h>
using namespace std;

int main()
{

    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;

    for (i = 0; i < 10; i++)
    {
        flags[i] = 0;
        allocation[i] = -1;
    }

    cout << "Enter no. of blocks" << endl;
    cin >> bno;
    cout << "Enter size of each block" << endl;
    for (i = 0; i < bno; i++)
        cin >> bsize[i];

    cout << "Enter number of processes" << endl;
    cin >> pno;
    cout << "Enter size of each process" << endl;
    for (i = 0; i < pno; i++)
        cin >> psize[i];

    for (i = 0; i < pno; i++)
        for (j = 0; j < bno; j++)
            if (flags[j] == 0 && bsize[j] >= psize[i])
            {
                allocation[j] = i;
                flags[j] = 1;
                break;
            }

    cout << "Block no.\tSize\tProcessNo.\tSize" << endl;
    for (i = 0; i < bno; i++)
    {
        cout << i + 1 << "\t\t" << bsize[i] << "\t\t";
        if (flags[i] == 1)
            cout << allocation[i] + 1 << "\t\t" << psize[allocation[i]] << endl;

        else
            cout << "Not Allocated" << endl;
    }

    return 0;
}
