#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 20;
char digits[MAX_N];

int main()
{
    int n;
    cin >> n;
    cin >> digits;

    vector<char> vec;

    for (int i = 0; i < n; i++)
    {
        switch (digits[i])
        {
        case '2':
            vec.push_back(2);
            break;
        case '3':
            vec.push_back(3);
            break;
        case '4':
            vec.push_back(3);
            vec.push_back(2);
            vec.push_back(2);
            break;
        case '5':
            vec.push_back(5);
            break;
        case '6':
            vec.push_back(5);
            vec.push_back(3);
            break;
        case '7':
            vec.push_back(7);
            break;
        case '8':
            vec.push_back(7);
            vec.push_back(2);
            vec.push_back(2);
            vec.push_back(2);
            break;
        case '9':
            vec.push_back(7);
            vec.push_back(3);
            vec.push_back(3);
            vec.push_back(2);
            break;
        }
    }

    sort(vec.begin(), vec.end(), [](char a, char b) {return a > b; });

    for (int i = 0; i < vec.size(); i++)
        cout << (int)vec[i];

    return 0;
}