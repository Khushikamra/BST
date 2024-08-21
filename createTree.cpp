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

void levelOrder(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(q.size() > 1){
        Node* temp = q.front();
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

Node* insertToBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(root->data < data){
        root->right = insertToBST(root->right, data);
    }
    else{
        root->left = insertToBST(root->left, data);
    }
    return root;
}

void 
createBST(Node* &root){
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;
    while(data != -1){
        root = insertToBST(root, data);
        cout<<"Enter data: "<<endl;
        cin>>data;
    }
}
int main(){
    Node* root = NULL;
    createBST(root);
    cout<<endl;
    cout<<"The tree is: "<<endl;
    levelOrder(root);
    return 0;
}