//局所探索法(山登り法)
//初期解を適当に設定し、小さな変更を初期解に加えたとき、スコアが良くなるなら採用する方式
//今回の小さな変更は「区間の移動順序の反転」とする

#include <bits/stdc++.h>
using namespace std;

/*
Timer() : コンストラクタ
restart() 計測開始時間を保存
elapsed() : restartから経過したミリ秒を返す
*/
class Timer{
    private: std::chrono::system_clock::time_point start;

    public:
        Timer(){
            restart();
        }

    public:
        void restart(){
            start = std::chrono::system_clock::now();
        }

        auto elapsed(){
            auto end = std::chrono::system_clock::now();
            auto dur = end - start;
            auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

            return ms;
        }
};

vector<int> X,Y;
vector<int> ans;

double getSumDistance(){
    double sum=0;
    for(int i = 0; i < ans.size()-1; i++){
        sum += sqrt(pow(X[ans[i]]-X[ans[i+1]], 2) + pow(Y[ans[i]]-Y[ans[i+1]], 2));
    }

    return sum;
}

int main(){
    Timer tm;
    tm.restart();
    int N;
    cin >> N;

    X.resize(N+1);
    Y.resize(N+1);
    for(int i = 1; i <= N; i++){
        cin >> X[i] >> Y[i];
    }

    //初期解を{1,2,3...N-1,N,1}に設定
    for(int i = 1; i <= N; i++){
        ans.push_back(i);
    }
    ans.push_back(1);

    double score = getSumDistance();
    //とりあえず900msまでループさせてみる
    while(tm.elapsed() < 900){
        //rand()は0からINT_MAXの間の値を返す
        //従ってNのmodを取れば0からN-1の間の値に
        //+1をすれば1からNの間の値に
        //最初と最後は都市1で固定なので1からN-1の区間
        int idx1 = rand()%(N-1) + 1;
        int idx2 = rand()%(N-1) + 1;
        
        if(idx1 == idx2){
            continue;
        
        }else if(idx2 < idx1){
            int tmp = idx2;
            idx2 = idx1;
            idx1 = tmp;

        }

        reverse(next(ans.begin(),idx1), next(ans.begin(),idx2+1));
        double bScore = getSumDistance();

        if(score > bScore){
            score = bScore;

        }else{
            reverse(next(ans.begin(),idx1), next(ans.begin(),idx2+1));
        
        }

    }

    for(auto v : ans){
        cout << v << endl;
    }
    return 0;
}