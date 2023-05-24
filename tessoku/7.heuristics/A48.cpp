//焼きなまし法を用いる
//焼きなまし法とは、局所解にはまらないように一定確率でスコアが下がる方向に遷移させることである
//採用する確率Pはスコアが上昇するときP = 1
//減少するときはネイピア数e、スコアの落差d、温度Tを用いて一般にP = e^(-d/T)とすることがおおい
//確率Pは序盤は局所解から抜け出しやすいように高く、終盤は真の最適解に近づきやすいように低く設定したい
//従って、温度Tは徐々に温度を下げて確率を低くする

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

bool Randouble(double dx, int Temperature){
    double P = exp(-dx/Temperature); //遷移する確率

    double basic = 1.0*rand()/RAND_MAX; //基準点(0 ~ 1.0)

    if(basic < P) return true;
    else return false;
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

    double D = getSumDistance();
    //とりあえず900msまでループさせてみる
    while(tm.elapsed() < 900){
        //1からN-1の区間
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
        double newD = getSumDistance();

        if(D > newD){
            //スコアが上がる変更なら必ず採用
            D = newD;

        }else{
            if(Randouble(abs(newD-D), 900-tm.elapsed())){
                //スコアが下がっても一定確率で採用
                D = newD;

            }else{
                reverse(next(ans.begin(),idx1), next(ans.begin(),idx2+1));
            
            }
        }

    }

    for(auto v : ans){
        cout << v << endl;
    }
    return 0;
}