/*https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_j*/
//転倒数に関する問題
//以下の解法だと文字列NとするとN^2の計算量でTLE

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a.at(i);

    vector<int> a_sorted;
    a_sorted = a;
    sort(a_sorted.begin(), a_sorted.end());

    int count=0;
    //i=0はbuf[i]=aと同じのを探して場所を先頭まで一つずつ持ってくるように愚直にやる
    for(int i = 0; i < a_sorted.size(); i++){
        for(int j = 0; j < a.size(); j++){
            if(a.at(j) == a_sorted.at(i)){
                count += j;
                a.erase(a.begin()+j);
            }
            //cout << "a";
        }
        //cout << "b";
    }

    cout << count << endl;
    return 0;
}