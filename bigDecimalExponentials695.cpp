#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define FOR(x,y,z) for(int x=y;x<z;x++)
//assume input is rev string
string mult(string s1, string s2){
	int len1=s1.length();
	int len2=s2.length();
	string ans (len1+len2+1,'0');
	int tmp;
	int carry=0;
	FOR(i,0,len1){
		FOR(j,0,len2){
			tmp = (s1[i]-'0')*(s2[j]-'0')+carry+(ans[i+j]-'0');
			ans[i+j] = tmp%10+'0';
			carry = tmp/10;
		}
		ans[i+len2]='0'+carry;
		carry=0;
	}
	int i;
	return ans;
}

//assume input is revstring
string exponentiate(string num, int pow){
	// cout<<"exponentiate "<<num<<" "<<pow<<endl;
	if(pow==1){
		return num;
	}
	string ans = exponentiate(num,pow>>1);
	if(pow&1){
		return mult(mult(ans,ans),num);
	}else{
		return mult(ans,ans);
	}
}

int main(){
	string base;
	int pow;
	while(cin>>base>>pow){
		int len = base.length();
		int end;
		string num="";
		//find trailing zeros
		for(int i=len-1;i>=0;i--){
			if(base[i]!='0'){
				end=i;
				break;
			}
		}
		int tail;
		//copy inverted num and find tail length
		for(int i=end;i>=0;i--){
			if(base[i]=='.'){
				tail=end-i;
			}else{
				num+=base[i];
			}
		}
		//do exponentiation
		string ans = exponentiate(num,pow);

		tail*=pow;
		bool flag=false;//to avoid leading 0s
		for(int i=ans.length()-1;i>=tail;i--){
			if(flag||ans[i]!='0'){
				cout<<ans[i];
				flag=true;
			}
		}
		if(tail)
			cout<<'.';
		for(int i = tail-1;i>=0;i--){
			cout<<ans[i];
		}
		cout<<endl;
	}

	return 0;
}
