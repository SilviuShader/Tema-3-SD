#include <fstream>
#include <iostream>

using namespace std;

const int MAX_N = 200005;

pair<int, int> hp[MAX_N];
int heapCount = 0;
int positions[MAX_N];

void Percolate(int pos)
{
    if (pos >= 1)
    {
        int prevP = pos >> 1;
        if (prevP >= 1)
            if (hp[pos] < hp[prevP])
            {
                swap(hp[pos], hp[prevP]);
                positions[hp[prevP].second] = prevP;
                positions[hp[pos].second] = pos;
                Percolate(prevP);
            }
    }
}

void SiftDown(int pos)
{
    if (pos <= heapCount)
    {
        int leftChild = pos << 1;
        int rightChild = leftChild + 1;
        int minIx = pos;

        if (leftChild <= heapCount)
        {
            if (hp[minIx] > hp[leftChild])
                minIx = leftChild;
            if (rightChild <= heapCount)
                if (hp[minIx] > hp[rightChild])
                    minIx = rightChild;
        }

        if (minIx != pos)
            swap(hp[pos], hp[minIx]);
        
        positions[hp[minIx].second] = minIx;
        positions[hp[pos].second] = pos;

         if (minIx!=pos)
            SiftDown(minIx);
    }
}

void Remove(int pos)
{
    hp[pos] = hp[heapCount];
    positions[hp[pos].second] = pos;
    heapCount--;
    Percolate(pos);
    SiftDown(pos);
}

void Insert(int x, int ix)
{
    hp[++heapCount] = make_pair(x, ix);
    positions[ix] = heapCount;
    Percolate(heapCount);
}

int main()
{
    ifstream fin("heapuri.in");
    ofstream fout("heapuri.out");
    int n;
    fin >> n;
    int addCount = 0;
    for (int i = 0; i < n; i++)
    {
        int op;
        fin >> op;
        switch (op)
        {
        case 1:
        {
            int x;
            fin >> x;
            Insert(x, ++addCount);
        }
            break;
        case 2:
        {
            int x;
            fin >> x;
            Remove(positions[x]);
        }
            break;
        case 3:
            fout << hp[1].first << "\n";
            break;
        }
    }
    fout.close();
    fin.close();

    return 0;
}