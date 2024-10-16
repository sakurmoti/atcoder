#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x,y; Point(){}; Point(int _x, int _y):x(_x),y(_y){}};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,S,T; cin >> N >> S >> T;
    vector<pair<Point, Point>> V(N);
    for(int i = 0; i < N; i++){
        int A,B,C,D; cin >> A >> B >> C >> D;
        V[i] = make_pair(Point(A,B), Point(C,D));
    }

    // N本の順番 * どちらの端点から始めるか
    vector<int> perm(N, 0);
    iota(ALL(perm), 0);
    
    double ans = 1e9;
    do{
        for(int b = 0; b < (1<<N); b++){
            bitset<10> bits(b); // 1が立ったら後ろから
            double time = 0.0;
            Point now(0,0);
            for(int i = 0; i < N; i++){
                if(!bits.test(i)){
                    // nowから初めの位置へ
                    int lx = abs(V[perm[i]].first.x - now.x);
                    int ly = abs(V[perm[i]].first.y - now.y);
                    time += sqrtl(lx*lx + ly*ly) / S;

                    // 初めの位置から終わりの位置へ
                    lx = abs(V[perm[i]].second.x - V[perm[i]].first.x);
                    ly = abs(V[perm[i]].second.y - V[perm[i]].first.y);
                    time += sqrtl(lx*lx + ly*ly) / T;

                    now = Point(V[perm[i]].second.x, V[perm[i]].second.y);

                }else{
                    int lx = abs(V[perm[i]].second.x - now.x);
                    int ly = abs(V[perm[i]].second.y - now.y);
                    time += sqrtl(lx*lx + ly*ly) / S;

                    lx = abs(V[perm[i]].first.x - V[perm[i]].second.x);
                    ly = abs(V[perm[i]].first.y - V[perm[i]].second.y);
                    time += sqrtl(lx*lx + ly*ly) / T;
                
                    now = Point(V[perm[i]].first.x, V[perm[i]].first.y);
                }

            }

            chmin(ans, time);
        }

    }while(next_permutation(ALL(perm)));


    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}