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


//動作確認
int main(){
    Timer tm;

    //O(10^8)の意味のない計算を計測してみる
    tm.restart();

    vector<int> hoge;
    for(int i = 0; i < 1e8; i++){
        hoge.push_back(i);
    }

    //AtcoderのコードテストではAtcoder上では721ms プログラム内では698msと出力された
    //なお、vscodeで実行すると2184msであった
    cout << tm.elapsed() << endl;
}