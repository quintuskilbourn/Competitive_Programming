#include <iostream>
#include <math.h>

using namespace std;

int filt(int num){
	int cnt=0;
	while(num){
		if(!(num%5)||!(num&1)){//could improve by going from most significant digit
			return cnt;
		}
		cnt++;//checks on what digit it went wrong
		num/=10;
	}
	return -1;
}

bool checkPrime(int num){
	if(num&1){
		int i =3;
		while(i*i<num){
			if(!(num%i)){
				return false;
			}
			i+=2;
		}
	}else{
		return false;
	}
	return true;
}

bool checkCirclePrime(int num){
	int cnt=0;
	int test = num;
	// cout<<"check: "<<num<<endl;
	while(test){
		cnt++;
		test/=10;
	}
	int front;
	int bod = pow(10,cnt-1);
	for(int i=0;i<cnt;i++){
		// cout<<"perm: "<<num<<endl;
		if(!checkPrime(num)){
			return false;
		}
		num = num/bod + (num%bod)*10;
	}

	return true;
}


int main(){
	int a,b;
	while(cin>>a){
		if(a<0){
			break;
		}
		if(!(a&1)){//even
			a++;
		}

		cin>>b;
		int check;
		int cnt=0;
		int num=a;
		while(num<=b){
			if(!(num&1)){
				num++;
			}
			check = filt(num);
			// cout<<"num: "<<num<<endl;
			// cout<<"skip: "<<check<<endl<<endl;

			if(check<0){
				if(checkCirclePrime(num)){
					// cout<<"!!!!!!! "<<num<<endl;

					cnt++;
					// cout<<num<<endl;
				}
				num+=2;//skip evens
			}else{
				int rem=pow(10,check);
				num = (num/rem)*rem + (1111111111111111%(rem*10));
			}
		}
		if(cnt>1)
			cout<<cnt<<" Circular Primes."<<endl;
		else if(cnt==1){
			cout<<cnt<<" Circular Prime."<<endl;
		}
		else
			cout<<"No Circular Primes."<<endl;
	}

	return 0;
}
