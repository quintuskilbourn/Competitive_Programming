#include <iostream>
#include <string>
#include <string.h>
#include <fstream>


using namespace std;

int main(){
	string a,b;
	int arr[1001][1001];
	// memset(arr[0],0,sizeof(int)*1001);
	for(int i =0;i<1001;i++){
		arr[0][i]=0;
	}
	while(getline(cin,a)){
		getline(cin,b);
		for(int i=0;i<=a.length();i++){
			for(int j=0;j<=b.length();j++){
				if(i==0||j==0){
					arr[i][j]=0;
				}
				else if(a[i-1]==b[j-1]){
					// cout<<a[i]<<" "<<b[j]<<endl;
					arr[i][j]=arr[i-1][j-1]+1;
				}
				else{
					arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
				}
			}
		}
		cout<<arr[a.length()][b.length()]<<endl;
	}

	return 0;
}
