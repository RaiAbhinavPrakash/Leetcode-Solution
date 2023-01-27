//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    long long mod = 1e9+7;
	    
		int CountWays(string s){
		    int one = 1, two = 0;
            if(s.size() == 1)
            {
                if(s[0] == '0') return 0;
                else return 1;
            }
            for(int i = 1; i<s.size(); i++)
            {
                if(s[i] == '0')
                {
                    if(s[i-1] != '0' && s[i-1]<='2')
                    {
                        two = one%mod;
                    }
                    else two = 0;
                    one = 0;
                }
                else
                {
                    int temp = one;
                    if(s[i-1] != '0' && s[i-1]<'2')
                    {
                        one = (one+two)%mod;
                        two = temp;
                    }
                    else if(s[i-1] == '2' && s[i]<='6')
                    {
                        one = (one+two)%mod;
                        two = temp;
                    }
                    else if(s[i-1] == '0')
                    {
                        one = two%mod;
                        two = 0;
                    }
                    else if(s[i-1]>'2')
                    {
                        one = (one+two)%mod;
                        two = 0;
                    }
                }
    
                if(one+two == 0) return 0;
            }
            return (one+two)%mod;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends