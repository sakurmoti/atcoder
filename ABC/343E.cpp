#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int area2(int x1, int y1, int z1, int x2, int y2, int z2){
    int w = min(x1+7, x2+7) - max(x1, x2); // 左端の最大から右端の最小
    int h = min(y1+7, y2+7) - max(y1, y2);
    int d = min(z1+7, z2+7) - max(z1, z2);
    if(w<0 || h<0 || d<0) return 0;
    return h*w*d;
}

int area3(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3){
    int w = min({x1+7, x2+7, x3+7}) - max({x1, x2, x3});
    int h = min({y1+7, y2+7, y3+7}) - max({y1, y2, y3});
    int d = min({z1+7, z2+7, z3+7}) - max({z1, z2, z3});

    if(w<0 || h<0 || d<0) return 0;
    return h*w*d;
}

int main(){
    int V1,V2,V3;
    cin >> V1 >> V2 >> V3;

    // 1個はC(0,0,0)でよい
    int x1=0,y1=0,z1=0;
    int W = 7;
    for(int x2 = -W; x2 <= W; x2++){
        for(int y2 = -W; y2 <= W; y2++){
            for(int z2 = -W; z2 <= W; z2++){
                for(int x3 = -W; x3 <= W; x3++){
                    for(int y3 = -W; y3 <= W; y3++){
                        for(int z3 = -W; z3 <= W; z3++){
                            int u3 = area3(x1,y1,z1,x2,y2,z2,x3,y3,z3);
                            int u2 = area2(x1,y1,z1,x2,y2,z2) + area2(x1,y1,z1,x3,y3,z3) + area2(x2,y2,z2,x3,y3,z3) - 3*u3;
                            int u1 = 3 * W * W * W - 2*u2 - 3*u3;

                            if(u1 == V1 && u2 == V2 && u3 == V3){
                                cout << "Yes" << endl;
                                cout << x1 << " " << y1 << " " << z1 << " ";
                                cout << x2 << " " << y2 << " " << z2 << " ";
                                cout << x3 << " " << y3 << " " << z3 << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << "No" << endl;
    return 0;
}