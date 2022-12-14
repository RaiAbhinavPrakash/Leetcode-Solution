//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
    string BalancedString(int N) {
        int r = N/26;
        string s = "";
        while(r--)
        {
            char ch = 'a';
            for(int i = 0; i<26; i++)
            {
                s += ch;
                ch++;
            }
        }
        int y = N;
        N = N%26;
        if(N%2 == 0)
        {
            string s1 = "", s2 = "";
            N /= 2;
            char ch = 'a';
            for(int i = 0; i<N; i++)
            {
                s1 += ch;
                ch++;
            }
            ch = 'z';
            for(int i = 0; i<N; i++)
            {
                s2 += ch;
                ch--;
            }
            reverse(s2.begin(), s2.end());
            s1 += s2;
            s += s1;
            return s;
        }
        else
        {
            string s1 = "", s2 = "";
            char ch = 'a';
            int sum = 0, k = y;
            while(k != 0)
            {
                int rem = k%10;
                sum += rem;
                k /= 10;
            }
            if(sum%2 == 0)
            {
                for(int i = 0; i<(N+1)/2; i++)
                {
                    s1 += ch;
                    ch++;
                }
                ch = 'z';
                for(int i = 0; i<(N-1)/2; i++)
                {
                    s2 += ch;
                    ch--;
                }
                reverse(s2.begin(), s2.end());
                s1 += s2;
                s += s1;
                return s;
            }
            else
            {
                for(int i = 0; i<(N-1)/2; i++)
                {
                    s1 += ch;
                    ch++;
                }
                ch = 'z';
                for(int i = 0; i<(N+1)/2; i++)
                {
                    s2 += ch;
                    ch--;
                }
                reverse(s2.begin(), s2.end());
                s1 += s2;
                s += s1;
                return s;
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends