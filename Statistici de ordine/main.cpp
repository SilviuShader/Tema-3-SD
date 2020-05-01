#include <fstream>
#include <time.h>

using namespace std;

int Partition(uint32_t* v, int l, int r)
{
    uint32_t x = v[r];
    int i = l;

    for (int j = l; j <= r - 1; j++)
        if (v[j] <= x)
        {
            swap(v[i], v[j]);
            i++;
        }

    swap(v[i], v[r]);

    return i;
}

int RandomPartition(uint32_t* v, int left, int right)
{
    int random = rand() % (right - left + 1) + left;
    swap(v[random], v[right]);

    return Partition(v, left, right);
}

uint32_t QuickSelect(uint32_t* v, int left, int right, int pos)
{
    if (pos > 0 && pos <= right - left + 1)
    {
        int index = RandomPartition(v, left, right);

        if (index - left == pos - 1)
            return v[index];

        if (index - left >= pos - 1)
            return QuickSelect(v, left, index - 1, pos);

        return QuickSelect(v, index + 1, right, pos - index + left - 1);
    }

    return -1;
}

int main()
{
    srand(time(NULL));
    int n, k;
    ifstream fin("sdo.in");
    fin >> n >> k;

    uint32_t* v = new uint32_t[n];
    for (int i = 0; i < n; i++)
        fin >> v[i];

    fin.close();

    ofstream fout("sdo.out");
    fout << QuickSelect(v, 0, n - 1, k);
    fout.close();

    delete[] v;
    v = NULL;

    return 0;
}