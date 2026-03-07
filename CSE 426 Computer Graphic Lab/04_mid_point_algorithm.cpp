#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> points;

void mid_point_algorithm(int x1, int y1, int r){
    int x = 0;
    int y = r;
    float decision = 5 / 4 - r;
    points.push_back({x, y});
    while (y > x){
        if (decision < 0)
        {
            x++;
            decision += (2 * x) + 3;
        }
        else
        {
            y--;
            x++;
            decision += 2 * (x - y) + 5;
        }
        points.push_back({x, y});
    }
}

int main(){
    mid_point_algorithm(10, 10, 50);
    for(auto p: points){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
