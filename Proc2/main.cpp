#include <fstream>
#include <queue>
#include <utility>
#include <tuple>
#include <algorithm>

typedef std::pair<int, int> TP;

using namespace std;

const int MAX_M = 100000;

tuple<int, int, int> proc[MAX_M];
int solution[MAX_M];
priority_queue<TP, vector<TP>, greater<TP>> becomesAvailable;
priority_queue<int, vector<int>, greater<int>> availableCPU;

int main()
{
    int n, m;
    ifstream fin("proc2.in");
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        fin >> get<0>(proc[i]) >> get<1>(proc[i]);
        get<2>(proc[i]) = i;
    }
    fin.close();

    sort(proc, proc + m);

    for (int i = 0; i < n; i++)
        availableCPU.push(i);

    for (int i = 0; i < m; i++)
    {
        tuple<int, int, int> pr = proc[i];

        while (!becomesAvailable.empty() && becomesAvailable.top().first <= get<0>(pr))
        {
            availableCPU.push(becomesAvailable.top().second);
            becomesAvailable.pop();
        }

        solution[get<2>(pr)] = availableCPU.top();
        availableCPU.pop();
        becomesAvailable.push(make_pair(get<0>(pr) + get<1>(pr), solution[get<2>(pr)]));
    }

    ofstream fout("proc2.out");
    for (int i = 0; i < m; i++)
        fout << solution[i] + 1 << "\n";
    fout.close();

    return 0;
}