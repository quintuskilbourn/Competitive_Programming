#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int recMod(int b, int p, int m){
	if(p==1){
		return b;
	}
	int nx;
	nx = recMod(b,p>>1,m);
	nx = (nx*nx)%m;
	if(p&1){//odd
		nx = (nx*b)%m;
	}
	return nx%m;
}

int bigMod(int b, int p, int m){
	b%=m;
	if(m==1){//!!!!!!!! this failed with ||b==0 as other condition
		return 0;
	}else if(p==0||b==1){
		return 1;
	}else{
		return recMod(b,p,m);
	}
}

int main(){
	int b,p,m;
	while(cin>>b>>p>>m){
		cout<<bigMod(b,p,m)<<endl;
	}

	return 0;
}
