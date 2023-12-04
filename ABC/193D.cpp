#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int K; cin >> K;
    string takahashi, aoki; cin >> takahashi >> aoki;

    vector<int> card(10, K);
    for(int i = 0; i < 4; i++){
        int ns = takahashi[i] - '0';
        int nt = aoki[i] - '0';

        card[ns]--;
        card[nt]--;
    }

    auto score = [](string S) -> int {
        vector<int> cnt(10, 0);
        for(int i = 0; i < S.size(); i++){
            cnt[S[i] - '0']++;
        }

        int ret = 0;
        for(int i = 1; i < 10; i++){
            ret += (i * powl(10, cnt[i]));
        }

        return ret;
    };

    double P = 0.0;
    double denom = (double)(9*K-8)*(9*K-9);
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            // iから先に決める
            string S = takahashi;
            string T = aoki;

            S[4] = '0'+i;
            T[4] = '0'+j;

            auto C = card;
            C[i]--;
            C[j]--;
            if(C[i] < 0 || C[j] < 0) continue;

            if(score(S) > score(T)){
                if(i==j){
                    P += ( (double)card[i] * (card[j]-1) ) / denom;
                    fprintf(stderr, "bunshi = %.5lf, bunbo = %.5lf\n", (double)card[i] * (card[j]-1), denom);

                }else{
                    P += ( (double)card[i] * card[j] ) / denom;
                    fprintf(stderr, "bunshi = %.5lf, bunbo = %.5lf\n", (double)card[i] * card[j], denom);

                }
            }
        }
    }

    cout << fixed << setprecision(10) << P << endl;
    return 0;
}