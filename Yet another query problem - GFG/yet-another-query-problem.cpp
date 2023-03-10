//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &a, vector<vector<int>> &q) {
        vector<int>ans;
        
        vector<int>v;
        for(int i = 0; i<N; i++)
        {
            int k = a[i];
            int c = 0;
            for(int j = i; j<N; j++)
            {
                if(a[j] == k) c++;
            }
            v.push_back(c);
        }
        
        for(int i = 0; i<num; i++)
        {
            int cnt = 0;
            for(int j = q[i][0]; j<=q[i][1]; j++)
            {
                if(v[j] == q[i][2]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends