#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) (a).begin(), (a).end()

// 今考えたらdeque使うならprefixとsuffix分ける必要なかった
// 複雑に考えすぎ
int main(){
    string S; cin >> S;
    int Q; cin >> Q;

    // not rev : pre + S + suf
    // rev : fus + rev(S) + erp
    deque<char> suffix, prefix;
    bool rev = false;
    for(int q = 0; q < Q; q++){
        int t; cin >> t;
        
        if(t == 1){
            rev = !rev;
        }

        if(t == 2){
            int f; char c;
            cin >> f >> c;

            if(f == 1){
                if(rev){
                    suffix.push_back(c);
                }else{
                    prefix.push_front(c);
                }
            }

            if(f == 2){
                if(rev){
                    prefix.push_front(c);
                }else{
                    suffix.push_back(c);
                }
            }
        }
    }

    if(rev){
        reverse(all(prefix));
        reverse(all(S));
        reverse(all(suffix));

        for(int i = 0; i < suffix.size(); i++) cout << suffix[i];
        for(int i = 0; i < S.size(); i++) cout << S[i];
        for(int i = 0; i < prefix.size(); i++) cout << prefix[i];
    }else{
        for(int i = 0; i < prefix.size(); i++) cout << prefix[i];
        for(int i = 0; i < S.size(); i++) cout << S[i];
        for(int i = 0; i < suffix.size(); i++) cout << suffix[i];
    }

    
    return 0;
}