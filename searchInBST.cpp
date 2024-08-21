#include<iostream>
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

bool searchInBST(Node* root, int target){
    if(root == NULL){
        return false;
    }
    if(root->data == target){
        return true;
    }

    bool leftAns = false;
    bool rightAns = false;

    if(root->data > target){
        leftAns = searchInBST(root->left, target);
    }
    else{
        rightAns = searchInBST(root->right, target);
    }
    return leftAns || rightAns;
}

Node* insertToBST(Node* root, int data){
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

void createBST(Node* &root){
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
    int target;
    cout<<"Enter Target: ";
    cin>>target;
    while(target != -1){
        bool ans = searchInBST(root, target);
        if(ans == true){
            cout<<"Found.";
        }
        else{
            cout<<"Not Found.";
        }
        cout<<endl;
        cout<<"Enter target: ";
        cin>>target;
    }
    return 0;
}