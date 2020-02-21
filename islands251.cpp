#include <iostream>
#include <queue>

using namespace std;

class coords{
  public:
    int x,y;
    coords(int y, int x);
};

coords::coords(int y, int x){
  this->x = x;
  this->y = y;
}

int main(){
  int col,row,x,y,cnt,X,Y;
  queue<coords> q;
  while(1){
    cnt=0;  //number of islands
    cin>>col>>row;
    if(col==0 && row==0){ //end condition
      return 0;
    }
    bool** map = new bool*[row]; //store map of islands
    for(int i = 0;i<row;i++){
      map[i] = new bool[col];
      for(int j =0;j<col;j++){
        cin>>map[i][j];
      }
    }
    for(y = 0;y<row;y++){
      for(x =0;x<col;x++){
        if(map[y][x]){
          cnt++;
          map[y][x] = 0;
          q.push(coords(y,x));
          while(!q.empty()){  //use BFS to find the island
            coords root = q.front();
            q.pop();
            for(int i =-1;i<2;i++){ //checking surrounding blocks
              for(int j =-1;j<2;j++){
                X = root.x+i;
                Y = root.y+j;
                if(X<col&&X>=0 && Y<row&&Y>=0 &&map[Y][X]){
                  map[Y][X] = 0;
                  q.push(coords(Y,X));
                }
              }
            }
          }
        }
      }
    }
    cout<<cnt<<endl;
    for(int i = 0;i<row;i++){
      delete map[i];
    }
    delete[] map;
  }

  return 0;
}
