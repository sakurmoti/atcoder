#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;

    vector<int> A(3*N + 1);
    for(int i = 1; i <= 3*N; i++){
        cin >> A.at(i);
    }

    //ある数字が何回出現したか
    map<int, int> cnt; //キー: 何の値 value:何回出現したか
    vector<int> ans;
    for(int i = 1; i <= 3*N; i++){
        int key = A.at(i);

        cnt[key] ++;
        if(cnt[key] == 2){
            ans.push_back(key);
        }
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << endl;
    }
    return 0;
}