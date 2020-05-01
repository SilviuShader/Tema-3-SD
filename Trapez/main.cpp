#include <fstream>
#include <utility>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int GCD(int a, int b)
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
    int n;
    ifstream fin("trapez.in");
    fin >> n;
    pair<int, int>* coords = new pair<int, int>[n];
    for (int i = 0; i < n; i++)
    {
        pair<int, int> crt;
        fin >> crt.first >> crt.second;
        coords[i] = crt;
    }
    fin.close();

    vector<pair<int, int> > slopes;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dx = coords[i].first - coords[j].first;
            int dy = coords[i].second - coords[j].second;

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

            pair<int, int> vec = make_pair(dx, dy);

            slopes.push_back(vec);
        }
    }

    delete[] coords;
    coords = NULL;

    int result = 0;

    sort(slopes.begin(), slopes.end());

    pair<int, int> prevSlope = make_pair(0, 0); 
    int cnt = 0;

    for (int i = 0; i < slopes.size(); i++)
    {
        if (slopes[i] == prevSlope)
            cnt++;
        else
        {
            result += cnt * (cnt + 1) / 2;
            cnt = 0;
        }
        prevSlope = slopes[i];
    }
    result += cnt * (cnt + 1) / 2;

    ofstream fout("trapez.out");
    fout << result;
    fout.close();

    return 0;
}