#include <fstream>
#include <iostream>

const int MAX_P = 1 << 30;

using namespace std;

inline int ZeroCount(int n) 
{
    int result = 0;
    for (int i = 5; n / i >= 1; i *= 5)
        result += n / i;

    return result;
}

int main()
{
    int p;
    ifstream fin("fact.in");
    fin >> p;
    fin.close();

    int n = MAX_P;
    for (int i = MAX_P; i > 0; i >>= 1)
        if (n >= i)
            if (ZeroCount(n - i) >= p)
                n -= i;

    ofstream fout("fact.out");

    if (n == 0)
        n = 1;

    if (ZeroCount(n) == p)
        fout << n;
    else
        fout << -1;

    fout.close();

    return 0;
}