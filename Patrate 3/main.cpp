#include <iostream>
#include <fstream>
#include <set>
#include <cmath>

using namespace std;

const double EPSILON = 1e-5;

struct Point 
{
    double x;
    double y;

    Point(double tx, double ty) : x(tx), y(ty) {}

    bool operator<(const Point& other) const
    {
        if (abs(other.x - x) <= EPSILON)
            return y < other.y - EPSILON;
        return x < other.x - EPSILON;
    }
};

int main()
{
    ifstream fin("patrate3.in");
    
    int n;
    int result = 0;
    fin >> n;

    set<Point> points;

    for (int i = 0; i < n; i++)
    {
        double x, y;
        fin >> x >> y;
        points.insert(Point(x, y));
    }

    fin.close();

    for (auto& a : points)
    {
        for (auto& c : points)
        {
            if (a.x < c.x && a.y < c.y)
            {
                Point mid = Point((a.x + c.x) / 2.0, (a.y + c.y) / 2.0);
                Point vecT = Point(mid.x - c.x, mid.y - c.y);
                vecT = Point(vecT.y, -vecT.x);
                Point b(mid.x + vecT.x, mid.y + vecT.y);
                Point d(mid.x - vecT.x, mid.y - vecT.y);

                if (points.find(b) != points.end() &&
                    points.find(d) != points.end())
                    result++;
            }
        }
    }
    
    ofstream fout("patrate3.out");
    fout << result;
    fout.close();
    
    return 0;
}