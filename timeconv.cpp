#include <iostream>
using namespace std;

int main(){
    string pukul;
    cin >> pukul;
    
    int jam= ((pukul[0]-48)*10)+(pukul[1]-48);
    
    if(pukul[8]=='A' && jam==12){
        jam=0;
    } else if(pukul[8]=='P' && jam!=12){
        jam+=12;
    }
    cout << (jam <10 ? "0":"") << jam;
    for(int i=2; i<8; i++ ){
        cout << pukul[i];
    }
    
    return 0;
}