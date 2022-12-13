//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        for(int i = 0; i<n; i++)
        {
            if(str[i] == '0') str[i] = '1';
            else str[i] = '0';
        }
        int sum = 0, mx = 0, a = -1, b = -1, k = -1;
        for(int i = 0; i<n; i++)
        {
            if(str[i] == '1') sum++;
            else sum--;
            if(sum<0)
            {
                sum = 0;
                k = i;
            }
            if(sum>mx)
            {
                mx = sum;
                a = k;
                b = i;
            }
        }
        if(b == -1) return {-1};
        else return {a+2, b+1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends