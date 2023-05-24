#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	string S;
	cin >> N >> S;

	bool flag;
	//N==2なら最初と最後が同じなら良い
	if(N == 2){
		if(S.at(0) == S.at(N-1)){
			flag = true;
		}else{
			flag = false;
		}

	//2 < N
	}else{
		//左端をBまたは右端をAにするのは不可能
		if(S.at(0)=='A' && S.at(N-1)=='B'){
			flag = false;

		//奇数なら上以外の場合ABAB..ABと並べ、左端にBまたは右端にAを置くだけ
		}else if(N%2 == 1){
			flag = true;

		//A---B以外で偶数の場合
		}else{
			//真ん中をAAA...ABとなるように埋め、最後にat(0)とat(1)でABとすれば必ずできる
			if(S.at(0)=='A' && S.at(N-1)=='A'){
				flag = true;

			}else if(S.at(0)=='B' && S.at(N-1)=='A'){
				/*S.at(N-2)が必ずAとなるので(N-2,N-1でABとするため)
				S.at(1)がAなら一つ上のパターンで必ずできる
				そして1,2でABとおけばA--Aで挟むことができる*/
				flag = true;

			}else if(S.at(0)=='B' && S.at(N-1)=='B'){
				//B--Aパターンと同じ理由から
				flag = true;

			}

		}
	}

	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;

}