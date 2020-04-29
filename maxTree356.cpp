#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <utility>
#include <string.h>

using namespace std;

int p[501];
int maximum = -1;
class Edge {
public:
	int u;
	int v;
	int w;
	Edge(int from, int to, int weight) {
		u = from;
		v = to;
		w = weight;
	}
};
int find(int element) {
	if (p[element] < 0)
		return element;
	return p[element] = find(p[element]);
}
void Unionp(int r1, int r2) {
	p[r1] += p[r2];//add number of nodes (negative)
	p[r2] = r1;
	if (p[r1] < maximum)
		maximum = p[r1];
}
void Union(int element1, int element2) {
	int root1 = find(element1);
	int root2 = find(element2);
	if (root1 == root2)
		return;
	if (p[root1] < p[root2]) {//root1 has more members
		Unionp(root1, root2);
	}
	else {
		Unionp(root2, root1);
	}
}


int main(){
	int n,m;

	while(cin>>n>>m){
		int v1,v2,w,max;
		if(n==0 && m==0){
			return 0;
		}
		memset(&p, -1, sizeof(int)*(501));
		maximum=-1;
		map<pair<int,int>,int > edges;
		for(int i=0;i<m;i++){//can count how many max there are if need to improve speed
			cin>>v1>>v2>>w;
			if(!i){
				max=w;
			}
			if(w>=max){
				max=w;
				edges[make_pair(v1,v2)]=w;
			}
		}
		// int size=0;
		map<pair<int,int>, int>::iterator it;
		for(it=edges.begin();it!=edges.end();it++){
			if(it->second == max){
				Union(it->first.first,it->first.second);
			}
		}
		cout<<maximum*(-1)<<endl;
	}


	return 0;
}


//
// void q_neighbours(int max,int n, int v1, bool seen[500], queue<int> &q, int g[500][500]){
// 	for(int i =0;i<n;i++){
// 		if (g[v1][i]==max && !seen[i]){
// 			q.push(i);
// 			seen[i]=1;
// 		}
// 	}
// }
//
// int spanSize(int max, int n, vector<pair<int,int> > &v, int g[500][500], bool seen[500]){
// 	queue<int> q;
// 	pair<int,int> start = v.at(0);
// 	int vmax1= start.first;
// 	int vmax2 = start.second;
// 	q.push(vmax1);
// 	q.push(vmax2);
// 	seen[vmax1]=seen[vmax2]=true;
// 	int cnt=0;
// 	while(!q.empty()){
// 		int curr = q.front();
// 		//cout<<"Front of Q: "<<curr<<endl;
// 		q.pop();
// 		cnt++;
// 		q_neighbours(max,n,curr,seen,q,g);
// 	}
// 	return cnt;
//
// }
//
// int main(){
// 	int n,m;
//
// 	while(cin>>n>>m){
// 		if(n==0 && m==0){
// 			return 0;
// 		}
// 		int g[500][500]={0};
// 		bool seen[500]={0};
// 		int v1,v2,w,vmax1,vmax2,max=0;
// 		vector<pair<int,int> > v;
// 		for(int i=0;i<m;i++){//can count how many max there are if need to improve speed
// 			cin>>v1>>v2>>w;
// 			if(w>max){
// 				v.clear();
// 				max=w;
// 				v.push_back(make_pair(v1,v2));
// 			}else if(w==max){
// 				// cout<<"adding: "<<v1<<","<<v2<<endl;
// 				v.push_back(make_pair(v1,v2));
// 			}
// 			g[v1][v2]=w;
// 			g[v2][v1]=w;
// 		}
// 		int size=0;
// 		while(!v.empty()&&v.size()>=size){
// 			// cout<<"big loop"<<endl;
// 			int currSize = spanSize(max,n,v,g,seen);
// 			if(currSize>size){
// 				size=currSize;
// 			}
// 			for(int i=0;i<v.size();i++){
// 				if(seen[v.front().first]){
// 					// cout<<v.front().first<<" has been seen "<<endl;
// 					v.erase(v.begin());
// 				}else{
// 					// cout<<v.front().first<<" has NOT been seen "<<endl;
// 					break;
// 				}
// 			}
// 		}
// 		cout<<size<<endl;
// 	}
//
//
// 	return 0;
// }
