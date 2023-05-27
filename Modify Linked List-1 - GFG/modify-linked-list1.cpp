//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
      struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        int len=0;
        Node* temp=head,*pichli;
        while(temp){
            temp=temp->next;
            len++;
        }
        if(len%2)len++;
        len=len/2;
        len++;
        temp=head;
        int c=1;
        while(c!=len){
            pichli=temp;
            temp=temp->next;
            c++;
        }
        Node* prev=NULL,*curr=temp,*agli;
        while(curr){
            agli=curr->next;
            curr->next=prev;
            prev=curr;
            curr=agli;
        }
        pichli->next=prev;
        Node* first=head,*second=prev;
        while(second){
            int t = first->data;
            first->data=second->data-first->data;
            second->data=t;
            first=first->next;
            second=second->next;
        }
        prev=NULL;
        curr=pichli->next;
        while(curr){
            agli=curr->next;
            curr->next=prev;
            prev=curr;
            curr=agli;
        }
        pichli->next=prev;
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends