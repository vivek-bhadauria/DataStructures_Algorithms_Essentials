#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{

    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

void printVector(vector<int> v){

    for(int val : v){
        cout<<val<<" ";
    }
}

void inorder(Node * root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void printLevelWise(Node* root){
    queue<Node*> q;
    if(root == NULL){
        return;
    }
    q.push(root);
    q.push(NULL);
    Node* currNode = NULL;
    int level=1;

    while(!q.empty()){
        Node* currNode = q.front();
        q.pop();
        if(q.empty()){
            break;
        }
        if(currNode == NULL){
            cout<<endl;
            q.push(NULL);
            level++;
            continue;
        }
        
        cout<<currNode->data<<" ";
        if(currNode->left != NULL){
            q.push(currNode->left);
        }
        if(currNode->right != NULL){
            q.push(currNode->right);
        }
    }
}

void insertIntoBST(int val, Node* node){
    if(node == NULL){
        cout<<"Not inserting value : "<<val<<endl;
        return;
    }
    if(val <= node->data && node->left == NULL){
        node->left = new Node(val);
        return;
    }
    if(val <= node->data && node->left != NULL){
        insertIntoBST(val, node->left);
        return;
    }
    if(val > node->data && node->right == NULL){
        node->right = new Node(val);
        return;
    }
    if(val > node->data && node->right != NULL){
        insertIntoBST(val, node->right);
        return;
    }

}

Node* createBST(vector<int> v){
    Node* root = NULL;
    for(int i=0 ; i<v.size(); i++){
        if(root == NULL){
            root = new Node(v[i]);
        } else {
            insertIntoBST(v[i], root);
        }
    }
    return root;
}

bool search(int key, Node* root){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key < root->data){
        return search(key, root->left);
    }else{
        return search(key, root->right);
    }
}

Node* findMin(Node* root){
    if(root == NULL){
        return NULL;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* findMax(Node* root){
    if(root == NULL){
        return NULL;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

Node* deleteNode(int key, Node* root){
    if(root == NULL){
        return NULL;
    }
    if(key < root->data){
        root->left = deleteNode(key, root->left);
    }else if(key > root->data){
        root->right = deleteNode(key, root->right);
    } else{
        if(root->left == NULL && root->right == NULL){/*root has no child*/
            delete root;
            root = NULL; 
        } else if(root->left == NULL){/*root has only right child*/
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if(root->right == NULL){/*root has only left child*/
            Node* temp = root;
            root = root->left;
            delete temp;
        } else {/*root has two children*/
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(temp->data,root->right);
            delete temp;
        }
    }
    return root;
}

void printInRange(Node* root, int k1, int k2){
    if(root == NULL){
        return;
    }
    if(k1<=root->data && root->data<=k2){
        /*kind of similar to printing the inorder just with that condition which is already tested*/
        printInRange(root->left, k1, k2);
        cout<<root->data<<" ";
        printInRange(root->right, k1, k2);
    }else if (k2<root->data){
        printInRange(root->left, k1, k2);
    }else{
        printInRange(root->right, k1, k2);
    }
}

void printRootToLeaf(Node* root, vector<int> &v){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        v.push_back(root->data);
        printVector(v);
        cout<<endl;
        return;
    }
    v.push_back(root->data);
    printRootToLeaf(root->left, v);
    v.pop_back();

    if(v[v.size()-1] != root->data){
        v.push_back(root->data);
    }
    printRootToLeaf(root->right, v);
    v.pop_back();
}

Node* mirrorBST(Node * root){
    if(root == NULL){
        return NULL;
    }
    Node* right = mirrorBST(root->right);
    Node* left = mirrorBST(root->left);
    root->left = right;
    root->right = left;
    return root;
}

bool isBST(Node * root){
    if(root == NULL){
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    if(root->left != NULL && root->left->data > root->data){
        return false;
    }
    if (root->right != NULL && root->right->data <= root->data){
        return false;
    }
    
    Node* min = findMin(root->right);
    Node* max = findMax(root->left);
    bool isLeftMaxOK = max == NULL || max->data <= root->data;
    bool isRightMinOK = min == NULL || min->data > root->data;
    
    
    return isLeftMaxOK && isBST(root->left) 
        && isRightMinOK && isBST(root->right);
}


int main(){
    vector<int> v{8, 3, 10, 1, 6, 14, 4, 7, 13};

    Node* root = createBST(v);
    inorder(root);
    cout<<endl;
    printLevelWise(root);
    cout<<endl;
    int val = 14;
    cout<<val<<" present in BST ? "<<search(val, root)<<endl;
    val = 15;
    cout<<val<<" present in BST ? "<<search(val, root)<<endl;
    /*int key;
    cin>>key;
    root = deleteNode(key, root);
    inorder(root);*/
    cout<<endl<<"Printing in range 5 to 13"<<endl;
    printInRange(root, 5, 13);
    cout<<endl<<"Printing in range 1 to 5"<<endl;
    printInRange(root, 1, 5);
    cout<<endl<<"Printing in range 8 to 14"<<endl;
    printInRange(root, 8, 14);
    cout<<endl;

    vector<int> v1;
    cout<<"All root to leaf paths"<<endl;
    printRootToLeaf(root,v1);

    /* test mirror BST */
    cout<<endl<<"Before Mirroring"<<endl;
    printLevelWise(root);
    cout<<endl<<"Is BST before mirroring : "<<isBST(root)<<endl;
    root = mirrorBST(root);
    cout<<endl<<"After Mirroring"<<endl;
    printLevelWise(root);
    cout<<endl<<"Is BST after mirroring : "<<isBST(root)<<endl;

}