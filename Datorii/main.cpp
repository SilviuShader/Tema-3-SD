#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_N = 15005;
const int TREE_SIZE = MAX_N * 4;

int v[MAX_N];
int tree[TREE_SIZE];

void Build(int node, int left, int right)
{
    if (left == right)
    {
        tree[node] = v[left];
        return;
    }

    int mid = (left + right) >> 1;
    Build(2 * node, left, mid);
    Build(2 * node + 1, mid + 1, right);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int Update(int sum, int node, int day, int left, int right)
{
    if (left == right && left == day)
    {
        if (sum > tree[node])
        {
            int diff = tree[node];
            tree[node] = 0;
            return diff;
        }
        tree[node] -= sum;
        return sum;
    }
    if (day >= left && day <= right)
    {
        int mid = (left + right) >> 1;
        int up = Update(sum, 2 * node, day, left, mid);
        up = max(Update(sum, 2 * node + 1, day, mid + 1, right), up);
        tree[node] -= up;

        return up;
    }

    return 0;
}

int Query(int node, int lf, int rg, int left, int right)
{
    if (left >= lf && right <= rg)
        return tree[node];
    if ((left <= lf && lf <= right) ||
        (left <= rg && rg <= right))
    {
        int mid = (left + right) >> 1;
        int result = Query(node * 2, lf, rg, left, mid);
        result += Query(node * 2 + 1, lf, rg, mid + 1, right);

        return result;
    }

    return 0;
}

int main()
{
    ifstream fin("datorii.in");
    ofstream fout("datorii.out");
    
    int n, m;
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> v[i];

    Build(1, 1, n);

    for (int i = 1; i <= m; i++)
    {
        int op, a, b;
        fin >> op >> a >> b;
        switch (op)
        {
        case 0:
            Update(b, 1, a, 1, n);
            break;
        case 1:
            fout << Query(1, a, b, 1, n) << "\n";
            break;
        }
    }
    
    fout.close();
    fin.close();

    return 0;
}