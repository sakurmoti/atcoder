#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int a,b,c,d;
    vector<vector<int>> paper(2000, vector<int>(2000,0));
    for(int i = 0; i < N; i++){
        //xy座標で左下が(a,b) 右上が(c,d)
        //ユークリッド空間と配列の空間の違いに注意
        cin >> a >> b >> c >> d;
        a++;
        b++;

        paper.at(b).at(a)++;
        paper.at(b).at(c+1)--;
        paper.at(d+1).at(a)--;
        paper.at(d+1).at(c+1)++;
    }

    //imos
    for(int i = 0; i <= 1510; i++){
        for(int j = 0; j <= 1510; j++){
            paper.at(i).at(j+1) += paper.at(i).at(j);
        }
    }

    for(int j = 0; j <= 1510; j++){
        for(int i = 0; i <= 1510; i++){
            paper.at(i+1).at(j) += paper.at(i).at(j);
        }
    }

    int ans = 0;
    for(int i = 0; i < 1510; i++){
        for(int j = 0; j < 1510; j++){
            if(paper.at(i).at(j) > 0){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}