#include <fstream>

using namespace std;

int ToursCount(int* v, int n, int capacity)
{
    int result = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > capacity)
            return -1;
        if (sum + v[i] > capacity)
        {
            sum = v[i];
            result++;
        }
        else
            sum += v[i];
    }

    return result;
}

int main()
{
    int n, k;
    int* v;
    int sum = 0;

    ifstream fin("transport.in");
    fin >> n >> k;
    v = new int[n];
    for (int i = 0; i < n; i++)
    {
        fin >> v[i];
        sum += v[i];
    }
    fin.close();
    
    int capacity = sum;

    for (int i = 1 << 30; i > 0; i >>= 1)
    {
        if (capacity >= i)
        {
            int tours = ToursCount(v, n, capacity - i);

            if (tours <= k && tours != -1)
                capacity -= i;
        }
    }

    ofstream fout("transport.out");
    fout << capacity;
    fout.close();

    delete[] v;
    v = NULL;
    
    return 0;
}