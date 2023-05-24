#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N;
    string S;
    cin >> N >> S;

    vector<int> cnt;
    int buf = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'o'){
            buf++;
        
        }else{
            cnt.push_back(buf);
            buf = 0;
        }
    }
    cnt.push_back(buf);

    sort(cnt.begin(), cnt.end());

    int size = cnt.size();
    if(cnt.at(size-1) == N || cnt.at(size-1) == 0){
        cout << -1 << endl;
    
    }else{
        cout << cnt.at(size-1) << endl;
    }
    return 0;
}