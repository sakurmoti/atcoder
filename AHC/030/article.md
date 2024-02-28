解法1: 全部掘る
サンプルコードと同じ解法
なんかめっちゃ得点高くない？

問題文を読むと、今回は得点が低いとスコアが高いらしい
![image.png](https://qiita-image-store.s3.ap-northeast-1.amazonaws.com/0/3330525/75326c8f-77b8-8b70-89f0-3895d8f33a25.png)


解法2: チェック柄に掘る
・見つかったらその左右も掘る
ポリオミノ型なので左右上下どこかはつながっている
油田は4以上の大きさなので必ず見つけられる

seed = 0043
![seed0043.gif](https://qiita-image-store.s3.ap-northeast-1.amazonaws.com/0/3330525/bee49c91-2f6a-11ad-0d46-542c25edcf51.gif)

まぁ、全部掘る必要はなくなったけどまだ右側の広いところがもったいないかな～くらい
![image.png](https://qiita-image-store.s3.ap-northeast-1.amazonaws.com/0/3330525/73f2e165-f5b4-6b5e-620a-3329da198846.png)


小話: C++むずい
とりあえずcostを表示させる...が、なんかうまく行かない
solve()内でcerrに表示させるのはできるが、main関数内でcerrに表示はできない
coutの出力先をnullptrにしたらcerrが表示できた(<-なんで？)
詳しい人教えてくれ～

<details><summary>再現したコード</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

double score = 3.141592;

void solve(){    
    ofstream ofs("output/.txt");
    cout.rdbuf(ofs.rdbuf());

    cout << "In solve cout" << endl;
    cerr << "In solve cerr " << endl;
}

int main(){
    solve();

    // コメントアウトするとバグる
    // cout.rdbuf(nullptr);
    
    cout << "In main cout" << endl;
    cerr << "In main cerr " << endl;

    return 0;
}
```

色々実験した結果、main関数内でcoutを用いると必ず終了してしまう。

`streambuf* init = cout.rdbuf(ofs.rdbuf())`として、`cout.rdbuf(init)`としても動くので、
solve関数内でofstreamを設定したのが問題っぽい？

</details>


解法3: 占いを有効活用してみる
解法2でもまだ無駄なところを掘っている
大体この辺は0だなっていうのを占いで判断できないか考える
N*Nをとりあえず4分割にしてすべてを占う
-> 0ならその区間は掘らなくてよい
-> 0でなければさらに4分割して占う...

これを繰り返せば余計なところは掘らなくてすみそう

$N * N$のグリッドを4分割する回数が$\log_2N$回なので最大$4^{\log_2N} = N^2$回の占いをすることになる

占いの説明は以下の通り
> 2マス以上の集合$S$を選び、それらのマスの石油の埋蔵量の総和$v(S)=∑(i,j)∈S​ v(i,j)$を占う。<br>
> 選択するマスの数が多いほどコストは低くなり、$k$マス選んだ場合に生じるコストは$\frac{1}{\sqrt{k}}$である。<br>
> 一方で、$k$に比例して占いによって得られる情報の分散も大きくなる。<br>
> 事前に与えられるパラメータ$ϵ$を用いて、以下の平均$μ$と分散$σ^2$の正規分布からサンプルされた値を$x$とする。<br>
> このとき、情報として得られる値は$\max(0, \text{round}(x))$である。<br>
> * 平均 $μ=(k−v(S))ϵ+v(S)(1−ϵ)$
> * 分散 $σ^2=kϵ(1−ϵ)$

つまり、一回だけ占うと間違った結果を得るかもしれないということ
とりあえず占うマスの総数をKとして、K/2回占い、0以上であればさらに区間を4分割して占うことにしてみる

seed = 0001
![seed0001.gif](https://qiita-image-store.s3.ap-northeast-1.amazonaws.com/0/3330525/97e947f3-80ff-a536-047e-03e4604be40a.gif)

かなり微妙
最初の誤差で0が出るとその区間は二度と見られなかったり、一部のシード値では回数制限を超えていたり、2*2の範囲ですら2回占うくらいでは間違えてしまったりしているなどあまり良い使い方ではなさそう

そこで、二分探索みたいに探すのではなく、畳み込みのようにウィンドウをスライドさせながら占ってみる
