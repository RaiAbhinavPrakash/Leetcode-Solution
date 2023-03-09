//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        vector<Node*>v;
        Node* l1 = head, *prev = NULL, *l2 = head;
        map<char,int>mp, mp1;
        int c = 0;
        for(int i = 0; i<s.size(); i++) mp[s[i]]++;
        sort(s.begin(), s.end());
        string k = "";
        while(l2)
        {
            mp1[l2->data]++;
            k += l2->data;
            c++;
            prev = l2;
            l2 = l2->next;
            if(c == s.size())
            {
                string p = k;
                sort(p.begin(),p.end());
                if(p == s)
                {
                    prev->next = NULL;
                    v.push_back(l1);
                    l1 = l2;
                    c = 0;
                    mp1.clear();
                    k = "";
                }
                else
                {
                    mp1[l1->data]--;
                    if(mp1[l1->data] == 0) mp1.erase(l1->data);
                    l1 = l1->next;
                    c--;
                    k.erase(k.begin());
                }
            }
        }
        // vector<Node*>ans;
        // for(int i = 0; i<v.size(); i++)
        // {
        //     string k = "";
        //     Node* temp = v[i];
        //     while(temp)
        //     {
        //         k += temp->data;
        //         temp = temp->next;
        //     }
        //     cout<<k<<" ";
        //     sort(k.begin(), k.end());
        //     if(s == k) ans.push_back(v[i]);
        // }
        return v;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends