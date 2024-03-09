// after contest

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

double sum_cost = 0.0;

void color(int y, int x, string color){
    cout << "#c " << y << " " << x << " " << color << endl;
}

struct Tester {
    vector<int> Di;
    vector<int> Dj;
    vector<vector<int>> V;
    vector<double> E;
    
    int call = 0; // 0 <= call <= 2*N*N

    Tester(){}

    Tester(vector<int> di, vector<int> dj, vector<vector<int>> v, vector<double> e)
    : Di(di), Dj(dj), V(v), E(e) {}

    int dig(int y, int x){
        call++;
        return V[y][x];
    }

    int fortune(vector<int> point){
        int k = point.size() / 2;
        int sum = 0;
        for(int i = 0; i < k; i++){
            int y = point[i*2];
            int x = point[i*2+1];
            sum += V[y][x];
        }

        double mu = (k - sum) * E[call] + sum*(1.0 - E[call]);
        double sigma = k * E[call] * (1.0 - E[call]);

        normal_distribution<> dist(mu, sigma);
        mt19937 mt;
        int ret = round(dist(mt));
        ret = max(0, ret);

        call++;
        return ret;
    }

    bool answer(vector<int> ans){
        int k = ans.size() / 2;
        int n = V.size();
        vector<vector<int>> field(n, vector<int>(n, -1));
        for(int i = 0; i < k; i++){
            int y = ans[i*2];
            int x = ans[i*2+1];

            if(field[y][x] < 0){
                field[y][x] = 1;
            }else{
                cout << "# illegal answer" << endl;
                return false;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if( (V[i][j] > 0 && field[i][j] < 0) || (V[i][j] < 0 && field[i][j] > 0) ){
                    cout << "# invalid answer" << endl;
                    return false;
                }
            }
        }

        call++;
        return true;
    }
};

struct Judge {
    int Limit;
    Tester tester;
    double cost = 0.0;

    Judge(){}
    Judge(int n) : Limit(2*n*n) {}
    Judge(int n, Tester t) : Limit(2*n*n), tester(t) {}

    int dig(int y, int x) {
        if(Limit <= 0){
            cost += 1e5;
            return -1;
        }
        Limit--;
        cost += 1.0;
        cout << "q 1 " << y << " " << x << endl;
        color(y, x, "#00ff00");

        int ret;

        #ifdef __LOCAL__
            ret = tester.dig(y, x);
        #else
            cin >> ret;
        #endif

        return ret;
    }

    int fortune(vector<int> point){
        if(Limit <= 0){
            cost += 1e5;
            return -1;
        }
        Limit--;
        int k = point.size() / 2;
        cost += 1.0 / sqrt(k);

        cout << "q ";
        cout << k << " ";
        for(int i = 0; i < k; i++){
            cout << point[i*2] << " " << point[i*2+1];
            if(i == k-1) cout << endl;
            else cout << " ";
        }

        int ret;
        
        #ifdef __LOCAL__
            ret = tester.fortune(point);
        #else
            cin >> ret;
        #endif

        return ret;
    }

    int answer(vector<int> ans){
        if(Limit <= 0){
            cost += 1e5;
            return -1; // limit exceeded
        }
        Limit--;
        int d = ans.size() /2;
        cout << "a " << d << " ";
        for(int i = 0; i < d; i++){
            cout << ans[i*2] << " " << ans[i*2+1];
            if(i == d-1) cout << endl;
            else cout << " ";
        }

        bool ret;
        
        #ifdef __LOCAL__
            ret = tester.answer(ans);
        #else
            cin >> ret;
        #endif

        cout << "# cost: " << cost << endl;
        cout << "# absolute score: " << round(1e6 * cost) << endl;
        if(ret){
            sum_cost += cost;
            return 1; // ac
        }else{
            cost += 1.0;
            return 0; // wa
        }
    }

};

struct Solver {
    int N;
    int M;
    double EPS;
    vector<vector<int>> Shape;
    vector<vector<double>> Island;
    Judge judge;

    Solver(int n, int m, double eps, vector<vector<int>> shape)
    : N(n), M(m), EPS(eps), Shape(shape) {
        Island.resize(N, vector<double>(N, -1.0));
    }

    void setJudge(Judge j){judge = j;}
 
    int solve(){
        return 0;
    }

    // ベイズ推定
    double bayes(){
        /*
         P(A|B) = P(B|A)*P(A) / P(B)
         事象A : 真の配置がAである
         事象B : 占い結果がBである　としてベイズ推定

         事前分布P(A), P(B)は一定なので本質は尤度に比例する
         
        */
    }
};

void solve(string seed=""){
    #ifdef __LOCAL__
        ifstream ifs("input/" + seed  + ".txt");
        cin.rdbuf(ifs.rdbuf());
        ofstream ofs("output/" + seed + ".txt");
        cout.rdbuf(ofs.rdbuf());

        auto start = chrono::system_clock::now();
    #endif

    int n,m;
    double eps;
    cin >> n >> m >> eps;

    vector<int> d(m);
    vector<vector<int>> shape(m);
    for(int i = 0; i < m; i++){
        cin >> d[i];
        
        shape[i].resize(2*d[i]);
        for(int j = 0; j < 2*d[i]; j++){
            cin >> shape[i][j];
        }
    }

    Solver solver(n, m, eps, shape);
    
    #ifdef __LOCAL__
        vector<int> di(m), dj(m);
        for(int i = 0; i < m; i++){
            cin >> di[i] >> dj[i];
        }

        vector<vector<int>> v(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> v[i][j];
            }
        }

        vector<double> e(2*n*n);
        for(int i = 0; i < 2*n*n; i++){
            cin >> e[i];
        }

        Tester tester(di,dj,v,e);
        solver.setJudge(Judge(n, tester));
    #endif
    
    int res = solver.solve();

    #ifdef __LOCAL__
        auto end = chrono::system_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cerr << "seed : " << seed << ", ";
        cerr << "elapsed : " << elapsed << " ms" << ", ";
        cerr << "cost : " << solver.judge.cost << ", ";
        cerr << (res>0 ? "" : (res == 0 ? " <WA> " : " <TLE> ") );
        cerr << "\t\t sum_cost : " << sum_cost;
        cerr << endl;
    #endif
}

int main(){
    #ifdef __LOCAL__
        for(int i = 0; i <= 99; i++){
            stringstream ss;
            ss << setw(4) << setfill('0') << i;
            solve(ss.str());
        }

        cout.rdbuf(nullptr);
        cerr << fixed << setprecision(5) << "avg_cost : " << sum_cost / 100 << endl;
    #else
        solve();
    #endif

    return 0;
}