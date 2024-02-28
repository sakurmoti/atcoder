#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S,T; cin >> S >> T;
    int N = S.size();

    vector<vector<bool>> used(30, vector<bool>(30, false));
    for(int i = 0; i < N; i++){
        used[S[i] - 'a'][T[i] - 'a'] = true; // S[i] -> T[i]に変換
    }

    bool ans = true;
    for(int i = 0; i <= 26; i++){
        int cnt = 0;
        for(int j = 0; j <= 26; j++){
            // i=kで固定して、used[k][j]=1なるものが複数あれば同じアルファベットが違うアルファベットに変換されている
            if(used[i][j]) cnt++;
        }

        if(cnt > 1) ans = false;
    }

    for(int j = 0; j <= 26; j++){
        int cnt = 0;
        for(int i = 0; i <= 26; i++){
            // j=kで固定して、used[i][k]=1なるものが複数あれば違うアルファベットが同じアルファベットに変換されている
            if(used[i][j]) cnt++;
        }
        
        if(cnt > 1) ans = false;
    }

    for(int i = 0; i <= 26; i++){
        for(int j = 0; j <= 26; j++){
            if(used[i][j]) cout << (char)((int)'a' + i) << " to " << (char)((int)'a'+j);
        }
        cout << "\n";
    }

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}