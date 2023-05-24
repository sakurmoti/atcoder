#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    string S,T;
    cin >> S >> T;

    //少なくともN回消して、最後にTと同じ文字を挿入すれば一致する
    //Sの部分列(あるところから最後まで)　と　Tの部分列(最初からあるところまで)　の共通部分列が最も長いのを求めればよい
    //そこでdp[i]をSを後ろからi文字目まで、Tを前からi文字目まで見たときの共通部分列の長さとする
    vector<int> dp(N+1,0);
    deque<char> s,t;
    for(int i = 0; i < N; i++){
        s.push_front(S.at(S.size()-1-i));
        t.push_back(T.at(i));

        if(s.front() == t.front() && s.back() == t.back() && (dp.at(i) >= 0 || i == 1)){
            dp.at(i+1) = i+1;
        
        }else if(s.front() != t.front() && s.back() != t.back()){
            dp.at(i+1) = -1;

        }else{
            dp.at(i+1) = 0;
            
        }

        //cout << dp.at(i) << endl;
    }

    int M = *max_element(dp.begin(), dp.end());
    sort(S.begin(), S.end());
    sort(T.begin(), T.end());

    if(S == T){
        cout << N - M << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}