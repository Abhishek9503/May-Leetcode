//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
      Node* help(int &index,int start,int end,int pre[],int preMirror[],int n){
        if(index>=n or start>end)return NULL;
        if(index==n-1 or start==end){
            Node* temp = new Node(pre[index]);
            index++;
            return temp;
        }
        Node* temp = new Node(pre[index]);
        index++;
        for(int i=start;i<=end;i++){
            if(pre[index]==preMirror[i]){
                temp->left = help(index,i,end,pre,preMirror,n);
                temp->right = help(index,start+1,i-1,pre,preMirror,n);
                break;
            }
        }
        return temp;
    }
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
        int index=0;
        return help(index,0,size-1,pre,preMirror,size);
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends