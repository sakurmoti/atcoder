#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<pair<int,int>> p(N);
    for(int i = 0; i < N; i++){
        cin >> p.at(i).first;
        p.at(i).second = i;
    }
    sort(p.begin(), p.end());

    //imos法を用いる。最初の状態から0~N-1反回転した状態で幸せになる場所をメモ
    vector<int> imos(N,0);
    for(int i = 0; i < N; i++){
        int temp = p.at(i).second - i; //人iと料理iの距離
        int rotate = (N-temp)%N; //何回回転したら料理iが人iの前に来るか

        //人iの前
        imos.at(rotate)++;
        
        //人i-1のまえ
        if(rotate == 0){
            imos.at(N-1)++;

        }else{
            imos.at(rotate-1)++;

        }

        //人i+1の前
        imos.at((rotate+1)%N)++;
        
    }

    int max=imos[0];
    for(int i = 0; i < N; i++){
        if(max < imos[i]) max = imos[i];
    }

    cout << max << endl;

    return 0;
}