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

Node* minValue(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node* temp = root->left;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
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

        //2- left is null and right is non null
        else if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //3- left is not null and right is null
        else if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            //4-left and righ both are not null
            //get min value of right subtree
            Node* mini = minValue(root->right);

            //replace
            root->data = mini->data;

            //delete mini
            root->right = deleteFromBST(root->right, mini->data);
        }
    }
    if(root->data > target){
        root->left = deleteFromBST(root->left, target);
    }
    else{
        root->right = deleteFromBST(root->right, target);
    }
}
int main(){
    Node* root = NULL;
    createBST(root);
    cout<<"The tree is: "<<endl;
    levelOrder(root);
    return 0;
}
