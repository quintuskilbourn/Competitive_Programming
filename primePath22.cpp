#include <bitset>
#include <iostream>
#include <queue>



using namespace std;
const int N = 10000;
int prime[1229];
bitset<N> p;

int makeNum(int num, int i, int d){
  switch(i){
    case 0: return (num/10)*10+d;
    case 1: return (num/100)*100+d*10+(num%10);
    case 2: return (num/1000)*1000+d*100+(num%100);
    case 3: return (num/10000)*10000+d*1000+(num%1000);
    default: return -1;
  }
}

void findP(){
  int count=0;
  p[0]=0;
  p[1]=0;
  p[2]=1;
  prime[count++]=2;
  // p.flip();
  for(int i=3; i<=N; i+=2){
    if (p[i] == 0){
      prime[count++]=i;			//not filtered, then prime
    }
    for(int j=1; j<count  &&  i*prime[j] <= N; j++){
      p[i*prime[j]] = 1;		//i*prime[j] is filtered.
      if(i%prime[j]==0){
        break;
      }
    }
  }
}

int main(){
  findP();
  int start,end,root,nw,whole,level,num;
  bitset<N> seen;

  bool flag;
  cin>>num;
  while(num){
    // cout<<"Inside"<<endl;
    queue<int> q;
    num--;
    cin>>start>>end;
    if (start==end){//case: same number
      cout<<0<<endl;
      continue;
    }
    bool flag=0;
    q.push(start);
    seen.reset();
    seen[start]=1;
    while(!q.empty()){
      root = q.front();
      q.pop();
      for(int i=0;i<4;i++){
        for(int d=0;d<10;d++){
          if(i==3 && d==0){
            continue;
          }
          whole = makeNum(root,i,d);
          nw = whole%10000;
          level = whole/10000 +1;

          if(nw%2==1 && !p[nw] && !seen[nw]){
            if(nw==end){
              cout<<level<<endl;
              flag=1;
              break;
            }
            q.push(whole+10000);
            seen[nw]=1;
          }
        }
        if(flag){
          break;
        }
      }
      if(flag){
        break;
      }
    }
    if(!flag){
      cout<<"Impossible"<<endl;
    }
  }

  return 0;
}
