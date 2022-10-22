```
class Solution {
public:
string minWindow(string s, string t) {
map<char,int>mp;
for(int i = 0; i<t.size(); i++)
{
mp[t[i]]++;
}
int i = 0, j = 0, f = 0, l = INT_MAX, count = 0, sz = mp.size();
map<char,int>m;
while(i<s.size())
{
m[s[i]]++;
if(m[s[i]] == mp[s[i]])
{
count++;
}
int k = 1;
// for(auto it:t)
// {
//     if(m[it] < mp[it])
//     {
//         k = 0;
//         break;
//     }
// }
if(count >= sz)
{
while(k)
{
for(auto it:t)
{
if(m[it] < mp[it])
{
k = 0;