#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S; cin >> S;
    int N = S.size();

    //999..99は必ず等差数なので、答えの数字の桁数はXと同じ
    //同じ桁数で最小なのは111..11
    //10桁以上はゾロ目しか等差数が存在しない
    
    //先頭の数字iと公差dを全探索
    for(int i = 1; i <= 9; i++){
        for(int d = -9; d <= 9; d++){
            //桁数はXと同じ
            string ans = "";
            bool flag = true;
            for(int k = 0; k < N; k++){
                int dd = i + k*d;
                if(!(0<=dd && dd<10)){
                    flag = false;
                }
                char num = '0' + dd;
                ans.push_back(num);
            }

            // cout << ans << endl;
            if(flag && ans >= S){
                cout << ans << endl;
                return 0;
            }
        }
    }
    return 0;
}  