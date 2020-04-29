#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <fstream>
#include <cmath>        // std::abs

using namespace std;

class Node{
	public:
		int x;
		int y;
		int ind;
		Node(int xcoord, int ycoord, int i){
			x=xcoord;
			y=ycoord;
			ind=i;
		}
};

bool bfs(bool graph[204][204],int path[204],int s, int t){
	bool seen[204];
   	memset(seen, 0, sizeof(seen));
	queue<int> q;
	q.push(t);
	seen[t]=1;
	while(!q.empty()){
		int nx = q.front();
		q.pop();
		for(int i =0;i<204;i++){//plus two for sink and tap
			if(graph[nx][i]&&!seen[i]){
				if(i==s){	//reached the sink
					path[s]=nx;
					return 1;
				}
				path[i]=nx;
				q.push(i);
				seen[i]=1;
			}
		}
	}
	return 0; //did not reach the sink
}

int fordFulkerson(bool rGraph[204][204], int s, int t)
{
    int parent[204];  // This array is filled by BFS and to store path
    int max_flow = 0;
    while (bfs(rGraph,parent,s,t))
    {
        for (int v=s; v != t; v=parent[v])
        {
            int u = parent[v];
            rGraph[u][v] = 0;
            rGraph[v][u] = 1;
        }

        // Add path flow to overall flow
        max_flow++;
    }

    // Return the overall flow
    return max_flow;
}

int main(){
	// std::ofstream out("out.txt");
    // std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    // std::cout.rdbuf(out.rdbuf());
	int L,W,N,d,cnt=0;
	while(1){
		//get and check test case input
		cnt+=1;
		// if(cnt==139||cnt==261){
		// 	int a =0;
		// }
		scanf("%d %d %d %d",&L,&W,&N,&d);
		if(L==0 && W==0 && N==0 && d==0){
			// std::cout.rdbuf(coutbuf);
			return 0;
		}
		if(d==0 || N==0){
			cout<<"Case "<<cnt<<": "<<0<<endl;
			continue;
		}

		//build graph
		vector<Node> v;
		bool graph[204][204];
		memset(graph,0,sizeof(graph));
		int xcoord,ycoord;
		//let s be 0 and t be N+1
		//apply multi 2 to mimic a limit of 1 on each node (i.e. create an edge)
		for(int i=2;i<=N*2;i+=2){
			scanf("%d %d",&xcoord,&ycoord);
			//check for s and t which are above and below the field
			if(ycoord<=d){
				graph[0][i]=1;
			}
			if(ycoord>=W-d){
				graph[i+1][N*2+2]=1;
			}
			graph[i][i+1]=1;
			//check for overlap to form edges
			for(int j=0;j<v.size();j++){
				if(sqrt(abs(v[j].x-xcoord)*abs(v[j].x-xcoord)+abs(v[j].y-ycoord)*abs(v[j].y-ycoord))<=d*2){ //if neighbours
					if(v[j].y<ycoord){//forward is smaller y to larger y. reverse will be large to small
						graph[v[j].ind+1][i]=1;
					}else{
						graph[i+1][v[j].ind]=1;
					}
				}
			}
			v.push_back(Node(xcoord,ycoord,i));
		}
		cout<<"Case "<<cnt<<": "<<fordFulkerson(graph,N*2+2,0)<<endl;

	}
	return 0;
}
