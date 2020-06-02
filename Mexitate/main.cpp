#include <iostream>
#include <fstream>
#include <vector>

#define MAX_N 400630
#define SQRT 630
#define MOD 1000000007

using namespace std;

const int DISTINCT_SIZE = MAX_N / SQRT;

int n, m, k, l;
vector<vector<int>> v;

int frequency[MAX_N];
int distinct[DISTINCT_SIZE];

void Push(int val)
{
    val--;
 
    if (frequency[val] == 0)
        distinct[val / SQRT]++;

    frequency[val]++;
}

void Pop(int val)
{
    val--;

    frequency[val]--;

    if (frequency[val] == 0)
        distinct[val / SQRT]--;
}

int FindMin()
{
    for (int i = 0; i < DISTINCT_SIZE; i++)
        if (distinct[i] < SQRT)
        {
            for (int j = i * SQRT; j < MAX_N; j++)
                if (!frequency[j])
                    return j + 1;
        }

    return -1;
}

int main()
{
    ifstream fin("mexitate.in");

    long long result = 1;
    
    fin >> n >> m >> k >> l;
    if (k < l)
    {
        v.resize(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int t;
                fin >> t;
                v[i].push_back(t);
            }
        }
    }
    else
    {
        v.resize(m);
        for (int i = 0; i < m; i++)
            v[i].resize(n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                fin >> v[j][i];

        swap(n, m);
        swap(l, k);
    }
    
    fin.close();

    int x = 0;
    for (int line = 0; line <= n - k; line++)
    {
        if (line == 0)
        {
            for (int i = 0; i < k; i++)
                for (int j = 0; j < l; j++)
                    Push(v[i][j]);
        }
        else
        {
            for (int i = x; i < x + l; i++)
                Pop(v[line - 1][i]);
            for (int i = x; i < x + l; i++)
                Push(v[line + k - 1][i]);
        }

        int mn = FindMin();
        result *= mn;
        result %= MOD;

        if (line % 2 == 0)
            x = 1;
        else
            x = m - l - 1;

        while ((x <= m - l && line % 2 == 0) ||
               (x >= 0     && line % 2 == 1))
        {
            if (line % 2 == 0)
            {
                for (int i = 0; i < k; i++)
                    Pop(v[line + i][x - 1]);
                for (int i = 0; i < k; i++)
                    Push(v[line + i][x + l - 1]);

                x++;
            }
            else
            {
                for (int i = 0; i < k; i++)
                    Pop(v[line + i][x + l]);
                for (int i = 0; i < k; i++)
                    Push(v[line + i][x]);

                x--;
            }

            int mn2 = FindMin();
            result *= mn2;
            result %= MOD;
        }

        if (line % 2 == 0)
            x = m - l;
        else
            x = 0;
    }
    
    ofstream fout("mexitate.out");
    fout << result;
    fout.close();

    return 0;
}