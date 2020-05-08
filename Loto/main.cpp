#include <fstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Sum
{
// If I were at the OOP exam I would've failed for declaing those public variables.
public:

    int x;
    int y;
    int z;

public:

    Sum(int tx = 0, int ty = 0, int tz = 0) : x(tx), y(ty), z(tz) {}
};

const int MAX_N = 105;

int v[MAX_N];
unordered_map<int, Sum> sums;

int main()
{
    ifstream fin("loto.in");
    int n, s;
    fin >> n >> s;
    for (int i = 0; i < n; i++)
        fin >> v[i];
    fin.close();

    sort(v, v + n);

    ofstream fout("loto.out");

    bool done = false;

    for (int i = 0; i < n && !done; i++)
    {
        for (int j = i; j < n && !done; j++)
        {
            for (int k = j; k < n && !done; k++)
            {
                int sum = v[i] + v[j] + v[k];
                if (sums.find(sum) == sums.end())
                    sums[sum] = Sum(v[i], v[j], v[k]);
                
                if (sums.find(s - sum) != sums.end())
                {
                    Sum other = sums[s - sum];
                    fout << v[i] << " " << v[j] << " " << v[k] << " " << other.x << " " << other.y << " " << other.z;
                    done = true;
                }
            }
        }
    }

    if (!done)
        fout << -1;

    fout.close();

    return 0;
}