#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll N,Q; cin >> N >> Q;

    vector<vector<char>> P(N, vector<char>(N));
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            cin >> P[i][j];
        }
    }

    // (0,0)から(i,j)までの総和
    ll cnt = 0;
    vector<vector<ll>> imos(N, vector<ll>(N, 0));
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(P[i][j] == 'B'){
                imos[i][j] = 1;
                cnt++;
            }
        }
    }

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(i!=0 && j!=0){
                imos[i][j] += (imos[i-1][j] + imos[i][j-1] - imos[i-1][j-1]);
            
            }
            else if(i==0 && j==0);
            else if(i==0) imos[i][j] += imos[i][j-1];
            else if(j==0) imos[i][j] += imos[i-1][j];

            cerr << imos[i][j] << " ";
        }
        cerr << endl;
    }

    for( ; Q > 0; Q--){
        ll A,B,C,D;
        cin >> A >> B >> C >> D;

        ll width = D-B+1;
        ll height = C-A+1;
        cerr << width << " " << height << endl;

        ll w1 = N-B;
        ll w2 = D%N;
        ll h1 = N-A;
        ll h2 = C%N;

        ll gridNum_w = D/N - 1;
        ll gridNum_h = C/N - 1;

        fprintf(stderr, "h1=%d, w1=%d,  h2=%d, w2=%d,  gridNum_h=%d, gridNum_w=%d\n", h1,w1,h2,w2,gridNum_h, gridNum_w);

        ll sum = 0;
        if(D > N && C > N){
            sum += ()

        }else if(D > N){

        }else if(C > N){

        }else{
            cerr << "exception\n";
        }

    }
    return 0;
}