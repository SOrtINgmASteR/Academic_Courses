// Bresenham Line Drawing
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> line;
vector<int> decision_p;

void bresenham_coordinates(int x0, int y0, int x1, int y1){
    int dx = x1 - x0;
    int dy = y1 - y0;
    int p = (2 * dy) - dx;
    int current_x = x0;
    int current_y = y0;
    line.push_back({current_x, current_y});
    decision_p.push_back(p);
    while(current_x < x1){
        current_x++;
        if(p < 0){
            p += 2 * dy;
        }
        else if(p >= 0){
            current_y++;
            p += ((2 * dy) - (2 * dx));
        }
        line.push_back({current_x, current_y});
        decision_p.push_back(p);
    }
}


int main (){
    cout << "The coordinates of the line are: " << endl;
    bresenham_coordinates(20, 10, 30, 18);
    for(int i = 0; i < line.size(); i++){
        cout << "K: " << i << " P: " << decision_p[i] << " Coordinate: ";
        cout << "(" << line[i].first << ", " << line[i].second << ")" << endl;
    }   
    return 0;
}