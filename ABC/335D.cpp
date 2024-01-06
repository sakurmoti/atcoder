#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#define TAKAHASHI 1'000'000'000

int main(){
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    int value = 1;
    int row_start = 0, row_end = n - 1;
    int col_start = 0, col_end = n - 1;

    while (value <= n * n) {
        for (int i = col_start; i <= col_end; i++) {
            arr[row_start][i] = value++;
        }
        row_start++;

        for (int i = row_start; i <= row_end; i++) {
            arr[i][col_end] = value++;
        }
        col_end--;

        for (int i = col_end; i >= col_start; i--) {
            arr[row_end][i] = value++;
        }
        row_end--;

        for (int i = row_end; i >= row_start; i--) {
            arr[i][col_start] = value++;
        }
        col_start++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(arr[i][j] == n*n) cout << 'T' << " ";
            else cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
