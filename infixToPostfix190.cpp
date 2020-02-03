#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <stdio.h>

using namespace std;

int main(){
  map<char,int> map;  //precedence map
  map['*']=3;
  map['/']=3;
  map['+']=2;
  map['-']=2;
  map['(']=1;
  map[')']=1;
  map['0']=0;
  map['1']=0;
  map['2']=0;
  map['3']=0;
  map['4']=0;
  map['5']=0;
  map['6']=0;
  map['7']=0;
  map['8']=0;
  map['9']=0;
  int num;
  char nx;
  cin>>num;
  scanf("%c",&nx);  //remove spaces
  scanf("%c",&nx); //remove spaces
  stack<char> s;

  string res,hold;
  for(int i=0;i<num;i++){

    while(!s.empty()){
      s.pop();
    }
    string res = "";
    while(true){
      getline(cin,hold);
      nx = hold[0];
      if(nx=='\n'||nx=='\0'||nx=='z'){
        break;
      }

      if(map[nx]==0){
        res+=nx;
      }else{
        if(nx==')'){
          while(s.top()!='('){
            res+=s.top();
            s.pop();
          }
          s.pop(); //lose the '('
        }else if(nx=='('){
          s.push(nx);
        }else{
          while(!s.empty()&&map[s.top()]>=map[nx]){
            res+=s.top();
            s.pop();
          }
          s.push(nx);
        }
      }
    }
    cout<<res;
    while(!s.empty()){
      cout<<s.top();
      s.pop();
    }

    if(i!=(num-1)){
        cout<<endl<<endl;
    }else{
      cout<<endl;
    }
  }
  return 0;
}
