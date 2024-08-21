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

void preOrder(Node* root){
    //NLR
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    //LNR
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    //LRN
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

Node* minValue(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

bool searchInBST(Node* root, int target){
    if(root == NULL){
        return false;
    }
    if(root->data == target){
        return true;
    }
    bool leftAns = false;
    bool rightAns = false;
    if(target > root->data){
        rightAns = searchInBST(root->right, target);
    }
    else{
        leftAns = searchInBST(root->left, target);
    }

    return leftAns || rightAns;
}

Node* deleteFromBST(Node* root, int target){
    if(root == NULL){
        return NULL;
    }

    if(root->data == target){
        //delete karo
        //4 cases

        //1- leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //2- left non NULL and right null
        else if(root->left != NULL && root->right == NULL){
            Node* childSubTree = root->left;
            delete root;
            return childSubTree;
        }

        //3- left NULL and right not null
        else if(root->left == NULL && root->right != NULL){
            Node* childSubTree = root->right;
            delete root;
            return childSubTree;

        }

        //4 - left is non null and right is also non null
        else{
            //a-> leftSubTree ki max value
            Node* maxi = maxValue(root->left);
            //replacement
            root->data = maxi->data;
            //delete maxi node
            //VERY IMPORTANT
            root->left = deleteFromBST(root->left, maxi->data);
            return root;
        }
    }
    else if(root->data > target){
        root->left = deleteFromBST(root->left, target);
    }
    else{
        root->right = deleteFromBST(root->right, target);
    }
    return root;
}

Node* insertToBST(int data, Node* root){
    if(root == NULL){
        root = new Node (data);
        return root;
    }
    if(data > root->data){
        root->right = insertToBST(data, root->right);
    }
    else{
        root->left = insertToBST(data, root->left);
    }
    return root;
}

void createBST(Node* &root){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    while(data != -1){
        root = insertToBST(data, root);
        cout<<"Enter data: "<<endl;
        cin>>data;
    }
}
int main(){
    Node* root = NULL;
    createBST(root);
//     cout<<"The tree is: "<<endl;
//     levelOrder(root);
//     cout<<endl;
//     cout<<"Inorder: ";
//     inOrder(root);
//     cout<<endl;
//     cout<<"Preorder: ";
//     preOrder(root);
//     cout<<endl;
//     cout<<"Postorder: ";
//     postOrder(root);
//     cout<<endl;
//    Node* minNode = minValue(root);
//    if(minNode == NULL){
//     cout<<"There is no node in tree, so no min value."<<endl;
//    }
//    else{
//     cout<<"The value of min node is: "<<minNode->data<<endl;
//    }
//    Node* maxNode = maxValue(root);
//    if(maxNode == NULL){
//     cout<<"There is no node in tree, so no max value."<<endl;
//    }
//    else{
//     cout<<"The value of max node is: "<<maxNode->data<<endl;
//    }

//    int t;
//    cout<<"Enter target: "<<endl;
//    cin>>t;

//    while(t != -1){
//     bool ans = searchInBST(root, t);
//     if(ans == true){
//         cout<<"Found"<<endl;
//     }
//     else{
//         cout<<"Not Found"<<endl;
//     }
//     cout<<"Enter the target: ";
//     cin>>t;
//    }

int target;
cout<<"Enter the target: ";
cin>>target;
while(target != -1){
    root = deleteFromBST(root, target);
    cout<<endl;
    cout<<"The tree is: "<<endl;
    levelOrder(root);

    cout<<endl;

    cout<<"Enter the target: ";
    cin>>target;
}
    return 0;
}