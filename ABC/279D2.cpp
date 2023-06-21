#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll A,B;
    cin >> A >> B;

    //A/sqrt(g) + B*(g-1)
    auto f = [&](double g){ return (double)A/sqrt(g) + (double)B*(g-1);};
    
    //三分探索
    ll low = 1;
    ll high = A/B;
    
    double eps = 1e-7;
    
    for(int i = 0; i < 1000; i++){
        ll t1 = (2*low + high)/3;
        ll t2 = (low + 2*high)/3;

        if(f(t1) < f(t2)){
            high = t2;
        }else{
            low = t1;
        }

        // printf("low=%d, high=%d, f(t1)=%.6f, f(t2)=%.6f\n", low, high, f(t1), f(t2));
    }

    double ans = f(low);
    for(ll g = low; g <= max(high, 1ll); g++){
        ans = min(ans, f(g));
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}