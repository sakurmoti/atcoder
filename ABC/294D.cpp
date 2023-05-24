#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,Q;
    cin >> N >> Q;

    set<int> service;
    queue<int> numbers;
    priority_queue<int, vector<int>, greater<int>> called;
    
    for(int i = 1; i <= N; i++) numbers.push(i);

    for(int q = 0; q < Q; q++){
        int event; cin >> event;

        if(event == 1){
            called.push(numbers.front());
            numbers.pop();

        }else if(event == 2){
            int x; cin >> x;
            service.insert(x);
            
        }else if(event == 3){
            while(true){
                if(service.find(called.top()) != service.end()){
                    called.pop();
                
                }else{
                    cout << called.top() << endl;
                    break;
                }
            }

        }
    }
    return 0;
}