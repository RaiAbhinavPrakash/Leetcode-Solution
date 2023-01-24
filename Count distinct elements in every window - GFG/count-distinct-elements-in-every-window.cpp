//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        queue<int>q1,q2;
        map<int,int>mp;
        int j = 0;
        vector<int>ans;
        for(int i = 0; i<n; i++)
        {
            q1.push(A[i]);
            mp[A[i]]++;
            if(q1.size() == k)
            {
                ans.push_back(mp.size());
                mp[A[j]]--;
                if(mp[A[j]] == 0) mp.erase(A[j]);
                j++;
                q1.pop();
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
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends