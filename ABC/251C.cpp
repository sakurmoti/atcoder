#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    set<string> dic;
    int ans=0;
    int index=0;
    for(int i = 0; i < N; i++){
        string s;
        int t;
        cin >> s >> t;

        if(dic.count(s)){
            //出現済みなので操作しない
        
        }else{
            //出現していないので更新できる
            if(ans < t){
                ans = t;
                index = i+1;
            }
        }

        dic.insert(s);
    }

    cout << index << endl;

    return 0;
}