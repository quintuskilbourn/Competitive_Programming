#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>

using namespace std;
class Node{
	public:
		int i;
		int j;
		int d;
		Node(int i,int j,int d){
			this->d=d;
			this->i=i;
			this->j=j;
		}
		bool operator<(const Node& other)const {//min priority queue
			return d > other.d;
		}
};
priority_queue <Node> q;
int d[125][125];
int w[125][125];

void relax(int i1,int j1,int i2, int j2){
	if(d[i2][j2]>d[i1][j1]+w[i2][j2]){
		d[i2][j2]=d[i1][j1]+w[i2][j2];
		// cout<<d[i2][j2]<<endl;
		q.push(Node(i2,j2,d[i2][j2]));
	}
}

int main(){
	int n;
	int in;
	int cnt=1;
	while(cin>>n){
		if(n==0){
			return 0;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>w[i][j];
				d[i][j] = INT_MAX;
			}
		}
		q = priority_queue<Node>();
		q.push(Node(0,0,w[0][0]));
		d[0][0]=w[0][0];
		while(!q.empty()){
			Node rt = q.top();
			// cout<<rt.i<<" "<<rt.j<<" "<<rt.d<<endl;
			if(rt.i==n-1 && rt.j==n-1){
				break;
			}
			q.pop();
			if(rt.i>0){
				relax(rt.i,rt.j,rt.i-1,rt.j);
			}
			if(rt.i<n-1){
				relax(rt.i,rt.j,rt.i+1,rt.j);
			}
			if(rt.j>0){
				relax(rt.i,rt.j,rt.i,rt.j-1);
			}
			if(rt.j<n-1){
				relax(rt.i,rt.j,rt.i,rt.j+1);
			}

		}
		cout<<"Problem "<<cnt<<": "<<d[n-1][n-1]<<endl;
		cnt++;
	}

	return 0;
}
