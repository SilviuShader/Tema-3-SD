#include <fstream>
#include <utility>
#include <iostream>

using namespace std;

const int MAX_N = 5000010;

pair<int, int> deq[MAX_N];

int main()
{
    ifstream fin("deque.in");
    
    int n, k;
    fin >> n >> k;

    int front = 0;
    int back = -1;
    int64_t sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        int val;
        fin >> val;
        while (back >= 0 && front <= back && deq[back].second > val)
            back--;
        deq[++back] = make_pair(i, val);
        if (i >= k - 1)
        {
            while (deq[front].first < i - (k - 1))
                front++;
            int64_t min = deq[front].second;
            sum += min;
        }
    }
    fin.close();

    ofstream fout("deque.out");
    fout << sum;
    fout.close();

    return 0;
}