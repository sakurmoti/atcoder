#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

constexpr bool LOCAL = false;

struct Point {
    int x;
    int y;

    Point() : x(0), y(0) {}
    Point(int _x, int _y) : x(_x), y(_y) {}
};

struct Judge
{
    int N, M;
    vector<vector<char>> A;
    vector<string> T;
    Point st;
    
    Point now;
    vector<Point> ans;
    string good_str;

    void init(int _N, int _M, vector<vector<char>> _A, vector<string> _T, Point _s){
        N = _N;
        M = _M;
        A = _A;
        T = _T;
        st = _s;
    }

    void solve(){
        good_str = this->make_string();

        now = st;
        for(int i = 0; i < 5*M; i++){
            char c = good_str[i];
            Point p = find_char(c);
            ans.push_back(p);
            now = p;
        }

        this->result();
    }

    string make_string(){
        string ret;
        now = st;
        char prev = A[st.y][st.x];
        vector<bool> used(M, false);

        for(int i = 0; i < M; i++){
            int cost = 1e9;
            int idx = -1;
            for(int j = 0; j < M; j++){
                if(used[j]) continue;
                if(cost > calc_cost(T[j])){
                    cost = calc_cost(T[j]);
                    idx = j;
                }
            }

            if(idx >= 0){
                ret += T[idx];
                used[idx] = true;
                continue;
            }else{
                printf("ERROR: not find idx\n", idx);
                exit(-1);
            }
        }

        // fprintf(stderr, "maked_str =\n%s", ret.c_str());
        return ret;
    }

    int calc_cost(string s){
        int ret = 0;
        for(int i = 0; i < 5; i++){
            Point p = find_char(s[i]);
            ret += abs(now.x - p.x) + abs(now.y - p.y) + 1;
            now = p;
        }
        return ret;
    }

    Point find_char(char c){
        int min_dist = 1e9;
        Point min_p;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(A[i][j] == c){
                    int dist = abs(now.x - j) + abs(now.y - i);
                    if(dist < min_dist){
                        min_dist = dist;
                        min_p = Point(j, i);
                    }
                }
            }
        }
        // printf("\tmin_p=(%d,%d)\n", min_p.x, min_p.y);
        return min_p;
    }

    void result(){
        if(!LOCAL){
            for(auto &v : ans){
                cout << v.y << " " << v.x << endl;
            }
        }else{
            ofstream ofs("output.txt");
            for(auto &v : ans){
                ofs << v.y << " " << v.x << endl;
            }
        }
    }
};


void input(int &N, int &M, Point &s, vector<vector<char>> &A, vector<string> &T){
    if(!LOCAL){
        cin >> N >> M;
        cin >> s.y >> s.x;
        A.resize(N, vector<char>(N));
        for(auto &_v : A) for(auto &_vv : _v) cin >> _vv;
        T.resize(M);
        for(auto &_v : T) cin >> _v;
    }else{
        ifstream ifs("input.txt");
        ifs >> N >> M;
        ifs >> s.y >> s.x;
        A.resize(N, vector<char>(N));
        for(auto &_v : A) for(auto &_vv : _v) ifs >> _vv;
        T.resize(M);
        for(auto &_v : T) ifs >> _v;
    }
}

int main(){
    int N,M;
    Point s;
    vector<vector<char>> A;
    vector<string> T;

    input(N,M,s,A,T);

    Judge judge;
    judge.init(N, M, A, T, s);
    judge.solve();
    return 0;
}