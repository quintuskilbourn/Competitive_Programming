#include <iostream>
#include <iomanip>

using namespace std;

bool row[8];
int col[8];
bool d1[15];
bool d2[15];
int num,c,r;
int sol=1;

void queen(int n){
  if(n==c){
    if(n>6){
      cout<<setw(2)<<sol<<"      ";
      sol++;
      for(int j=0;j<7;j++){
        cout<<col[j]+1<<" ";
      }
      cout<<col[7]+1<<endl;
    }else{
      queen(n+1);
    }
    return;
  }
  for(int i = 0; i<8;i++){
    if(row[i]||d2[i+n]||d1[i-n+7]){
      continue;
    }else{
      row[i]=1;
      col[n]=i;
      d1[i-n+7]=1;
      d2[i+n]=1;
      if(n>6){
        cout<<setw(2)<<sol<<"      ";
        sol++;
        for(int j=0;j<7;j++){
          cout<<col[j]+1<<" ";
        }
        cout<<col[7]+1<<endl;
      }else{
        queen(n+1);
      }
      row[i] = 0;
      col[n] = 0;
      d1[i-n+7]=0;
      d2[i+n]=0;
    }
  }

}

int main(){
  cin>>num;
  for(int i = 0; i<num; i++){
    sol=1;
    cin>>r>>c;
    c-=1;
    r-=1;
    col[c] = r;
    row[r] = 1;
    d1[r-c+7] = 1;
    d2[r+c] = 1;
    cout << "SOLN       COLUMN" << endl;
    cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
    queen(0);
    if(i!=num-1){
      cout<<endl;
    }
    for(int j=0;j<8;j++){
      row[j]=0;
      col[j]=0;
    }
    for(int j=0;j<15;j++){
      d1[j]=0;
      d2[j]=0;
    }
  }

  return 0;
}
