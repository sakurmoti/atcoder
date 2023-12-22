#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    auto B = A;
    sort(ALL(B));
    B.erase(unique(ALL(B)), B.end());

    vector<int> zip;
    for(int i = 0; i < N; i++){
        int idx = lower_bound(ALL(B), A[i]) - B.begin();
        zip.push_back(idx);
    }

    for(int _i = 0; _i < zip.size(); _i++){
        cout << zip[_i] << " \n"[_i == zip.size()-1];
    }
    return 0;
}