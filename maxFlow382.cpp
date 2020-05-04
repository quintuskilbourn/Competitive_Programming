#include <iostream>
#include <queue>
#include <string.h>
#include <limits.h>

using namespace std;
#define V 202

int source = 0;
int sink = 201;


bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}

int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];

    int parent[V];  // This array is filled by BFS and to store path

    int max_flow = 0;  // There is no flow initially

    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main(){
	int n,m,u,v,c,b,d,hold;
	int g[V][V];
	while(cin>>n){
		memset(g,0,sizeof(int)*V*V);
		for(int i=1; i<=n; i++){
			cin>>g[i][i+n];
			g[i+n][i]=g[i][i+n];
		}

		cin>>m;
		for(int i=0; i<m; i++){
			cin>>u>>v;
			cin>>g[u+n][v];
		}

		cin>>b>>d;
		for(int i=0;i<b;i++){
			cin>>hold;
			g[source][hold]=INT_MAX;
		}

		for(int i=0;i<d;i++){
			cin>>hold;
			g[hold+n][sink]=INT_MAX;
		}
		cout<<fordFulkerson(g,source,sink)<<endl;

	}

	return 0;
}
