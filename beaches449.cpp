#include <iostream>
#include <string>

using namespace std;

int main(){
  char land[50][50];
  char check;
  int col,beach,offset;
  bool flag=false; //flag checks for double empty line. 
  int row = 0;
  string in;
  while(getline(cin,in)){
      if(in[0]=='\n'||in.length()==0){
        if(flag){
          break;
        }
        beach=0;
        for(int r=0;r<row;r++){
          for(int c=1;c<col;c++){
            if(land[r][c]!=land[r][c-1]){
              beach+=1;
            }
          }
        }
        for(int c=0;c<col;c++){
          for(int r=1;r<row;r++){
            if(land[r][c]!=land[r-1][c]){
              // cout<<r<<c<<" "<<r-1<<c<<endl;
              beach+=1;
            }
            offset=(r%2==0)?-1:1;
            if((c+offset)<0||(c+offset)>=col){
              continue;
            }
            if(land[r][c]!=land[r-1][c+offset]){
              // cout<<r<<c<<" "<<r-1<<c+offset<<endl;
              beach+=1;
            }
          }
        }
        cout<<beach<<endl;
        row=0;
        flag=true;

        continue;
      }
      flag=false;

      col = in.length();
      for(int c=0;c<col;c++){
        land[row][c] = in[c];
      }
      row++;
    }
    if(flag){
      return 0;
    }
    beach=0;
    for(int r=0;r<row;r++){
      for(int c=1;c<col;c++){
        if(land[r][c]!=land[r][c-1]){
          // cout<<r<<c<<" "<<r<<c-1<<endl;
          beach+=1;
        }
      }
    }
    for(int c=0;c<col;c++){
      for(int r=1;r<row;r++){
        if(land[r][c]!=land[r-1][c]){
          // cout<<r<<c<<" "<<r-1<<c<<endl;
          beach+=1;
        }
        offset=(r%2==0)?-1:1;
        if((c+offset)<0||(c+offset)>=col){
          continue;
        }
        if(land[r][c]!=land[r-1][c+offset]){
          // cout<<r<<c<<" "<<r-1<<c+offset<<endl;
          beach+=1;
        }
      }
    }

    cout<<beach<<endl;

  return 0;
}
