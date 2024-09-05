#include <bits/stdc++.h>
using namespace std;

struct Point {
  int x, y;
};

int dist(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
  int seed = 1;
  stringstream ss;
  streambuf *cinbuf = cin.rdbuf();
  streambuf *coutbuf = cout.rdbuf();
  ss << setw(4) << setfill('0') << seed;
  ifstream ifs("in/" + ss.str() + ".txt");
  cin.rdbuf(ifs.rdbuf());
  ofstream ofs("out/" + ss.str() + ".txt");
  cout.rdbuf(ofs.rdbuf());

  // get input
  int N, M, T, L_A, L_B;
  cin >> N >> M >> T >> L_A >> L_B;

  vector<vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  vector<int> t(T);
  for (int i = 0; i < T; i++) {
    cin >> t[i];
  }

  vector<Point> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P[i].x >> P[i].y;
  }

  // construct and output the array A
  vector<int> A(L_A, 0);
  for (int i = 0; i < N; i++) {
    A[i] = i;
  }
  for (int i = 0; i < L_A; i++) {
    cout << A[i];
    if (i < L_A - 1) {
      cout << ' ';
    } else {
      cout << endl;
    }
  }

  int pos_from = 0;

  for (int i = 0; i < T; i++) {
    int pos_to = t[i];

    // determine the path by BFS
    auto bfs = [&](int st, int gl){
        queue<int> que;
        que.push(st);
        vector<bool> visited(N, false);
        visited[st] = true;
        vector<int> parent(N, -1);

        while(!que.empty()){
            int v = que.front();
            que.pop();

            if(v==gl){
                vector<int> path;
                while(parent[v] != -1){
                    path.push_back(v);
                    v = parent[v];
                }
                reverse(path.begin(), path.end());
                return path;
            }

            for(int i = 0; i < G[v].size(); i++){
                int next = G[v][i];
                if(visited[next]) continue;
                visited[next] = true;

                parent[next] = v;
                que.push(next);    
            }
        }

        throw runtime_error("no path : " + to_string(st) + " -> " + to_string(gl));
    };
    auto path = bfs(pos_from, pos_to);

    // for every step in the path, control the signal and move
    for (int u : path) {
      cout << 's' << ' ' << 1 << ' ' << u << ' ' << 0 << endl;
      cout << 'm' << ' ' << u << endl;
    }
    pos_from = pos_to;
  }

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);
}
