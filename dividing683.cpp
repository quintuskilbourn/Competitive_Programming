#include <iostream>
#include <math.h>

using namespace std;


int main(){ //stupid way of doing it, but its still fast enough
	int k,a,b,v,s,d,cnt;
	bool flag;
	while(cin>>k>>a>>b>>v){
		cnt=0;
		s=ceil(a/(float)v);
		while(s>0){
			cnt+=1;
			if(k-1<=b){
				b-=k-1;
				s-=k;
			}else if(b){
				s-=(b+1);
				b=0;
			}else{
				s--;
			}
		}
		cout<<cnt<<endl;

	}
	return 0;
}


// int main(){
// 	int k,a,b,v,s,d;
// 	bool flag;
// 	while(cin>>k>>a>>b>>v){
// 		// cout<<endl<<endl;
// 		flag=false;
// 		if(!a){
// 			cout<<0<<endl;
// 			continue;
// 		}
// 		s = ceil(a/(float)v);
// 		// cout<<"s "<<s<<endl;
// 		if(s==1){
// 			cout<<1<<endl;
// 			continue;
// 		}
// 		d=b/(k-1);
// 		// cout<<"d "<<d<<endl;
// 		for(int i =1;i<=d;i++){
// 			s-=k;
// 			if(s<0){
// 				cout<<i<<endl;
// 				flag=true;
// 				break;
// 			}
// 		}
// 		if(flag){
// 			continue;
// 		}
//
// 		if(b%(k-1)){
// 			s-=((b%(k-1))+1);
// 			cout<<d+1+max(0,s)<<endl;
// 		}else{
// 			cout<<d+s<<endl;
// 		}
//
// 	}
// 	return 0;
// }
