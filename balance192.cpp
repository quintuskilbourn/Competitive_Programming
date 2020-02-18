#include <iostream>
#include <string>

using namespace std;

int isBalanced(){ //DFS
  int l,wl,r,wr;
  cin>>wl>>l>>wr>>r;
  if(wl==0){
    wl = isBalanced();
    if(wl<0){
      return -1;
    }
  }
  if(wr==0){
    wr = isBalanced();
    if(wr<0){
      return -1;
    }
  }
  if(l*wl == r*wr){
    return wl+wr;
  }else{
    return -1;
  }
}

int main(){
  int num;
  string in;
  cin>>num;
  for(int i = 0; i<num; i++){
    if(isBalanced()<0){
      cout<<"NO"<<endl;
    }else{
      cout<<"YES"<<endl;
    }
    if(i!=num-1){
      cout<<endl;
      getline(cin,in);

      getline(cin,in);
      while(in[0]!='\n' && in[0]!='\0'){ //in case -1 is returned before the end of the mobile we need to get rid of the extra lines.
        getline(cin,in);
      }
    }
  }
}
