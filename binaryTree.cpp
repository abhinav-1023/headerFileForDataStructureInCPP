/* hierarchial data structure */
#include<iostream> 
#include<queue>
using namespace std;
/* Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1  */
class Node{
    public:
    int data;
    Node*left;
    Node* right;
    Node(int d){
        data=d; 
        left =right = NULL;

    }
};
Node* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    Node*n=new Node (d);
    n->left=buildTree(); 
    n->right=buildTree();
    return n;


}
Node* levelOrderBuild(){
    int d;
    cin>>d;
    Node* root =new Node(d);
    queue <Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1){
            current->left=new Node (c1);
            q.push(current->left);
        }
        if(c2!=-1){
            current->right=new Node(c2);
            q.push(current->right);
        }
    }


    return root;
}
int height(Node* root){
    if (root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2= height(root->right);
    return 1+max(h1,h2);

}

int diameter(Node* root){
    if(root ==NULL){
        return 0;
    }
    int D1= height(root->left)+height(root->right);
    int D2=height(root->left);
    int D3= height(root->right);

    return max(D1,max(D2,D3) );
}

class HDPair{
    public :
    int height ;
    int diameter;

};
HDPair optDiameter(Node * root){
    HDPair P;
    if(root==NULL){
        P.height=P.diameter=0;
        return P;
    }


    HDPair left=optDiameter(root->left);
    HDPair right=optDiameter(root->right);

    P.height=max(left.height,right.height)+1;
    int D1=left.height+right.height;
    int D2=left.diameter;
    int D3= right.diameter;

    P.diameter=max(D1,max(D2,D3));
    return P;
}

void printPreorder(Node * root  ){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);

}
void printInOrder(Node * root){
    if(root==NULL){
        return ;
    }
    printPreorder(root->left);
    cout<<root->data<<" ";
    printPreorder(root->right);
}
void postOrder(Node* root ){
      if(root==NULL){
        return ;
    }
    printPreorder(root->left);
    printPreorder(root->right);
    cout<<root->data<<" ";
}
void levelOrderTree(Node*root ){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }

        }
        else {
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    Node* root =levelOrderBuild();
    printPreorder(root);
    cout<<endl;
    printInOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    
   

return 0;
}