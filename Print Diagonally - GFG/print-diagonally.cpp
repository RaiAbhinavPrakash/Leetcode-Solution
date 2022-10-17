//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> a)
	{
		vector<int>ans;
		int i = 0, j = 0, k = 0, l = 0;
		while(i<n && j>=0)
		{
		    ans.push_back(a[i][j]);
		  //  cout<<a[i][j]<<"\n";
		    i++;
		    j--;
		    if(i == n)
		    {
		        l++;
		        i = l;
		        j = n-1;
		    }
		    else if(j<0)
		    {
		        i = 0;
		        k++;
		        j = k;
		    }
		}
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends