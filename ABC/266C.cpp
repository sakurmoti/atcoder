#include <bits/stdc++.h>
using namespace std;

int main(){
    int Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;

    /*凸であるなら対角線を結んだとき、片方に点が寄ることはない。
    つまりACを結んだ時、B,Dは直線ACで区切られた領域の片方に集まっていなければよい
    これをBDについても言えれば凸であるといえる*/

    bool flag = true;

    //ACを結んだ場合
    if(Ax == Cx){
        /*縦の直線となりy=の形で表せない。
        この場合はBx,DxがAx(またはCx)を境に分かれているか調べればよい*/
        if( (Ax-Bx > 0 && Ax-Dx < 0) || (Ax-Bx < 0 && Ax-Dx > 0)){
            //ok
        }else{
            flag = false;
        }
    }else{
        /*y=の形で表す。y = grad*x + interceptの形*/
        double grad = (double)(Ay-Cy)/(Ax-Cx); //傾き
        double intercept = (double)Ay - Ax*grad; //切片
        //printf("grad=%lf intercept=%lf\n",grad,intercept);

        if( (By < grad*Bx+intercept && Dy > grad*Dx+intercept) || (By > grad*Bx+intercept && Dy < grad*Dx+intercept)){
            //ok
        }else{
            flag = false;
        }
    }

    //BDを結んだ場合
    if(Bx == Dx){
        if( (Bx-Ax > 0 && Bx-Cx < 0) || (Bx-Ax < 0 && Bx-Cx > 0)){
            //ok
        }else{
            flag = false;
        }
    }else{
        double grad = (double)(By-Dy)/(Bx-Dx); //傾き
        double intercept = (double)By - Bx*grad; //切片
        //printf("grad=%lf intercept=%lf\n",grad,intercept);

        if( (Ay < grad*Ax+intercept && Cy > grad*Cx+intercept) || (Ay > grad*Ax+intercept && Cy < grad*Cx+intercept)){
            //ok
        }else{
            flag = false;
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}