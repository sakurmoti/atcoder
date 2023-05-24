#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<string> A(N);
    int max_size = 0;
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        
        if(max_size < A.at(i).size()){
            max_size = A.at(i).size();
        }
    }

    //すべての文字列のsizeを0で揃える
    for(int i = 0; i < N; i++){
        A.at(i).insert(0, (max_size - A.at(i).size()), '0');
    }

    //ソートして下から3つとったのが作れる最大の桁数になる
    sort(A.begin(), A.end());

    //追加した0を消すため数字へ
    int one = stoi(*(A.end()-1));
    int two = stoi(*(A.end()-2));
    int three = stoi(*(A.end()-3));

    //Aは10^6なので最大で答えは10^21。また文字列に直す必要がある
    string fir = to_string(one);
    string sec = to_string(two);
    string thr = to_string(three);

    //9が先頭に来ているものが前に来た方が良い
    vector<string> pickup = {fir, sec, thr};
    sort(pickup.begin(), pickup.end());
    
    //答え
    string ans = pickup[2] + pickup[1] + pickup[0];
    cout << ans << endl;

    return 0;
}