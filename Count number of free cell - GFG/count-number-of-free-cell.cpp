//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
    vector<long long int> countZero(int n, int k, vector< vector<int>>& arr){
        vector<long long>ans;
        unordered_map<long long,bool>r, c;
        long long count_r = 0, count_c = 0, zeroes = n*n;
        for(int i = 0; i<k; i++)
        {
            if(r[arr[i][0]-1] == false)
            {
                r[arr[i][0]-1] = true;
                zeroes = zeroes-(n-count_c);
                count_r++;
            }
            if(c[arr[i][1]-1] == false)
            {
                c[arr[i][1]-1] = true;
                zeroes = zeroes-(n-count_r);
                count_c++;
            }
            ans.push_back(zeroes);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends