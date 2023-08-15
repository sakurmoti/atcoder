#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N),B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }

    vector<int> login(N), logout(N);
    for(int i = 0; i < N; i++){
        login[i] = A[i]; //プレイヤーiのログインの日
        logout[i] = A[i] + B[i]; //プレイヤーiのログアウトの日
    }
    //プレイヤーの情報は必要ないのでソートしてもよい
    sort(login.begin(), login.end());
    sort(logout.begin(), logout.end());
    //このとき、Y < login[0], logout[-1] <= Zを満たすY, Z日目は誰もログインしていない
    
    //二つを合わせてソートする
    vector<pair<int, int>> X;
    for(int i = 0; i < N; i++){
        X.push_back(make_pair(login[i], 1));
        X.push_back(make_pair(logout[i], -1));
    }
    sort(X.begin(), X.end());
    //このとき、X[k] <= D < X[k+1]で人数の変化はおきない

    vector<int> ans(N+1,0);
    int player = 0;
    for(int i = 0; i < X.size()-1; i++){
        player += X[i].second;
        int day = X[i+1].first - X[i].first; //day日間同じ人数

        ans[player] += day;
    }

    for(int i = 1; i <= N; i++){
        cout << ans[i] << " \n"[i==N];
    }

    return 0;
}