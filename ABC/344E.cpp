#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;

    struct List{
        int num;
        int next = -1;
        int prev = -1;

        List(): num(-1) {}
        List(int n): num(n) {}

        void set_next(int nx){
            this->next = nx;
        }
        
        void set_prev(int pr){
            this->prev = pr;
        }

    };

    map<int, List> dict; 
    int pre=-1;
    for(int i = 0; i < N; i++){
        int a; cin >> a;

        if(pre > 0) dict[pre].set_next(a);

        dict[a] = List(a);
        dict[a].set_prev(pre);

        pre = a;
    }

    int Q; cin >> Q;
    while(Q--){
        int q; cin >> q;

        if(q == 1){
            int x,y; cin >> x >> y;
            
            dict[y] = List(y);
            
            if(dict[x].next > 0) dict[dict[x].next].set_prev(y);
            
            dict[y].set_prev(x);
            dict[y].set_next(dict[x].next);

            dict[x].set_next(y);
        }

        if(q == 2){
            int x; cin >> x;

            if(dict[x].next > 0) dict[dict[x].next].set_prev(dict[x].prev);
            if(dict[x].prev > 0) dict[dict[x].prev].set_next(dict[x].next);

            dict.erase(x);
        }

        // {
        //     printf("\n");
        //     for(auto [k,v] : dict){
        //         printf("key : %d, prev : %d next : %d\n", k ,v.prev, v.next);
        //     }
        //     printf("\n");
        // }
    }

    int idx = 0;
    for(auto [k,v] : dict){
        if(v.prev < 0){
            idx = k;
            break;
        }
    }

    while(idx > 0){
        List ls = dict[idx];

        cout << ls.num << " ";
        idx = ls.next;
    }
    return 0;
}