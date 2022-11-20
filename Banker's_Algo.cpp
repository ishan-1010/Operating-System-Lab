#include <bits/stdc++.h>
using namespace std;

const int P = 5;
const int R = 3;

void Needed(int need[P][R], int max[P][R], int alloc[P][R])
{
    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < R; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

bool isSafe(int processes[], int avail[], int max[][R], int alloc[][R])
{
    int need[P][R];

    Needed(need, max, alloc);

    bool finish[P] = {0};
    int safeSeq[P];
    int work[R];

    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    int count = 0;

    while (count < P)
    {
        bool found = false;
        for (int p = 0; p < P; p++)
        {
            if (finish[p] == 0)
            {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;

                if (j == R)
                {
                    for (int k = 0; k < R; k++)
                        work[k] += alloc[p][k];

                    safeSeq[count++] = p;

                    finish[p] = 1;

                    found = true;
                }
            }
        }

        if (found == false)
        {
            cout << "System is not in safe state" << endl;
            break;
        }
    }

    cout << "System is in safe state" << endl;
    for (int i = 0; i < P; i++)
        cout << safeSeq[i] << " ";

    return true;
}

int main()
{

    int processes[] = {0, 1, 2, 3, 4};

    int avail[] = {3, 3, 2};

    int max[][R] = {{7, 5, 3},
                    {3, 2, 2},
                    {9, 0, 2},
                    {2, 2, 2},
                    {4, 3, 3}};

    int alloc[][R] = {{0, 1, 0},
                      {2, 0, 0},
                      {3, 0, 2},
                      {2, 1, 1},
                      {0, 0, 2}};

    isSafe(processes, avail, max, alloc);

    return 0;
}
