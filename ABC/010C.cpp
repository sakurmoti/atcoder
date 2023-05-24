#include <bits/stdc++.h>
using namespace std;

int main(){
    int fx,fy,lx,ly,T,V,N;
    cin >> fx >> fy >> lx >> ly >> T >> V >> N;

    
    int L = T*V;
    int x,y;
    for(int i = 0; i < N; i++){
        cin >> x >> y;

        int d1 = (x-fx)*(x-fx) + (y-fy)*(y-fy);
        int d2 = (lx-x)*(lx-x) + (ly-y)*(ly-y);

        double dis = sqrt(d1) + sqrt(d2);
        //printf("dis=%lf, L=%d\n",dis,L);
        if(dis <= L){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}