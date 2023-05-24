#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
        a.at(i)--; // 0-indexにする
    }

    sort(a.begin(), a.end());
    
    set<int> flag;
    int c = a.size();
    for(int i = 0; i < c;){
        if(flag.count(a.at(i))){
            //もう出ているなら後ろへ
            a.push_back(a.at(i));
            a.erase(a.begin()+i);
            c--;
        }else{
            //そうでないなら追加
            flag.insert(a.at(i));
            i++;
        }
    }

    int ans=0, idx=0;
    int size = a.size();
    while(size >= idx){
        //printf("idx= %d\n",idx);
        if(ans == a.at(idx)){
            //順番に読めている
            ans++;
            idx++;
        
        }else{
            if(size-2 >= idx){
                //後ろ二巻を犠牲に新しいのを買う
                ans++;
                size-=2;
            }else{
                //できないなら終了
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}