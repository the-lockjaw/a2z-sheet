#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	if(n<=1){
		cout<<n<<endl;
	}else{
		int prev = 1, prev2 = 0, ans;
		for(int i = 2; i < n; i++){
			ans = prev + prev2;
			prev2 = prev;
			prev = ans;
		} 
		cout<<ans<<endl;
	}
}