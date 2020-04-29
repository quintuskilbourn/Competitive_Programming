#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <utility>
#include <string.h>

using namespace std;

int p[30001];
int maximum = -1;

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
	int num,n,m;
	cin>>num;

	while(num-- >0){
		cin>>n>>m;
		int v1,v2;
		if(n==0 && m==0){
			return 0;
		}
		memset(&p, -1, sizeof(int)*(30001));
		maximum=-1;
		queue<pair<int,int> > edges;
		int max=1;
		for(int i=0;i<m;i++){
			cin>>v1>>v2;
			edges.push(make_pair(v1,v2));
		}
		pair<int,int> tmp;
		for(int i=0;i<m;i++){
	 		tmp = edges.front();
			edges.pop();
			Union(tmp.first,tmp.second);
		}

		cout<<maximum*(-1)<<endl;
	}


	return 0;
}
