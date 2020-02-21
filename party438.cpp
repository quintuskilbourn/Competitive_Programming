#include <iostream>

using namespace std;

#define party(a) (max(0,a-2))

int main(){
  int in;
  cin>>in;
  while(cin>>in){
    cout<<party(in)<<endl;
  }

  return 0;
}
