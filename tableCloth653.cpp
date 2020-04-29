#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int n,m;
	bool table[51][51];
	bool flag;
	while(cin>>n>>m){
		flag=false;
		if(!n && !m){
			break;
		}
		for(int i =0;i<n;i++){
			for(int j =0;j<m;j++){
				cin>>table[i][j];
			}
		}
		if(table[0][0] || table[n-1][0]||table[0][m-1]||table[n-1][m-1]){
			cout<<1<<endl;
			continue;
		}

		for(int i=0;i<n;i++){
			if(table[i][0]||table[i][m-1]){
				cout<<2<<endl;
				flag=true;
				break;
			}
		}
		if(flag){
			continue;
		}
		for(int i=0;i<m;i++){
			if(table[0][i]||table[n-1][i]){
				cout<<2<<endl;
				flag=true;
				break;
			}
		}
		if(flag){
			continue;
		}
		cout<<4<<endl;

	}

	return 0;
}
