#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>

//input is 5 ints
//first four integers represent the four cups, the fifth represents the required amount
//each cup can only ever be filled completely (or emptied), except when the pouring cup runs out of water first.

//using a BFS to solve the problem

using namespace std;

class values {
public:
	int vals[5];
  values(int check[5]);
	values(int, int, int, int, int);
};
values::values(int check[5]) {
	for(int i=0;i<5;i++){
    vals[i]=check[i];
  }
}
values::values(int n1, int n2, int n3, int n4, int n5) {
	vals[0] = n1;
	vals[1] = n2;
	vals[2] = n3;
	vals[3] = n4;
  vals[4] = n5;
}


void enter(values v, bool (&seen)[25][25][25][25],queue<values>& q){
  if(!seen[v.vals[0]][v.vals[1]][v.vals[2]][v.vals[3]]){	//Check if we have seen this before to save time and space.
    seen[v.vals[0]][v.vals[1]][v.vals[2]][v.vals[3]] = true;
    q.push(v);
  }
}

values pop(queue<values>& q){
  values f = q.front();
  q.pop();
  return f;
}


int main(){

  int input[5];
  int hold,amt,in;
  int cnt=0;
  int check[5];
  while(cin>>in){
    input[cnt] = in;
    cnt++;
    if(cnt==5){
      bool seen[25][25][25][25];
      memset(seen, 0, 25*25*25*25);
      queue<values> q;
      cnt=0;
      bool flag = 1;
      if(input[4]==0){
        cout<<-1<<endl;
        continue;
      }
      for(int i=0;i<4;i++){
        if(input[i]==input[4]){ //if cup is the same size as the required amt, then just fill that cup;
          cout<<1<<endl;
          flag=0;
          break;
        }
      }
      if(!flag){
        continue;
      }

      for(int i=0;i<4;i++){
        if(input[i]>input[4]){
          flag=0;
        }
      }
      if(flag){       //if none of the cups are big enough to hold the required amount
        cout<<-1<<endl;
        continue;
      }

      enter(values(input[0],0,0,0,1),seen,q);
      enter(values(0,input[1],0,0,1),seen,q);
      enter(values(0,0,input[2],0,1),seen,q);
      enter(values(0,0,0,input[3],1),seen,q);
      while(!q.empty()){
        values el = pop(q);
        for(int i = 0;i<4;i++){	//for each cup
          for(int j = 1;j<4;j++){
            for(int x=0;x<4;x++){
              check[x]=el.vals[x];
            }
            check[4] = el.vals[4]+1;
            hold = (i+j)%4;
            amt = input[hold]-check[hold];
            if(amt>=check[i]){
              check[hold]+=check[i];
              if(check[hold]==input[4]){
                cout<<check[4]<<endl;
                flag=1;
                break;
              }
              check[i]=0;
              enter(values(check),seen,q);
            }else{
              check[i]-= amt;
              check[hold]+=amt;
              if(check[hold]==input[4]||check[i]==input[4]){
                cout<<check[4]<<endl;
                flag=1;
                break;
              }
              enter(values(check),seen,q);
            }
          }
          if(flag){
            break;
          }
          for(int x=0;x<4;x++){
            check[x]=el.vals[x];
          }
          check[4] = el.vals[4]+1;
          check[i] = input[i];
          if(check[i]==input[4]){
            cout<<check[4]<<endl;
            flag=1;
            break;
          }
          enter(values(check),seen,q);
          check[i] = 0;
          enter(values(check),seen,q);
        }
        if(flag){
          break;
        }
      }
      if(!flag){  //reached end of queue but no solution was found
        cout<<-1<<endl;

      }
    }
  }

  return 0;
}
