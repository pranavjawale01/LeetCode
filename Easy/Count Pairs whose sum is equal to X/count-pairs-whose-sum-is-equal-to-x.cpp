//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void append(struct Node** headRef, struct Node** tailRef, int newData) {
    struct Node* new_node = new Node(newData);

    if (*headRef == NULL) {
        *headRef = new_node;
    }

    else {
        (*tailRef)->next = new_node;
    }
    *tailRef = new_node;
}

void printList(struct Node* head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        vector<int> vec1, vec2;
        Node *temp1 = head1;
        Node *temp2 = head2;
        while (head1 != nullptr) {
            vec1.push_back(head1->data);
            head1 = head1->next;
        }
        while (head2 != nullptr) {
            vec2.push_back(head2->data);
            head2 = head2->next;
        }
        sort(begin(vec1), end(vec1));
        sort(begin(vec2), end(vec2));
        int i = 0, n = vec1.size(), j = vec2.size() - 1, count = 0;
        while (i < n && j >= 0) {
            if (vec1[i] + vec2[j] == x) {
                count++;
                i++;
                j--;
            } else if (vec1[i] + vec2[j] > x) {
                j--;
            } else {
                i++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        struct Node* head1 = NULL;
        struct Node* tail1 = NULL;
        struct Node* tail2 = NULL;
        struct Node* head2 = NULL;
        int n1, n2, tmp, x;
        cin >> n1;
        while (n1--) {
            cin >> tmp;
            append(&head1, &tail1, tmp);
        }
        cin >> n2;
        while (n2--) {
            cin >> tmp;
            append(&head2, &tail2, tmp);
        }
        cin >> x;
        Solution obj;
        cout << obj.countPairs(head1, head2, x) << '\n';
    }
    return 0;
}
// } Driver Code Ends