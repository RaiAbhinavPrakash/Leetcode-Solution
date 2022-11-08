class Solution {
public:
    int reverse(int x) {
        if(x <= INT_MIN || x == 0) return 0;
        string s = to_string(x);
        if(x<0)
        {
            s.erase(s.begin());
        }
        int n = s.size()-1;
        while(s.size()>=1 && s[s.size()-1] == '0')
        {
            s.erase(s.size()-1, 1);
            n--;
        }
        for(int i = 0; i<s.size()/2; i++)
        {
            swap(s[i], s[s.size()-i-1]);
        }
        if(s.size() == 10 && s>"2147483647") return 0;
        if(x<0 && s.size() == 10 && s>"2147483648") return 0;
        int ans = stoi(s);
        if(x<0) ans *= -1;
        return ans;
    }
};