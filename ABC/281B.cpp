#include <bits/stdc++.h>
using namespace std;

bool isNum(char c){
    if('0' <= c && c <= '9'){
        return true;
    }else{
        return false;
    }
}

int main(){
    string S;
    cin >> S;

    bool flag = true;
    if(S.size() == 8){
        //最初が英文字か
        if(!isNum(S.at(0))){

            //続く6文字が数字か
            for(int i = 1; i <= 6; i++){
                if(isNum(S.at(i))){
                    if(i==1){
                        //最初の数字は0でないか
                        if(S.at(i) != '0'){
                            continue;
                        
                        }else{
                            flag = false;

                        }
                    }

                }else{
                    flag = false;

                }
            }

            //最後の文字が英文字か
            if(flag && !isNum(S.at(7))){

            }else{
                flag = false;
                
            }

        }else{
            flag = false;
        }

    }else{
        flag = false;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}