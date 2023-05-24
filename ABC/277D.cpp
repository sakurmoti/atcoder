#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    int a;
    map<int,int> f;
    long long sumA = 0;
    for(int i = 0; i < N; i++){
        cin >> a;
        sumA += a;
        f[a]++;
    }

    /*0 <= Ai < Mから(X+1) modMとなるカードは0のみ(X=M-1のとき)
    Ai = M-1が存在すれば、0につなげることができる
    Ai=Ajなる数字があるならどうせ全て消したほうが良いので重複は除いてよい
    そこで整数nのカードがy枚あることを指す辞書y = f(n)を作る
    ソートして連番が途切れたところまではつなげられる
    逆に途切れた後の数字からスタートする以外は無駄なのでやらなくてよい*/

    long long maximum=0;
    long long sum = 0;
    long long sum0=-1;
    for(auto itr = f.begin(); itr != f.end(); itr++){
        //printf("map[%d] = %d\n",itr->first, itr->second);
        //printf("next itr : map[%d] = %d\n", next(itr)->first, next(itr)->second);

        if(sum == 0){
            sum += (itr->first)*(itr->second);
        }

        if(itr != prev(f.end())){
            //mapのイテレータはpair<const key, value>で入っている
            if( (itr->first)+1 == (next(itr)->first)){
                sum += (next(itr)->first)*(next(itr)->second);

            }else{
                maximum = max(maximum, sum);
                if(sum0 == -1) sum0 = sum;

                sum = 0;
            }

        }else{
            //最後のイテレータになったら0とつなげられるか確認
            //この時、最初から最後までずっと続いていたら加算してはいけないことに注意
            if(f.begin()->first == 0 && sum0 != -1 && f.end()->first == M-1){
                sum += sum0;
            }

            maximum = max(maximum, sum);

        }
        
        //printf("sum = %d\n\n",sum);
    }

    cout << sumA-maximum << endl;
    return 0;
}