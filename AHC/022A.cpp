#include <bits/stdc++.h>
using namespace std;

//ファイル出力----
#include <fstream>
ofstream file;
//--------------

struct Pos {
    int y, x;
};

struct Judge {
    void set_temperature(const vector<vector<int>>& temperature) {
        cout << "# set temperature" << endl;
        for (const vector<int>& row : temperature) {
            for (int i = 0; i < row.size(); i++) {
                string output = to_string(row[i]) + (i == row.size() - 1 ? "\n" : " ");
                cout << output;
                file << output;

            }
        }
        cout.flush();
        file.flush();
    }

    int measure(int i, int y, int x) {
        cout << i << " " << y << " " << x << endl;
        int v;
        cin >> v;
        if (v == -1) {
            cerr << "something went wrong. i=" << i << " y=" << y << " x=" << x << endl;
            exit(1);
        }
        return v;
    }

    //回答
    void answer(const vector<int>& estimate) {
        cout << "-1 -1 -1" << endl;
        file << "-1 -1 -1" << endl;
        for (int e : estimate) {
            cout << e << endl;
            file << e << endl;
        }
    }
};

struct Solver {
    const int L; // 10 <= L <= 50
    const int N; // 60 <= N <= 100
    const int S; // 1 <= sqrt(S) <= 30
    const vector<Pos> landing_pos; //出口セルの情報
    Judge judge;

    Solver(int L, int N, int S, const vector<Pos>& landing_pos) : 
        L(L), N(N), S(S), landing_pos(landing_pos), judge() {
    }

    void solve() {
        const vector<vector<int>> temperature = create_temperature();
        judge.set_temperature(temperature);
        const vector<int> estimate = predict(temperature);
        judge.answer(estimate);
    }

    //配置
    vector<vector<int>> create_temperature() {
        vector<vector<int>> temperature(L, vector<int>(L, 0));
        for(int i = 0; i < L; i++){
            for(int j = 0; j < L; j++){
                temperature[i][j] = i*7 + j*13; //MAX: 50*7 + 50*13 = 1000. 実際にはL=50のとき49*7+49*13だけど...
            }
        }
        return temperature;
    }

    //計測
    vector<int> predict(const vector<vector<int>>& temperature) {
        vector<int> estimate(N);
        for (int i_in = 0; i_in < N; i_in++) {
            cout << "# measure i=" << i_in << " y=0 x=0" << endl;

            int measured_value = judge.measure(i_in, 0, 0);

            int min_diff = 9999;
            for (int i_out = 0; i_out < N; i_out++) {
                const Pos& pos = landing_pos[i_out];
                int diff = abs(temperature[pos.y][pos.x] - measured_value);
                if (diff < min_diff) {
                    min_diff = diff;
                    estimate[i_in] = i_out;
                }
            }
        }
        return estimate;
    }
};

int main() {
    file.open("022A_output.txt", ios::out);

    cout << "# input section" << endl;
    int L, N, S;
    cin >> L >> N >> S;
    vector<Pos> landing_pos(N);
    for (int i = 0; i < N; i++) {
        cin >> landing_pos[i].y >> landing_pos[i].x;
    }

    Solver solver(L, N, S, landing_pos);
    solver.solve();
}
