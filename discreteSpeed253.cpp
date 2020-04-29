#include <queue>
#include <iostream>
#include <map>
#include <iomanip>
#include <string.h>

using namespace std;

class Node{
  public:
    int index;
    int speed;
    int from;
    double time;
    Node();
    Node(int ind,int s,double t,int fr);
    bool operator<(const Node &other)const {
      return time>other.time;
    }
};

Node::Node(int ind,int s,double t,int fr){
  index=ind;
  speed=s;
  time=t;
  from=fr;
}

int main(){
  cout<<setprecision(5)<<fixed;
  int dist[31][31];
  int limit[31][31];
  bool seen[31][31][30]; //to,from, speed
  int V,E,start,end,e1,e2,d,l;
  while(1){
    memset(limit, 0, sizeof(limit));
    memset(dist, 0, sizeof(dist));
    memset(seen, 0, sizeof(seen));
    cin>>V>>E;
    if(V==0){//&&E==0
      return 0;
    }
    cin>>start>>end;
    if(E==0){
      cout<<"unreachable"<<endl;
      continue;
    }
    V+=1;
    for(int i=0;i<E;i++){
      cin>>e1>>e2>>d>>l;
      dist[e1][e2]=d;
      dist[e2][e1]=d;
      limit[e1][e2]=l;
      limit[e2][e1]=l;
    }

    priority_queue<Node> q;
    q.push(Node(start,0,0,-1));
    bool flag=1;
    while(!q.empty()){
      Node root = q.top();
      q.pop();
      if(root.index==end && root.speed==1){
        cout<<root.time<<endl;
        flag=0;
        break;
      }
      int ind = root.index;
      double time = root.time;
      int from = root.from;
      for(int j =-1;j<2;j++){
        int speed = root.speed+j;
        if(speed<1){
          continue;
        }
        for(int i=0;i<V;i++){
          if(speed<=limit[ind][i]&&!seen[i][ind][speed]&&i!=from){
            double newT = time+((double)dist[ind][i])/((double)speed);
            // cout<<"EnQ: "<<i<<","<<speed<<","<<newT<<" "<<endl;
            q.push(Node(i,speed,newT,ind));
            seen[i][ind][speed]=1;
          }
        }
      }
    }
    if(flag){
      cout<<"unreachable"<<endl;
    }
  }

  return 0;
}
