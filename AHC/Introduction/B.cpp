#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

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
                score -= C[j] * (i - last[j]);
            }

            cout << score << endl;
        }
        return score;
    }

    void solve(){
        for(int d = 1; d <= D; d++){
            int idx = 0;
            int score = -1;
            for(int i = 1; i <= C_TYPE; i++){
                T[d] = i;

                int gS = this->getScore();
                if(score < gS){
                    score = gS;
                    idx = i;
                }
            }

            T[d] = idx;
        }
    }
    
    void result(){
        for(int i = 1; i <= C_TYPE; i++){
            cout << T[i] << endl;
        }
    }
};

int main(){
    // #ifdef __LOCAL__
    //     string seed = "0000";
    //     ifstream ifs("input/" + seed + ".txt");
    //     cin.rdbuf(ifs.rdbuf());
    //     ofstream ofs("output/" + seed + ".txt");
    //     cout.rdbuf(ofs.rdbuf());
    // #endif

    int D; cin >> D;
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

    vector<int> ans(D+1);
    for(int i = 1; i <= D; i++){
        cin >> ans[i];
    }

    Solver solver(D,c,s);
    solver.setAns(ans);

    solver.getScore();
    return 0;
}