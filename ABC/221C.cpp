#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S; cin >> S;
    int N = S.size();
    const int M = 9;
    
    ll ans = -1;
    for(int i = 0; i < (1<<N); i++){
        bitset<M> bits(i);

        string A,B;
        for(int j = 0; j < M; j++){
            if(bits.test(j)){
                A += S[j];
            }else{
                B += S[j];
            }
        }

        sort(RALL(A));
        sort(RALL(B));

        ll a,b;
        try
        {
            a = stoi(A);
            b = stoi(B);
            ans = max(ans, a*b);
        }
        catch(const std::exception& e){}
    }
    cout << ans << endl;
    return 0;
}