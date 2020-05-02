#include <fstream>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX_N = 1005;
const int MAX_COORD = 20000005;

pair<int, int> flowers[MAX_N];

inline int GCD(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int t;
    ifstream fin("flori2.in");
    ofstream fout("flori2.out");

    fin >> t;
    unordered_map<int64_t, int> mp;

    for (int i = 0; i < t; i++)
    {
        int n;
        fin >> n;

        int result = 0;
        for (int j = 0; j < n; j++)
            fin >> flowers[j].first >> flowers[j].second;

        sort(flowers, flowers + n);

        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int dx = flowers[j].first  - flowers[k].first;
                int dy = flowers[j].second - flowers[k].second;

                int l = GCD(abs(dx), abs(dy));

                dx /= l;
                dy /= l;

                if (dx == 0)
                {
                    if (dy < 0)
                        dy = -dy;
                }
                else
                    if (dx < 0)
                    {
                        dx = -dx;
                        dy = -dy;
                    }

                int64_t key = (int64_t)dy * MAX_COORD + (int64_t)dx;
                if (mp.find(key) == mp.end())
                    mp[key] = 0;
                mp[key]++;

                result = max(result, mp[key]);
            }
            mp.clear();
        }

        fout << result + 1 << endl;
    }

    fout.close();
    fin.close();

    return 0;
}