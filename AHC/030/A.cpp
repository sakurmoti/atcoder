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
    double cost = 0.0;
    Tester tester;

    Judge(){}

    void setTester(Tester t){tester = t;}
    void setLimit(int l){Limit = l;}

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
    vector<vector<int>> Island;
    Judge judge;

    vector<int> ans;

    Solver(int n, int m, double eps, vector<vector<int>> shape)
    : N(n), M(m), EPS(eps), Shape(shape) {
        Island.resize(N, vector<int>(N,-1));
        judge.setLimit(2*N*N);
    }

    int solve(){
        // all_dig();
        // grid_dig();
        dfs_dig();
        // division_dig();
        // division_dig2();
        int res = judge.answer(ans);

        return res;
    }

    // 解法1
    void all_dig(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                Island[i][j] = judge.dig(i, j);

                if(Island[i][j] > 0){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
    }

    // 解法2-1
    void grid_dig(){
        int oil = 0;
        int sum = 0;
        for(auto &v : Shape) oil += v.size()/2;
        cout << "# oil : " << oil << endl;

        auto isRange = [](int x, int L, int R){ return L <= x && x < R; };

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if( (Island[i][j] < 0) && ( (i%2 == 0 && j%2==1) || (i%2==1 && j%2==0) ) ){
                    Island[i][j] = judge.dig(i,j);
                    

                    if(Island[i][j] > 0){
                        ans.push_back(i);
                        ans.push_back(j);
                        color(i, j, "#00ff00");
                        sum += Island[i][j];
                        if(sum == oil) return;

                        if( isRange(j-1, 0, N) && Island[i][j-1] < 0 ){
                            Island[i][j-1] = judge.dig(i, j-1);
                            if(Island[i][j-1] > 0){
                                ans.push_back(i);
                                ans.push_back(j-1);
                                color(i, j-1, "#99ff99");
                                sum += Island[i][j-1];
                                if(sum == oil) return;
                            }
                        }

                        if( isRange(j+1, 0, N) && Island[i][j+1] < 0 ){
                            Island[i][j+1] = judge.dig(i, j+1);
                            if(Island[i][j+1] > 0){
                                ans.push_back(i);
                                ans.push_back(j+1);
                                color(i, j+1, "#99ff99");
                                sum += Island[i][j+1];
                                if(sum == oil) return;
                            }
                        }

                        if( isRange(i-1, 0, N) && Island[i-1][j] < 0 ){
                            Island[i-1][j] = judge.dig(i-1, j);
                            if(Island[i-1][j] > 0){
                                ans.push_back(i-1);
                                ans.push_back(j);
                                color(i-1, j, "#99ff99");
                                sum += Island[i-1][j];
                                if(sum == oil) return;
                            }
                        }

                        if( isRange(i+1, 0, N) && Island[i+1][j] < 0 ){
                            Island[i+1][j] = judge.dig(i+1, j);
                            if(Island[i+1][j] > 0){
                                ans.push_back(i+1);
                                ans.push_back(j);
                                color(i+1, j, "#99ff99");
                                sum += Island[i+1][j];
                                if(sum == oil) return;
                            }
                        }
                    }else{
                        color(i, j, "#ff0000");
                    
                    }
                }
            }
        }
    }

    // 解法2-2
    void dfs_dig(){
        // grid_digのように掘っていき、1以上が見つかったらdfsで隣接を掘る
        // oilと等しくなったらreturn
        int oil = 0;
        int sum = 0;
        for(auto &v : Shape) oil += v.size()/2;

        auto isRange = [](int x, int L, int R){ return L <= x && x < R; };

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        auto bfs = [&](int s, int t) -> void {
            queue<pair<int, int>> que;
            que.push({s,t});

            int x,y;
            while(!que.empty()){
                if(sum == oil) return;

                auto [y, x] = que.front();
                que.pop();
                if(Island[y][x] >= 0) continue;
                Island[y][x] = judge.dig(y,x);
                sum += Island[y][x];

                if(Island[y][x] > 0){
                    ans.push_back(y);
                    ans.push_back(x);
                    for(int i = 0; i < 4; i++){
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if(isRange(nx, 0, N) && isRange(ny, 0, N)) que.push({ny, nx});
                    }
                }
            }
        };

        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < N; j++){
        //         if( (Island[i][j] < 0) && ( (i%2 == 0 && j%2==1) || (i%2==1 && j%2==0) ) ){
        //             bfs(i, j);
        //         }
        //     }
        // }

        // ランダムで掘ってみる
        // こっちのほうがよさそう
        uniform_int_distribution<int> unif(0, N-1);
        while(sum < oil){
            random_device seed;
            mt19937 mt(seed());
            int randY = unif(mt);
            int randX = unif(mt);
            bfs(randY, randX);
        }

    }

    // 解法3-1
    void division_dig(){
        auto g = [](int x) -> int {
            return x/2;
        };

        function<void(int, int, int, int)> divide = [&](int sy, int sx, int ty, int tx) -> void {
            if(sy == ty || sx == tx) return;

            vector<int> p;
            for(int i = sy; i < ty; i++){
                for(int j = sx; j < tx; j++){
                    p.push_back(i);
                    p.push_back(j);
                }
            }

            // 1マスの場合は掘って情報を確定させる
            if(p.size()/2 == 1){
                int y = p[0];
                int x = p[1];
                Island[y][x] = judge.dig(y, x);
                if(Island[y][x] > 0){
                    ans.push_back(y);
                    ans.push_back(x);
                }
                return;
            }

            // 2マス以上は占い、0が多いと思われる場合はスルー
            // ただし、占う範囲が広いほど精度は悪いので繰り返し占う必要がある
            vector<int> f;
            for(int i = 0; i < g((ty-sy) * (tx-sx)); i++){
                f.push_back(judge.fortune(p));
            }
            
            int zero = 0;
            int other = 0;
            for(int i = 0; i < f.size(); i++){
                if(f[i] == 0) zero++;
                else other++;
            }
            if(zero > other) return;
            
            int my = (sy + ty) / 2;
            int mx = (sx + tx) / 2;

            divide(sy, sx, my, mx);
            divide(sy, mx, my, tx);
            divide(my, sx, ty, mx);
            divide(my, mx, ty, tx);
        };

        divide(0, 0, N/2, N/2);
        divide(0, N/2, N/2, N);
        divide(N/2, 0, N, N/2);
        divide(N/2, N/2, N, N);
    }

    // 解法3-2
    void division_dig2(){
        int stlide = 1;
        int window_H = 2;
        int window_W = 2;

        for(int i = 0; i < N; i += stlide){
            for(int j = 0; j < N; j += stlide){
                int sy = i;
                int sx = j;
                int ty = min(i + window_H, N);
                int tx = min(j + window_W, N);

                vector<int> p;
                for(int y = sy; y < ty; y++){
                    for(int x = sx; x < tx; x++){
                        p.push_back(y);
                        p.push_back(x);
                    }
                }

                vector<int> f;
                for(int k = 0; k < 3; k++){
                    f.push_back(judge.fortune(p));
                }

                int zero = 0;
                int other = 0;
                for(int k = 0; k < f.size(); k++){
                    if(f[k] == 0) zero++;
                    else other++;
                }

                if(zero > other) continue;

                for(int y = sy; y < ty; y++){
                    for(int x = sx; x < tx; x++){
                        Island[y][x] = judge.dig(y, x);
                        if(Island[y][x] > 0){
                            ans.push_back(y);
                            ans.push_back(x);
                        }
                    }
                }
            }
        }

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
        solver.judge.setTester(tester);
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