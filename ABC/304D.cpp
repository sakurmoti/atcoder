#include <bits/stdc++.h>
using namespace std;

int main(){
    int W,H,N;
    cin >> W >> H >> N;

    vector<pair<int, int>> pq(N);
    for(int i = 0; i < N; i++){
        cin >> pq[i].first >> pq[i].second;
    }
    
    sort(pq.begin(), pq.end());
    
    int A; cin >> A;
    vector<int> a(A+1,0);
    for(int i = 1; i <= A; i++){
        cin >> a[i];
    }
    a.push_back(W); //x=Wの線を追加

    int B; cin >> B;
    vector<int> b(B+1,0);
    for(int i = 1; i <= B; i++){
        cin >> b[i];
    }
    b.push_back(H); //y=Hの線を追加

    //a[i] <= x < a[i+1] && b[j] <= y < b[j+1]のとき、(x,y) =(i,j)のピースであるとする
    map<pair<int, int>, int> ichigo;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        int x = pq[i].first;
        int X = *lower_bound(a.begin(), a.end(), x);

        int y = pq[i].second;
        int Y = *lower_bound(b.begin(), b.end(), y);
        ichigo[make_pair(X,Y)]++;
    }
    
    int m=1e9,M=-1;
    for(auto v : ichigo){
        //printf("(x,y) = (%d,%d), cnt = %d\n",v.first.first,v.first.second,v.second);
        m = min(m, v.second);
        M = max(M, v.second);
    }

    if(ichigo.size() < ((long long)(A+1))*(B+1)) m=0;
    cout << m << " " << M << endl;
    return 0;
}