#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

struct Trie {
    struct Node{
        int cnt; // そのNodeの個数
        map<char, int> to; // k : 次の文字 v : Nodeのidx
        Node() : cnt(0){}
    };

    vector<Node> tree;

    Trie() : tree(1){} // 空文字列のノードを用意

    void add(string & s){
        int now = 0; // ノードの深さ
        for(auto c : s){
            if(!tree[now].to.contains(c)){
                // 行き先が存在しない場合ノードを追加
                tree[now].to[c] = tree.size(); // 新しいidxを割り振る
                tree.push_back(Node()); // 割り振ったidxに初期化したノード
            }

            now = tree[now].to[c];
        }

        tree[now].cnt++; // 末端のノード(すなわち単語のノードをカウント)
    }

    // 頂点uのカウントの総和
    ll ans = 0;
    ll dfs(int u){
        ll sum = tree[u].cnt;
        for(auto [k,v] : tree[u].to){
            sum += dfs(v);
        }

        // sum Combination 2 ただし空文字はカウントしない
        if(u != 0) ans += sum*(sum-1) / 2;
        // printf("idx = %d, sum = %d\n", u, sum);
        return sum;
    }

    void solve(){
        dfs(0);
        cout << ans << endl;
    }
};

int main(){
    int N; cin >> N;

    // 最長共通接頭辞を直接求めるのではなく、接頭辞Tが何回出現するかを考える
    Trie trie;
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        trie.add(s);
    }

    // {
    //     int M = trie.tree.size();
    //     for(int i = 0; i < M; i++){
    //         auto x = trie.tree[i];
    //         printf("\nidx = %d, cnt = %d\n",i, x.cnt);
    //         for(auto [k,v] : x.to){
    //             printf("[%c, %d]\n", k, v);
    //         }
    //     }
    // }

    trie.solve();
    return 0;
}