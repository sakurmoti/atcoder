#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A.at(i);
    for(int i = 0; i < N; i++) cin >> B.at(i);

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long sum =0;
    for(int i = 0; i < N; i++){
        sum += abs(A.at(i) - B.at(i));
    }

    cout << sum << endl;
    return 0;
}