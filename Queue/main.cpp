#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

ifstream fin("queue.in");
ofstream fout("queue.out");

stack<int> s1;
stack<int> s2;

char op[25];

int main()
{
    
    int n;
    fin >> n;
    fin.get();

    for (int i = 0; i < n; i++)
    {
        fin.getline(op, 25);
        if (op[10] == ')')
        {
            fout << i + 1 << ": ";
            if (s2.empty())
            {
                while (s1.size() > 1)
                {
                    int val = s1.top();
                    s2.push(val);
                    s1.pop();

                    fout << "pop(1) push(2," << val << ") ";
                }
                fout << "pop(1) write(" << s1.top() << ")\n";
                s1.pop();
            }
            else
            {
                fout << "pop(2) write(" << s2.top() << ")\n";
                s2.pop();
            }

        }
        else
        {
            int j = 10;
            int nr = 0;
            while ('0' <= op[j] && op[j] <= '9')
            {
                nr = nr * 10 + op[j] - '0';
                j++;
            }
         
            s1.push(nr);
            fout << i + 1 << ": read(" << nr << ") push(1," << nr << ")\n";
        }
    }

    fout.close();
    fin.close();
    return 0;
}