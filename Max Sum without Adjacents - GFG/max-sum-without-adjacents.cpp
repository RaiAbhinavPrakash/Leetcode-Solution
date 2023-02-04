//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int f(int *arr, int n, int i, vector<int>&ans)
	{
	    if(i>n) return 0;
	    if(ans[i] != -1) return ans[i];
	    int take = arr[i] + f(arr, n, i+2, ans);
	    int notTake = f(arr, n, i+1, ans);
	    return ans[i] = max(take, notTake);
	}
	
	int findMaxSum(int *arr, int n) {
	    vector<int>ans(n, -1);
	    return max(f(arr, n-1, 0, ans), f(arr, n-1, 1, ans));
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends