#include<iostream> 
using namespace std;
class Node {
    public:
    int key;
    Node* left;
    Node* right;

    Node(int key){
        this->key=key;
        left=right=NULL;
    }
};

Node* insert(Node* root,int key){
    if(root==NULL){
        return new Node(key);

    }
    if (key<root->key){
        root->left=insert(root->left,key);

    }
    else{
        root->right=insert(root->right,key);
    }
    return root;
}
void printInOrder(Node* root){
    if(root==NULL){
        return;
    }
    printInOrder(root->left);
    cout<<root->key<<",";
    printInOrder(root->right);
}

bool search(Node* root , int key ){
    if(root==NULL){
        return false;
    }
    if(root->key==key){
        return true;
    }
    if(key<root->key){
        return search(root->left,key);
    }
     return search(root->right,key);



}


Node * findMin(Node* root){
    while (root->left!=NULL){
        root=root->left;
    }
    return root;
}




Node* remove (Node * root ,int key){
    if (root==NULL){
    return NULL;
    }
    else if(key<root->key){
        root->left=remove(root->left,key);
    }
    else if (key>root->key)
    {
        root->right=remove(root->left,key);
        /* code */
    }
    else{/* when current node matches with key */
        /* No child  */

        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }
        /* SINGLE CHILD  */
        else if (root->left==NULL)
        {
            Node* temp=root;
            root= root->right;
            delete temp;
        }
        else if (root->right==NULL)
        {
            Node* temp=root;
            root= root->left;
            delete temp;
        }
        /* 2 childern */
        else{
            Node* temp= findMin(root->right);
            root->key=temp->key;
            root->right=remove(root->right,temp->key);
            
        }
        
        
    }
    return root ;

}


void printRoot2LeafPath(Node* root ,vector<int>&path){
    if (root==NULL){
        return;
    }
    if(root->left==NULL&& root->right==NULL){
        for (int node:path){
            cout<<node<<"->";

        }
        cout<<root->key;<<"->";
        cout<<endl;

    }
    path.push_back(root->data);
    printRoot2LeafPath(root->left,path);
    printRoot2LeafPath(root->right,path);

    path.pop_back();
    return ;    
}




int main(){
    Node* root=NULL;
    int a[]={8,3,10,1,6,14,4,7,13};
    for (int s:a){
        root=insert(root,s);
    }
    printInOrder(root);
   cout<< search(root,39);

return 0;
}