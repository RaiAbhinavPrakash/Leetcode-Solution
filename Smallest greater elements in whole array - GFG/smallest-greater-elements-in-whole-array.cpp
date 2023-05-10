//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int* greaterElement(int arr[], int n);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int *b;
        b = greaterElement(arr, n);
        for(int i=0;i<n;i++){
            if(b[i] == -10000000)
                cout << "_ ";
            else
                cout << b[i] << " ";
        }
        cout<<endl;   
        
    }
    return 0;
}

// } Driver Code Ends


int* greaterElement(int arr[], int n)
{
    vector<int>v;
    for(int i = 0; i<n; i++)
    {
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i<n; i++)
    {
        auto upper = upper_bound(v.begin(), v.end(), arr[i]);
        if(upper-v.begin()>=n) arr[i] = -10000000;
        else arr[i] = v[upper-v.begin()];
    }
    return arr;
}
