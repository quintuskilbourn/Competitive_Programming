#include <iostream>
#include <string>

using namespace std;

int main(){
	int num;
	cin>>num;
	string in;
	for(int i =0;i<num;i++){
		cin>>in;
		int ind;
		for(int x=0;x<in.length();x++){
			char max=' ';
			for(int y=x;y<in.length();y++){
				if(in[y]>max){
					// cout<<"YEE"<<endl;
					max = in[y];
					ind = y;
				}
			}
			cout<<in[ind];
			x=ind;
		}
		cout<<endl;

	}
	return 0;
}
