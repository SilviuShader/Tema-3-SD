#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        uint64_t n, k;
        cin >> n >> k;

        bool result = false;
        if (n % 2 == k % 2)
        {
            uint64_t sum = k * k;
                
            if (sum <= n)
                result = true;
        }

        if (result)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}