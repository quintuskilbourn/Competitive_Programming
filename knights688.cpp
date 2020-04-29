#include <iostream>
#include <queue>

using namespace std;

class coords{
  public:
    int x,y,level;
    coords(int x, int y, int level);
};

coords::coords(int x, int y, int level){
  this->x = x;
  this->y = y;
  this->level = level;
}

bool check(char (&board)[8][8],int x, int y){
  if(x*y<0||x>7||y>7){
    return 0;
  }
  if(board[x][y]=='@'){
    return 1;
  }
  if(board[x][y]=='-'){ //so we don't check the same positions over and over
    board[x][y]='*';
    return 1;
  }
  return 0;
}

bool enQ(char (&board)[8][8],int x, int y,int level,queue<coords>& q){
  if(check(board,x,y)){
    if(board[x][y]=='@'){
      cout<<level+1<<endl;
      return 1;
    }
    // cout<<"Push: "<< x<<y<<level+1<<endl;

    q.push(coords(x,y,level+1));
  }
  return 0;
}

int main(){
  int num,x,y;
  bool flag;
  char in;
  cin>>num;
  char board[8][8];
  int total = num+1;
  while(num){
    flag=0;
    cout<<"Case "<<total-num<<": ";
    num--;
    queue<coords> q;
    for(int i = 0;i<8;i++){
      for(int j =0;j<8;j++){
        cin>>in;
        board[i][j]=in;
        if(in=='#'){
          q.push(coords(i,j,0));
        }
      }
    }
    while(!q.empty()){  //use BFS to find the island
      coords root = q.front();
      q.pop();
      x=root.x;
      y=root.y;
      // cout<<endl<<"Root: "<<x<<y<<root.level<<endl;
      for(int i =-2;i<3;i+=4){
        for(int j=-1;j<2;j+=2){
          if(enQ(board,x+i,y+j,root.level,q)||enQ(board,x+j,y+i,root.level,q)){
            flag=1;
            break;
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
      cout<<"IMPOSSIBLE"<<endl;
    }
  }


  return 0;
}
