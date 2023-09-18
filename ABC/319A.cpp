#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    map<string, int> rate;
    rate["tourist"] = 3858;
    rate["ksun48"] = 3679;
    rate["Benq"] = 3658;
    rate["Um_nik"] = 3648;
    rate["apiad"] = 3638;
    rate["Stonefeang"] = 3630;
    rate["ecnerwala"] = 3613;
    rate["mnbvmar"] = 3555;
    rate["newbiedmy"] = 3516;
    rate["semiexp"] = 3481;

    string s; cin >> s;
    cout << rate[s] << endl;
    return 0;
}