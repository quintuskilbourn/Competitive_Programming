#include <iostream>
#include <string>

using namespace std;

string parseAndMeasure(string s){
	int len = s.size();
	string cp="";
	for(int i=0;i<len;i++){
		if('A'<=s[i]&&s[i]<='Z'){
			cp+=s[i]-'A'+'a';
		}else if(('a'<=s[i]&&s[i]<='z')||s[i]=='-'){
			cp+=s[i];
		}else if(i>len/2){
			break; //split in two but second half will be smaller
		}else{
			while(i<len){
				if(('a'<=s[i]&&s[i]<='z')||s[i]=='-'||('A'<=s[i]&&s[i]<='Z')){
					break;
				}
				i++;
			}
			if(i==len){
				break;
			}
			string other = parseAndMeasure(s.substr(i));
			return (cp.size()>=other.size())? cp:other;
		}
	}
	return cp;
}

int main(){
	string maxString;
	int max=0;
	string s;
	int len;
	while(cin>>s){
		if(s=="E-N-D"){
			break;
		}
		if(s.size()<max){
			continue;
		}
		s = parseAndMeasure(s);
		int len=s.size();
		if(len>max){
			max = len;
			maxString=s;
		}
	}
	cout<<maxString<<endl;

	return 0;
}
