#include <fstream>
#include <time.h>

using namespace std;

void QuickSort(uint32_t* v, int n)
{
    if (n <= 1)
        return;

    int i = 0;
    int j = n - 1;
    int pIx = rand() % n;
    uint32_t pivot = v[pIx];

    while (i <= j)
    {
        while (v[i] < pivot)
            i++;

        while (v[j] > pivot)
            j--;

        if (i <= j)
        {
            uint32_t tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;

            i++;
            j--;
        }
    }

    int left = 0;
    int right = n - 1;

    if (left < j)
        QuickSort(v + left, j - left + 1);
    if (i < right)
        QuickSort(v + i, n - i);
}

int main()
{
    srand(time(NULL));
    int n;
    ifstream fin("algsort.in");
    fin >> n;

    uint32_t* v = new uint32_t[n];
    for (int i = 0; i < n; i++)
        fin >> v[i];

    fin.close();

    QuickSort(v, n);

    ofstream fout("algsort.out");
    for (int i = 0; i < n; i++)
        fout << v[i] << " ";
    fout.close();

    delete[] v;
    v = NULL;

    return 0;
}