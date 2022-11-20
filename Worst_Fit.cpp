#include <bits/stdc++.h>
using namespace std;

int main()
{
    int frag[20], b[20], f[20], i, j, nb, nf, temp, highest = 0;
    int bf[20], ff[20];

    cout << "Enter no. of blocks" << endl;
    cin >> nb;
    cout << "Enter no. of process files" << endl;
    cin >> nf;

    cout << "Enter the size of blocks" << endl;
    for (i = 0; i < nb; i++)
        cin >> b[i];

    cout << "Enter the size of process files" << endl;
    for (i = 0; i < nf; i++)
        cin >> f[i];

    for (i = 0; i < nf; i++)
    {
        for (j = 0; j < nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                    if (temp > highest)
                    {
                        ff[i] = j;
                        highest = temp;
                    }
            }
        }

        frag[i] = highest;
        bf[ff[i]] = 1;
        highest = 0;
    }

    cout << "Process_No\tProcess_Size\tBlock_No\tBlock_Size\tFragment" << endl;
    for (i = 0; i < nf; i++)
        cout << i + 1 << "\t\t" << f[i] << "\t\t" << ff[i] + 1 << "\t\t" << b[ff[i]] << "\t\t" << frag[i] << endl;

    return 0;
}
