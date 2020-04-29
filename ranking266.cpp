#include <iostream>
#include <queue>
#include <bitset>

using namespace std;

int main(){
	int n,m;

	while(cin>>n>>m){
		bitset<101> w[101];
		for(int i =0;i<n;i++)
			w[i].reset();
		// memset(g,0,sizeof(bool)*100*100);
		int win,lose;
		for(int i=0;i<m;i++){
			cin>>win>>lose;
			w[win][lose]=1;
			// l[lose][win]=1;
		}
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				if(w[v][u]){
					w[v] |= w[u];
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			int cmps = 0;
			for(int j=1;j<=n;j++){
				// cout<<i<<" "<<count(l,i)<<" + "<<count(w,i)<<endl;
				if(w[i][j]||w[j][i]){
					cmps++;
				}
			}
			if(cmps==n-1)
				cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
