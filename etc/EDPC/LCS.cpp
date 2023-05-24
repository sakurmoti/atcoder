#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin >> s >> t;

    /*方針としてdpで最長の文字列の長さを求めてからその文字列を探す感じ
    dp[i][j]をsをi文字目まで、tをj文字目まで見たときの最長共通部分列の長さとする
    s[i]==t[j]ならこれを含めた方が長くなるのでdp[i-1][j-1] + 1
    s[i]!=t[j]ならどちらか一文字は含めなくてよいのでdp[i][j-1]またはdp[i-1][j]のまま
    */
    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1,0));
    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= t.size(); j++){
            if(s.at(i-1) == t.at(j-1)){
                dp.at(i).at(j) = dp.at(i-1).at(j-1) + 1;

            }else{
                dp.at(i).at(j) = max(dp.at(i-1).at(j), dp.at(i).at(j-1));
            }
        }
    }

    /*for(int i = 0; i <= s.size(); i++){
        for(int j = 0; j <= t.size(); j++){
            printf("dp[%d][%d] = %d\n",i,j,dp[i][j]);
        }
    }
    cout << dp.at(s.size()).at(t.size()) << endl;
    //dpによって最大値を求めることに成功
    */
    
    /*dpを逆にたどって決める
    s[i]==t[j]ならばその文字を使えばよいし、
    s[i]!-t[j]ならばdpの値が減らないほうに遷移すればよい
    */
    int len = dp.at(s.size()).at(t.size());
    int s_idx=s.size()-1, t_idx=t.size()-1;
    string ans;
    while(len > 0){
        //printf("s_idx = %d t_idx = %d\n",s_idx, t_idx);

        if(s.at(s_idx) == t.at(t_idx)){
            ans.push_back(s.at(s_idx));
            len--;
            s_idx--;
            t_idx--;
        
        }else if(dp.at(s_idx+1).at(t_idx+1) == dp.at(s_idx+1).at(t_idx)){
            t_idx -= 1;
        
        }else if(dp.at(s_idx+1).at(t_idx+1) == dp.at(s_idx).at(t_idx+1)){
            s_idx -= 1;
        
        }else{
            cout << "ERROR" << endl;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    
    return 0;
}