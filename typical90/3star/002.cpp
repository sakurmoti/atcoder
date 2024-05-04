#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<string> ans;
    //全探索する
    for(int i = 0; i < (1<<N); i++){ //1<<Nは1をNビット左シフト。つまり2^N
        bitset<20> Q(i);
        string buf = "";
        int count_right=0, count_left=0;
        bool flag=true;

        for(int j = 0; j < N; j++){
            if(Q.test(j)){
                buf += "(";
                count_left++;
            }else{
                buf += ")";
                count_right++;
            }

            if(count_left-count_right < 0) flag = false;
        }
        
        if(count_left==count_right && flag){
            ans.push_back(buf);
        }

    }

    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans.at(i) << endl;
    }

    return 0;
}