#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N,C; cin >> N >> C;
    
    vector<pair<ll, ll>> event;
    for(int i = 0; i < N; i++){
        int a,b,c;
        cin >> a >> b >> c;

        event.push_back(make_pair(a,  c));
        event.push_back(make_pair(b+1, -c));
    }
    
    sort(event.begin(), event.end());

    ll sum = 0;
    ll service = 0; //1日の利用料金
    for(int i = 0; i < event.size()-1; i++){
        service += event[i].second;

        ll day = (event[i+1].first - event[i].first);
        if(service < C){
            sum += service * day;
        }else{
            sum += C * day;
        }
    }

    cout << sum << endl;
    return 0;
}