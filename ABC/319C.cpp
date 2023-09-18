#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    vector<int> c(9);
    for(int i = 0; i < 9; i++){
        cin >> c[i];
    }

    vector<int> comb(9); //comb[i]をi番目に開ける場所とするのではなく、iをcomb[i]番目に開ける場所と定義すると楽
    iota(comb.begin(), comb.end(), 0);

    //確認すべき場所
    vector<tuple<int,int,int>> check{
        //行
        {0,1,2},
        {3,4,5},
        {6,7,8},

        //列
        {0,3,6},
        {1,4,7},
        {2,5,8},
        
        //斜め
        {0,4,8},
        {2,4,6}
    };

    int all = 0;
    int not_gakkari = 0;

    do
    {
        all++;
        bool gakkari = false;

        for(auto t : check){
            int x,y,z;
            tie(x,y,z) = t;
            // printf("x=%d, y=%d, z=%d\n",x,y,z);

            //xとyが同じでzが最後に開けられる場合
            if( (c[x] == c[y]) && (comb[x] < comb[z] && comb[y] < comb[z]) ){
                gakkari = true;
            
            //xとzが同じで~
            }else if( (c[x] == c[z]) && (comb[x] < comb[y] && comb[z] < comb[y]) ){
                gakkari = true;

            //yとzが同じで~
            }else if( (c[y] == c[z]) && (comb[y] < comb[x] && comb[z] < comb[x]) ){
                gakkari = true;

            }
        }

        if(!gakkari) not_gakkari++;
    } while (next_permutation(comb.begin(), comb.end()));
    
    // cout << not_gakkari << " " << all << endl;
    cout << fixed << setprecision(10) << (long double)not_gakkari / all << endl;
    return 0;
}