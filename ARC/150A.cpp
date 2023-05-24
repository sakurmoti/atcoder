#include <bits/stdc++.h>
using namespace std;

bool Query(){
    int N,K;
    string S;
    cin >> N >> K >> S;

    /*必ずK個1が連続で、それ以外は0である文字列をつくる
    つまり、一番左の1と右の1の間に0があったら不可能、またはその長さがK以上なら不可能
    一番左の1と右の1の両端に?がありその間にK-1個1が並んでいたら2通りできてしまう
    1が一個しかない場合、その1の両端に挟まれていたら2個できてしまう*/

    //1を数える
    int count=0;
    int start_one=-1, last_one=-1;
    for(int i = 0; i < N; i++){
        if(S[i] == '1'){
            if(count == 0){
                start_one = i;
            }else{
                last_one = i;
            }
            count++;
        
        }else if(S[i] == '0'){
            //1が分断されると不可能
            if(count != 0){
                return false;
            }

        }

    }

    /*1の場所を基準に?がどのように伸びてるか確認する*/
    if(count == 1){
        int i=1;
        bool m=true, p=true;
        int dis=1;
        while(true){
            int minus = start_one - i;
            int plus = start_one + i;
            if(m && minus >= 0 && S[minus] == '?'){
                dis++;
            }else{
                m = false;
            }

            if(p && plus < N && S[plus] == '?'){
                dis++;
            }else{
                p = false;
            }

            i++;
            if(!m && !p) break;
        }

        return (dis>=K);
    
    }else{
        
    }

    return true;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        cout << (Query() ? "Yes" : "No") << endl;
    }
    return 0;
}