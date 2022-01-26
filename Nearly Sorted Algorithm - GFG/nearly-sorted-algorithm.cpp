#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int n,k,t;
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++) cin>>arr[i];
	    priority_queue<int,vector<int>,greater<int>>minh;
	    vector<int>ans;
	    for(int i=0;i<n;i++){
	        minh.push(arr[i]);
	        if(minh.size()>k){
	            ans.push_back(minh.top());
	            minh.pop();
	        }
	    }
	    while(minh.size()!=0){
	        ans.push_back(minh.top());
	        minh.pop();
	    }
	    for(int i=0;i<ans.size();i++){
	        cout<<ans[i]<<" ";
	    }
	    ans.clear();
	    cout<<endl;
	}
	return 0;
}