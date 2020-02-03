#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <math.h>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

string inToPre(string input){ //convert infix to postfix (from equation190)
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
  map['A']=0;
  map['B']=0;
  map['C']=0;
  map['D']=0;
  map['E']=0;
  map['F']=0;
  char nx;
  stack<char> s;

  string res,hold;

  int len = input.length();
  for(int i =0;i<len;i++){
    nx = input[i];

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
    while(!s.empty()){
      res+=s.top();
      s.pop();
    }

      return res;
    }

int postEval(string input){ //evaluate postfix
  stack<int> s;
  map<char,int> map;
  map['+'] = -2;
  map['*'] = -1;
  map['0']=0;
  map['1']=1;
  map['2']=2;
  map['3']=3;
  map['4']=4;
  map['5']=5;
  map['6']=6;
  map['7']=7;
  map['8']=8;
  map['9']=9;
  map['A']=10;
  map['B']=11;
  map['C']=12;
  map['D']=13;
  map['E']=14;
  map['F']=15;
  int len = input.length();
  int i=0;
  int a,b;
  while(i!=len){
    if(map[input[i]]<-1){
      a = s.top();
      s.pop();
      b = s.top();
      s.pop();
      s.push(a+b);
    }else if(map[input[i]]<0){
      a = s.top();
      s.pop();
      b = s.top();
      s.pop();

      s.push(a*b);
    }else{
      s.push(map[input[i]]);
    }
    i++;
  }

  return s.top();
}

string calcHex(int input){ //convert dec to hex
  map<int,char> map;
  map[0]='0';
  map[1]='1';
  map[2]='2';
  map[3]='3';
  map[4]='4';
  map[5]='5';
  map[6]='6';
  map[7]='7';
  map[8]='8';
  map[9]='9';
  map[10]='A';
  map[11]='B';
  map[12]='C';
  map[13]='D';
  map[14]='E';
  map[15]='F';
  string res;
  while(input>15){
    res+=map[input%16];
    input = floor(input/16);

  }
  res+=map[input];
  reverse(res.begin(),res.end());
  return res;
}

int main(){
  string hold;
  while(getline(cin,hold)){
    cout<<calcHex(postEval(inToPre(hold)))<<endl;
  }

  return 0;
}
