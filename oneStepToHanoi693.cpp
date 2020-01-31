#include <iomanip>
#include <math.h>
#include <iostream>

using namespace std;

int main(){
  int disk,cnt;
  while(cin>>disk){
    cnt = 0;
    for(int i = 0; i<disk;i++){
      cnt+=pow(3.0,i)*2;
    }
    cout<<cnt<<endl;
  }

  return 0;
}
