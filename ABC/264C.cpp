#include <bits/stdc++.h>
using namespace std;

int main(){
    //input
    int H1,W1;
    cin >> H1 >> W1;
    vector<vector<int>> A(H1, vector<int>(W1));
    for(int i = 0; i < H1; i++){
        for(int j = 0; j < W1; j++){
            cin >> A.at(i).at(j);
        }
    }

    int H2,W2;
    cin >> H2 >> W2;
    vector<vector<int>> B(H2, vector<int>(W2));
    for(int i = 0; i < H2; i++){
        for(int j = 0; j < W2; j++){
            cin >> B.at(i).at(j);
        }
    }

    //H,Wが小さいからだまってbit全探索！！！！！
    for(int y = 0; y < (1 << H1); y++){
        for(int x = 0; x < (1 << W1); x++){
            bitset<10> h(y), w(x);
            
            //bit_hには1になる場所を入れておき、次の比較をやりやすくする
            //1の数を数えてBと同じ行列ができるか確認。できないなら次のbitへ
            vector<int> bit_h, bit_w;
            for(int i = 0; i < 10; i++){
                if(h.test(i)){
                    bit_h.push_back(i);
                }
                if(w.test(i)){
                    bit_w.push_back(i);
                }
            }
            if(bit_h.size() != H2 || bit_w.size() != W2) continue;

            //bitが1になるところのAの行および列とBを比較する
            bool ans = true;
            for(int i = 0; i < H2; i++){
                for(int j = 0; j < W2; j++){
                    if(B.at(i).at(j) != A.at(bit_h.at(i)).at(bit_w.at(j)) ){
                        ans = false;
                        break; //正直breakしてもしなくても計算量的には一緒
                    }
                }
            }

            if(ans){
                cout << "Yes" << endl;
                return 0;
            }

        }
    }

    cout << "No" << endl;

    return 0;
}