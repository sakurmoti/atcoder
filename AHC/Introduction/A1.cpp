#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()


// 貪欲解法
struct Solver{
    int D;
    vector<int> C;
    vector<vector<int>> S;
    vector<int> T;

    const int C_TYPE = 26;

    Solver(int d, vector<int> c, vector<vector<int>> s)
    : D(d), C(c), S(s) {
        T.resize(D+1, -1);
    }
    
    void setAns(vector<int> &t){
        T = t;
    }

    ll getScore(){
        ll score = 0;
        vector<int> last(C_TYPE+1, 0);
        for(int i = 1; i <= D; i++){
            if(T[i] < 0) break;

            score += S[i][T[i]];
            last[T[i]] = i;

            for(int j = 1; j <= C_TYPE; j++){
                score -= (ll)C[j] * (i - last[j]);
            }

            // cout << i << " : " << score << endl;
        }
        return score;
    }

    void solve(){
        for(int d = 1; d <= D; d++){
            int idx = 0;
            ll score = -1e18;
            for(int i = 1; i <= C_TYPE; i++){
                T[d] = i;
                ll gS = getScore();
                if(score < gS){
                    score = gS;
                    idx = i;
                }
            }

            T[d] = idx;
        }
    }
    
    void result(){
        for(int i = 1; i <= D; i++){
            cout << T[i] << endl;
        }
    }
};

int main(){
    // #ifdef __LOCAL__
    //     ifstream ifs("tester/input.txt");
    //     cin.rdbuf(ifs.rdbuf());
    //     ofstream ofs("tester/output.txt");
    //     cout.rdbuf(ofs.rdbuf());
    // #endif

    int D; cin >> D;
    cout << D << endl;
    vector<int> c(27);
    for(int i = 1; i <= 26; i++){
        cin >> c[i];
    }

    vector<vector<int>> s(D+1, vector<int>(27));
    for(int i = 1; i <= D; i++){
        for(int j = 1; j <= 26; j++){
            cin >> s[i][j];
        }
    }

    Solver solver(D,c,s);

    solver.solve();
    solver.result();
    return 0;
}