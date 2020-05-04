#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

struct suffix{
	int index;
	int rank[2];
};

int cmp(struct suffix a, struct suffix b)
{
    if(a.rank[0] == b.rank[0]){
		if(a.rank[1] < b.rank[1]){
			return 1;
		}else{
			return 0;
		}
	}else{
		return (a.rank[0] < b.rank[0])? 1: 0;
	}

}

void printSuffs(struct suffix suff[], string in){
	int len =in.size();
	cout<<"---------"<<endl;
	for(int i=0;i<len;i++){
		// cout<<"rank0: "<<suff[i].rank[0]<<endl;
		// cout<<"rank1: "<<suff[i].rank[1]<<endl;
		for(int j=suff[i].index;j<len;j++){
			cout<<in[j];
		}
		cout<<endl;
	}
	cout<<"---------"<<endl;
}

void kasai(struct suffix suffs[],string in){
	int k=0;
	int max=0;
	int len = in.size();
	int ord[len];
	int lcp[1001]={0};
	for(int i=0;i<len;i++){
		ord[suffs[i].index]=i;
	}

	for(int i=0;i<len;i++){
		if(ord[i]==len-1){
			k=0;
			continue;
		}
		int j = suffs[ord[i]+1].index;//next in lexicographical order
		while(i+k<len && j+k<len && in[i+k]==in[j+k]){
			k++;
		}
		lcp[i]=k;
		if(k>max){
			max=k;
		}
		if(k>0){
			k--;
		}
	}

	int cnt=0;
	int max_cnt=0;
	int ind;
	for(int i=0; i<len; i++){
		if(lcp[suffs[i].index]==max){
			cnt++;
		}else{
			if(cnt){
				break;
			}
			cnt=0;
		}
		if(cnt>max_cnt){
			max_cnt=cnt;
			ind = suffs[i].index;
		}
	}
	if(!max){
		cout<<"No repetitions found!"<<endl;
		return;
	}
	for(int i=0;i<max;i++){
		cout<<in[ind+i];
	}
	cout<<" "<<max_cnt+1<<endl;
}

int main(){
	// std::ofstream out("out.txt");
   // std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
   // std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	int len,n;
	string in;
	cin>>n;
	while(n>0){
		n--;
		int ord[1001] = {0};
		cin>>in;
		len=in.size();
		struct suffix suffs[len];
		for(int i=0;i<len;i++){
			suffs[i].index=i;
			suffs[i].rank[0] = in[i]-'A';
			suffs[i].rank[1] = (i<len-1)? in[i+1]-'A': -1;
		}

		sort(suffs,suffs+len,cmp);
		for(int l=2;l<len;l*=2){
			// cout<<"l: "<<l<<endl;
			// printSuffs(suffs,in);
			int rank=0;
			int prev = suffs[0].rank[0];
			ord[suffs[0].index]=0;
			suffs[0].rank[0]=0;
			for(int i=1;i<len;i++){
				if(suffs[i].rank[0]==prev && suffs[i-1].rank[1]==suffs[i].rank[1]){
					suffs[i].rank[0]=rank;
				}else{
					rank++;
					prev = suffs[i].rank[0];
					suffs[i].rank[0]=rank;
				}
				ord[suffs[i].index]=rank;
			}
			for(int i=0;i<len;i++){
				// cout<<"len: "<<in.size()<<endl;
				// cout<<"rank1 loop: "<<(suffs[i].index+l<len)? ord[suffs[i].index+l]: -1<<endl;
				suffs[i].rank[1]=(suffs[i].index+l<len)? ord[suffs[i].index+l]: -1;
			}
			sort(suffs,suffs+len,cmp);
		}
		// printSuffs(suffs,in);
		kasai(suffs,in);
	}
	// std::cout.rdbuf(coutbuf); //reset to standard output again

	return 0;
}
