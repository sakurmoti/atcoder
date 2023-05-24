#include <bits/stdc++.h>
using namespace std;

template <typename T>
void chmax(T &a, T b){
    if(a < b) a = b;
}

struct point{
    int x;
    int y;
};

int main(){
    int N;
    cin >> N;

    vector<point> p(N);
    for(int i = 0; i < N; i++){
        cin >> p.at(i).x >> p.at(i).y;
    }

    double M = 0.0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            chmax(M, sqrt((p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y)));
        }
    }

    cout << M << endl;
    return 0;
}