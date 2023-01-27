//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        int mx = INT_MIN, mn = INT_MAX, sum = 0, total = 0;
        for(int i = 0; i<num; i++)
        {
            sum += arr[i];
            mx = max(mx, sum);
            if(sum<0) sum = 0;
        }
        for(int i = 0; i<num; i++)
        {
            sum += arr[i];
            total += arr[i];
            mn = min(mn, sum);
            if(sum>0) sum = 0;
        }
        total -= mn;
        if(total == 0) return mx;
        return max(mx, total);
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends