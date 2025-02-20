#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x,y; Point(){}; Point(int _x, int _y):x(_x),y(_y){}};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int T; cin >> T;
    while(T--){
        int N,K; cin >> N >> K;
        vector<pair<ll, ll>> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i].first;
            A[i].second = i;
        }

        vector<ll> B(N);
        for(auto &_v : B) cin >> _v;

        sort(ALL(A));
        ll sumB = 0;
        // max(A)の方が下からK番目のものであれば取りうるsum(B)はこれだけ
        multiset<int> mstB, other;
        for(int i = 0; i < K; i++){
            sumB += B[A[i].second];
            mstB.insert(B[A[i].second]);
        }

        ll ans = A[K-1].first*sumB;
        // printf("init\t%lld * %lld = %lld\n", A[K-1].first, sumB, ans);
        
        // max(A)が下からi番目のものならBの値が小さいものに一つ交換できる
        for(int i = K; i < N; i++){
            // B[A[i].second]は必ず入れなければならないので
            int buf = *prev(mstB.end());
            mstB.erase(prev(mstB.end()));
            other.insert(buf);
            mstB.insert(B[A[i].second]);
            sumB = sumB - buf + B[A[i].second];
            
            auto itr = mstB.find(B[A[i].second]);
            if(itr != prev(mstB.end())){
                while(*prev(mstB.end()) > *other.begin() ){
                    int s = *prev(mstB.end());
                    int t = *other.begin();

                    mstB.erase(prev(mstB.end()));
                    other.erase(other.begin());
                    
                    mstB.insert(t);
                    other.insert(s);

                    sumB = sumB-s+t;
                }
            }else{
                while(K > 1 && *prev(prev(mstB.end())) > *other.begin() ){
                    int s = *prev(prev(mstB.end()));
                    int t = *other.begin();

                    mstB.erase(prev(prev(mstB.end())));
                    other.erase(other.begin());
                    
                    mstB.insert(t);
                    other.insert(s);

                    sumB = sumB-s+t;
                }

            }

            // printf("\t%lld * %lld = %lld\n", A[i].first, sumB, A[i].first*sumB);
            chmin(ans, A[i].first*sumB);
        }

        cerr << "\t";
        cout << ans << endl;
    }
    return 0;
}