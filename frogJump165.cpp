#include <map>
#include <queue>
#include <iostream>
#include <utility>
#include <stdlib.h>     /* abs */
#include <math.h>
#include <float.h>
#include <iomanip>

using namespace std;

float find_dist(pair<float,float> a, pair<float,float> b){
  return sqrt(pow(abs(a.first-b.first),2)+pow(abs(a.second-b.second),2));
}

pair<float,float> find_top(map<pair<float,float>,bool>& seen, map<pair<float,float>,float>& dist){ //basically priority queue
  float min = FLT_MAX;
  pair<float,float> nx = make_pair(-1,-1);
  for(map<pair<float,float>,float>::iterator iter = dist.begin(); iter != dist.end(); ++iter){
    if(iter->second<min&&!seen[iter->first]){
      min = iter->second;
      nx = iter->first;
    }
  }
  return nx;
}

void relax(map<pair<float,float>,bool>& seen, map<pair<float,float>,float>& dist, pair<float,float> root){
  for(map<pair<float,float>,float>::iterator iter = dist.begin(); iter != dist.end(); ++iter){
    pair<float,float> curr = iter->first;
    if(!seen[curr]){
      dist[curr] = min(dist[curr],max(dist[root],find_dist(curr,root)));
    }
  }
}

int main(){
  cout << setprecision(3)<< fixed;
  int in,cnt=0;
  float a,b;
  cin>>in;
  while(in!=0){
    cnt++;
    cout<<"Scenario #"<<cnt<<endl;
    map<pair<float,float>,bool> seen;
    map<pair<float,float>,float> dist;
    cin>>a>>b;
    pair<float,float> start = make_pair(a,b);
    seen[start]=0;
    dist[start]=0;
    cin>>a>>b;
    pair<float,float> end = make_pair(a,b);
    seen[end]=0;
    dist[end]=FLT_MAX;

    if(in == 2){
      cout<<"Frog Distance = "<<find_dist(start,end)<<endl<<endl;
    }else{
      for(float i =0;i<in-2;i++){
        cin>>a>>b;
        pair<float,float> hold = make_pair(a,b);
        seen[hold]=0;
        dist[hold]=FLT_MAX;
      }
      while(1){
        pair<float,float> root = find_top(seen,dist);
        if(root==end){
          cout<<"Frog Distance = "<<dist[end]<<endl<<endl;
          break;
        }
        seen[root] = 1;
        relax(seen,dist,root);
      }
    }
    cin>>in;
  }

  return 0;
}
