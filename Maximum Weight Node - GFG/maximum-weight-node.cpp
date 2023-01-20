//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      map<int,int>mp;
      for(int i = 0; i<Edge.size(); i++)
      {
          if(Edge[i] == -1) mp[Edge[i]] += 0;
          else mp[Edge[i]] += i;
      }
      int ans = 0, val = 0;
      for(auto it:mp)
      {
          if(it.first<0) continue;
          if(it.second>=val)
          {
              ans = it.first;
              val = it.second;
          }
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends