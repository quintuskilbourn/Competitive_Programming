#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int main(){
	long dp[1000001];
	int m,n;
	while(cin>>n>>m){
		memset(dp,0,sizeof(long)*1000001);
		dp[0]=1;
		for(long val=1;val<=n;val*=m){
			for(int j=1;j<=n;j++){
				if(val>j){
					j+= val-j-1;
				}else{
					dp[j] = (dp[j]+dp[j-val])%1000000007;
				}
			}
			// cout<<val<<" "<<dp[n]<<endl;

		}
		cout<<dp[n]<<endl;
		// cout<<"----"<<endl;
	}
	return 0;
}
