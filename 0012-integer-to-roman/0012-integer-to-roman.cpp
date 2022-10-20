class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        int c = 0;
        while(num)
        {
            int rem = num%10;
            if(c == 0)
            {
                if(rem == 4)
                {
                    ans += "VI";
                }
                else if(rem == 9)
                {
                    ans += "XI";
                }
                else if(rem == 5)
                {
                    ans += "V";
                }
                else if(rem < 5)
                {
                    while(rem--) ans += "I";
                }
                else
                {
                    int a = rem-5;
                    while(a--) ans += "I";
                    ans += "V";
                }
            }
            else if(c == 1)
            {
                if(rem == 4)
                {
                    ans += "LX";
                }
                else if(rem == 9)
                {
                    ans += "CX";
                }
                else if(rem == 5)
                {
                    ans += "L";
                }
                else if(rem < 5)
                {
                    while(rem--) ans += "X";
                }
                else
                {
                    int a = rem-5;
                    while(a--) ans += "X";
                    ans += "L";
                }
            }
            else if(c == 2)
            {
                if(rem == 4)
                {
                    ans += "DC";
                }
                else if(rem == 9)
                {
                    ans += "MC";
                }
                else if(rem == 5)
                {
                    ans += "D";
                }
                else if(rem < 5)
                {
                    while(rem--) ans += "C";
                }
                else
                {
                    int a = rem-5;
                    while(a--) ans += "C";
                    ans += "D";
                }
            }
            else
            {
                while(rem--)
                {
                    ans += "M";
                }
            }
            num /= 10;
            c++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};