#include <bits/stdc++.h>
using namespace std;

double f(double x){
    return pow(x, 3) + x;
}

int main(){
    int N;
    cin >> N;
    
    double ok = 100.0;
    double ng = 0.0;
    while(abs(f(ok) - N) > 0.001){
        double mid = (ok+ng)/2;
        
        if(f(mid) < N){
            ng = mid;
        
        }else{
            ok = mid;

        }

    }

    cout << fixed << setprecision(10) << ok << endl;
    return 0;
}