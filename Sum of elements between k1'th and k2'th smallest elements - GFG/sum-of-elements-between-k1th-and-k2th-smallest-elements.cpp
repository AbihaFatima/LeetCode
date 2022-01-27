// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long kthSmallest(long long a[],long long &n, long long k){
        priority_queue<long long>maxh;
        long long i;
        for(i=0;i<n;i++){
            maxh.push(a[i]);
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        long long smallest = maxh.top();
        return smallest;
    }
    long long sumBetweenTwoKth( long long a[], long long n, long long k1, long long k2)
    {
        // Your code goes here
        long long first = kthSmallest(a, n, k1);
        long long second = kthSmallest(a, n, k2);
        long long cost =0;
        long long i;
        for(i=0;i<n;i++){
            if(a[i]>first && a[i]<second) 
            {
                cost += a[i];
            }
        }
        return cost;
        
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends