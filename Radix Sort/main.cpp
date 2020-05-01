#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    unsigned long long n, a, b, c;

    ifstream fin("radixsort.in");
    fin >> n >> a >> b >> c;
    fin.close();

    uint32_t* v = new uint32_t[n];
    v[0] = b;
    for (int i = 1; i < n; i++)
        v[i] = (a * v[i - 1] + b) % c;

    uint32_t* tmp = new uint32_t[n];

    uint32_t* crt = v;
    uint32_t* next = tmp;
    int sz[256];

    for (int i = 0; i < 4; i++)
    {
        memset(sz, 0, sizeof(int) * 256);

        for (int j = 0; j < n; j++)
        {
            int index = (crt[j] >> (8 * i)) & 255;
            sz[index]++;
        }

        for (int j = 1; j < 256; j++)
            sz[j] += sz[j - 1];

        for (int j = n - 1; j >= 0; j--)
        {
            int index = (crt[j] >> (8 * i)) & 255;
            next[--sz[index]] = crt[j];
        }

        uint32_t* t = crt;
        crt = next;
        next = t;
    }

    ofstream fout("radixsort.out");
    
    for (int i = 0; i < n; i += 10)
        fout << crt[i] << " ";
    
    fout.close();

    delete[] v;
    delete[] tmp;

    return 0;
}