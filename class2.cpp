#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertToBST(Node*root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(root->data > data){
        root->left = insertToBST(root->left, data);
    }
    else{
        root->right = insertToBST(root->right, data);
    }
    return root;
}

void createBST(Node* root){
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;
    while(data != -1){
        root = insertToBST(root, data);
        cout<<"Enter data: "<<endl;
        cin>>data;
    }
}

void levelOrder(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        Node*temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}

Node* inorderBST(int inorder[], int start, int end){
    if(start > end){
        return NULL;
    }
    int mid = (start+end)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    root->left = inorderBST(inorder, start, mid-1);
    root->right = inorderBST(inorder,mid+1, end);
    return root;

}

void convertBSTtoDLL(Node* root, Node* &head){
    if(root == NULL){
        return;
    }

    //RNL
    //R
    convertBSTtoDLL(root->right, head);

    //N
    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    head = root;

    //L
    convertBSTtoDLL(root->left, head);

}
void convertBSTtoDLL2(Node* root, Node* &head){
    if(root == NULL){
        return;
    }

    //RNL
    //R
    convertBSTtoDLL(root->left, head);

    //N
    if(head != NULL){
        head->right = root;
    }
    root->left = head;
    head = root;

    //L
    convertBSTtoDLL(root->right, head);

}
void printLinkedList(Node* & head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->right;
    }
    cout<<endl;
}

int main(){
    int inorder[7] = {10,20,30,40,50,60,70};
    int start = 0;
    int size = 7;
    int end = size-1;
    Node* root = inorderBST(inorder, start, end);
    cout<<"The tre is: "<<endl;
    levelOrder(root);
    Node* head = NULL;
    cout<<endl;
    // convertBSTtoDLL(root, head);
    // cout<<"The list is: "<<endl;
    // printLinkedList(head);
    // cout<<endl;
    convertBSTtoDLL2(root, head);
    cout<<"The list is: "<<endl;
    cout<<endl;
    printLinkedList(head);
    return 0;
}