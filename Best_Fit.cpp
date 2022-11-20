#include <bits/stdc++.h>
using namespace std;

int main()
{

    int fragment[20], b[20], p[20], i, j, nb, np, temp, lowest = INT_MAX;
    int barray[20], parray[20];

    cout << "Enter the number of blocks" << endl;
    cin >> nb;
    cout << "Enter the number of processes" << endl;
    cin >> np;
    cout << "Enter the size of block" << endl;
    for (i = 0; i < nb; i++)
        cin >> b[i];

    cout << "Enter the size of processes" << endl;
    for (i = 0; i < np; i++)
        cin >> p[i];

    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nb; j++)
        {
            if (barray[j] != 1)
            {
                temp = b[j] - p[i];
                if (temp >= 0)
                    if (lowest > temp)
                    {
                        parray[i] = j;
                        lowest = temp;
                    }
            }
        }

        fragment[i] = lowest;
        barray[parray[i]] = 1;
        lowest = INT_MAX;
    }

    cout << "Process_No\tProcess_Size\tBlock_No\tBlock_Size\tFragment" << endl;
    for (i = 0; i < np && parray[i] != 0; i++)
        cout << i + 1 << "\t\t" << p[i] << "\t\t" << parray[i] << "\t\t" << b[parray[i]] << "\t\t" << fragment[i] << endl;

    return 0;
}
