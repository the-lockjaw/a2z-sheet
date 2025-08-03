#include<iostream>
#include<vector>
using namespace std;

int fib(vector<int> &dp, int n){
	if(n<=1) return dp[n] = n;
	if(dp[n]!=-1)return dp[n];
	return dp[n] = fib(dp,n-1) + fib(dp,n-2);
}

int main(){
	int n;
	cin>>n;
	vector<int> dp(n+1,-1);
	int ans = fib(dp,n-1);
	for(auto a : dp)cout<<a<<" ";
		cout<<endl;
	cout<<ans<<"\n";
}