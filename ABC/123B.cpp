#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, c=0, ans=0;
    vector<int> num;
    for(int i = 0; i < 5; i++){
        cin >> t;

        if(t%10 == 0){
            ans += t;
            c++;

        }else{
            num.push_back(t);

        }
    }

    if(c==5){
        cout << ans << endl;
        return 0;
    }
    sort(num.begin(), num.end(), [](int a, int b) {return a%10 > b%10; });

    /*cout << "test" <<endl;
    for(int v : num) cout << v << endl;*/

    for(int i = 0; i < num.size()-1; i++){
        ans += (num.at(i) + (10 - num.at(i)%10));
    }

    ans += num.at(num.size()-1);
    cout << ans << endl;
    return 0;
}