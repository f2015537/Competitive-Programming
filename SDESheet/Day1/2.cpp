#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v = {1,2,3};
	reverse(v.begin(),v.end());
	// cout<<v[0]<<v[1]<<v[2];
	auto it = v.begin() + 2;
	cout<<*it;
}