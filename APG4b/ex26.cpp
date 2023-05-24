#include <bits/stdc++.h>
using namespace std;

//変数を格納する連想配列
map<char, int> parameter_int;
map<char, vector<int>> parameter_vec;

//calc_vecにcalc_intが配列の終わりを知らせる
bool flag = true;

int calc_int(){
    int num = 0;
    char buf0,buf1; //buf1の一つ前がbuf0に入る

    while(true){
        cin >> buf1;
        if(buf1 == ';'|| buf1 == ',') break;
        else if(buf1 == ']'){
            flag = false;
            break;
        }
        
        if('0'<=buf1 && buf1<='9'){
            if(buf0 == '-'){
                num -= (buf1-'0');
            }else{
                num += (buf1-'0');
            }

        }else if(parameter_int.count(buf1)){
            if(buf0 == '-'){
                num -= parameter_int.at(buf1);
            }else{
                num += parameter_int.at(buf1);
            }

        }else if(buf1=='=' || buf1=='+' || buf1=='-'){
            //cout << "calc : " << buf1 << endl;
        }else{
            //cout << "error1" << endl;
        }

        buf0 = buf1;
    }

    //cout << num << endl;
    return num;
}

vector<int> calc_vec(){
    vector<int> vec;
    char buf0,buf1; //buf1の一つ前がbuf0に入る

    while(true){
        cin >> buf1;
        if(buf1 == ';') break;

        if(buf1 == '['){
            flag = true;
            int i = 0;
            if(vec.size()==0){
                while(flag){
                    vec.push_back(calc_int());
                }

            }else if(buf0 == '-'){
                while(flag){
                    vec.at(i) -= calc_int();
                    i++;
                }
            }else{
                while(flag){
                    vec.at(i) += calc_int();
                    i++;
                }
            }

        }else if(parameter_vec.count(buf1)){
            vector<int> temp = parameter_vec.at(buf1);
            if(vec.size() == 0){
                vec = temp;

            }else if(buf0 == '-'){
                for(int i = 0; i < temp.size(); i++){
                    vec.at(i) -= temp.at(i);
                }
            }else{
                for(int i = 0; i < temp.size(); i++){
                    vec.at(i) += temp.at(i);
                }
            }

        }else if(buf1=='=' || buf1=='+' || buf1=='-'){
            //cout << "calc : " << buf1 << endl;
        }else{
            //cout << "error2" << endl;
        }

        buf0 = buf1;
    }

    //for(int i = 0; i < vec.size(); i++) cout << i << " : " << vec.at(i) << endl;
    return vec;
}

void int_declare(){
    char name;
    cin >> name;

    parameter_int[name] = calc_int(); //連想配列に追加
}

void print_int(){
    int ret = calc_int();
    cout << ret << endl;
}

void vec_declare(){
    char name;
    cin >> name;

    parameter_vec[name] = calc_vec();
}

void print_vec(){
    vector<int> ret = calc_vec();
    cout << "[ "; 
    for(int i = 0; i < ret.size(); i++){
        cout << ret.at(i) << " ";
    }
    cout << "]" << endl;
}

int main(void){
    int N;
    cin >> N;

    string command;
    for(int i = 0; i < N; i++){
        cin >> command;

        if(command == "int"){
            int_declare();

        }else if(command == "print_int"){
            print_int();

        }else if(command == "vec"){
            vec_declare();

        }else if(command == "print_vec"){
            print_vec();

        }

        //cout << "next calc" << endl;
    }

    return 0;
}