#include <fstream>
#include <vector>

using namespace std;

const int MOD = 666013;

vector<int> hashMap[MOD];

vector<int>::iterator Find(int x)
{
    int md = x % MOD;
    for (vector<int>::iterator it = hashMap[md].begin(); it != hashMap[md].end(); ++it)
        if (*it == x)
            return it;

    return hashMap[md].end();
}

int main()
{
    ifstream fin("hashuri.in");
    ofstream fout("hashuri.out");

    int n;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        int op, x;
        fin >> op >> x;

        switch (op)
        {
        case 1:
            if (Find(x) == hashMap[x % MOD].end())
                hashMap[x % MOD].push_back(x);
            break;
        case 2:
        {
            vector<int>::iterator it = Find(x);
            if (it != hashMap[x % MOD].end())
            {
                *it = hashMap[x % MOD][hashMap[x % MOD].size() - 1];
                hashMap[x % MOD].pop_back();
            }
        }
            break;
        case 3:
            fout << (Find(x) != hashMap[x % MOD].end()) << "\n";
            break;
        }
    }

    fout.close();
    fin.close();

    return 0;
}