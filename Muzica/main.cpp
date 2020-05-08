#include <fstream>
#include <vector>

#define MOD 100005

using namespace std;

vector<int> st[MOD];

inline bool Find(int val)
{
    vector<int>& v = st[val % MOD];
    for (auto& it : v)
        if (it == val)
        {
            it = v[v.size() - 1];
            v.pop_back();
            return true;
        }
    return false;
}

int main()
{
    int n, m;
    int result = 0;
    ifstream fin("muzica.in");
    fin >> n >> m;
    int64_t a, b, c, d, e;
    fin >> a >> b >> c >> d >> e;

    for (int i = 0; i < n; i++)
    {
        int track;
        fin >> track;
        st[track % MOD].push_back(track);
    }

    fin.close();
    
    for (int i = 0; i < m; i++)
    {
        int64_t newVal;
        if (i == 0 || i == 1)
        {
            if (i == 0)
                newVal = a;
            else
                newVal = b;
        }
        else
        {
            newVal = (c * b + d * a) % e;
            a = b;
            b = newVal;
        }

        if (Find((int)newVal))
            result++;
    }

    ofstream fout("muzica.out");
    fout << result;
    fout.close();

    return 0;
}