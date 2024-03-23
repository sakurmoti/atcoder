#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int Q; cin >> Q;
    
    map<int, int> dict;
    while(Q--){
        int q; cin >> q;

        if(q == 1){
            int x; cin >> x;
            dict[x]++;

        }else if(q == 2){
            int x,c; cin >> x >> c;
            dict[x] -= c;

            if(dict[x] <= 0){
                dict.erase(x);
            }

        }else{
            cout << (prev(dict.end()))->first - (dict.begin())->first << endl;

        }
    }
    return 0;
}