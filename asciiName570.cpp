#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

int main(){
	string s;
	int num;
	cin>>num;
	for(;num>0;num--){
		cin>>s;
		int total=0;
		if(s.length()>1){
			int last=INT_MAX;
			int alt=INT_MAX;
			int count=0;
			int len = s.length();
			for(int i=0;i<s.length();i++){
				if(s[i]!='A'){
					count++;
					if(last==INT_MAX){
						last=i;
						alt = len-i;
					}else{
						alt = min(last+(len-i)*2 ,min(alt,last*2+len-i));
						last=i;
					}
				}
			}
		// cout<<"last, alt "<<last<<" : "<<alt<<endl;
		  if(count)total+=min(last,alt);
		}
		for(int i =0;i<s.length();i++){
			total+=min(s[i]-'A',26 - s[i] + 'A');//could just use 'M'
		}
		cout<<total<<endl;
	}
	return 0;
}
