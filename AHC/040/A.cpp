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

void debug(string s){ cout << "# " << s << endl; }

struct Rect{
    int id;
    int w,h;
    Point p; // 左上を基準とした座標

    Rect():w(0),h(0),id(-1){};
    Rect(int _w, int _h, int _id):w(_w),h(_h),id(_id){}

    void swap(){
        std::swap(w,h);
    }
};

struct Field{
    int N;
    vector<optional<Rect>> boxes;
    Point max;


    Field(int &n) : N(n){
        boxes.assign(N, nullopt);
    }

    
    void set(Rect box, int rot, char dir, int base_idx){
        Rect base;
        if(base_idx < 0){
            if(dir=='U'){
                base.p = {0,max.y};
            }else{
                base.p = {max.x,0};
            }

        }else if(!boxes[base_idx].has_value()){
            debug("base_idx is not valid");
            exit(1);
        }else{
            base = boxes[base_idx].value();
        }

        if(rot==1){
            box.swap();
        }

        if(dir=='U'){
            box.p = {base.p.x, base.p.y + base.h};
            
        }else{
            box.p = {base.p.x + base.w, base.p.y};
        }

    }
};

class Judge{
    vector<Rect> ans;
    vector<pair<int, int>> eps;

    void local_init(int N){
        for(int i = 0; i < N; i++){
            int w,h; cin >> w >> h;
            ans.push_back(Rect(w,h,i));
        }

        for(int i = 0; i < N; i++){
            int dw, dh; cin >> dw >> dh;
            eps.push_back({dw,dh});
        }
    }

    void score(int idx){

    }

};

void solve(){
    int N,T,sd; cin >> N >> T >> sd;
    vector<Rect> A(N);
    for(int i = 0; i < N; i++){
        int w,h; cin >> w >> h;
        A[i] = Rect(w,h,i);
    }

    while(T--){
        
    }


}

int main(){
    #ifndef ONLINE_JUDGE
        for(int seed = 0; seed < 10; seed++){
            stringstream ss;
            ss << setw(4) << setfill('0') << seed;
            ifstream ifs("in/" + ss.str() + ".txt");
            ofstream ofs("out/" + ss.str() + ".txt");
            auto start = chrono::system_clock::now();
            solve();
            auto end = chrono::system_clock::now();
            auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        }
        return 0;
    #endif

    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    solve();
    return 0;
}