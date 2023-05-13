//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        map<int,int>mp;
        int isZero = 0, ans = 1;
        if(arr[0] == 0)
        {
            isZero = 1;
            ans = 0;
        }
        for(int i = 1; i<n; i++)
        {
            mp[arr[i]]++;
            if(isZero && arr[i] == 0) continue;
            else if(isZero)
            {
                ans++;
                isZero = 0;
            }
            else if(arr[i] == 0) isZero = 1;
        }
        if(mp[0] == 0) return -1;
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends