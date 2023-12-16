#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
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

class DPair{
    public:
        int height;
        int diameter;
};

/* sample input - 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1*/

Node* buildTree(){

     int d;
     cin>>d;
     
     if(d==-1){
        return NULL;
     }

     Node* node = new Node(d);
     node->left = buildTree();
     node->right = buildTree();

     return node;
}

void printPreorder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printPostorder(Node* root){
    if(root == NULL){
        return;
    }
    
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
}

void printPreorderIterative(Node* root){

    stack<Node*> stk;
    Node* currNode = root;
    Node* prevNode = NULL;

    while(!stk.empty() || currNode != NULL){

        if(currNode != NULL){
            cout<<currNode->data<<" ";
            stk.push(currNode);
            currNode = currNode->left;
        }else{
            prevNode = stk.top();
            stk.pop();
            currNode = prevNode->right;
        }
    }

}

void printInorderIterative(Node* root){

    stack<Node*> stk;
    Node* currNode = root;
    Node* prevNode = NULL;

    while(!stk.empty() || currNode != NULL){

        if(currNode != NULL){
            stk.push(currNode);
            currNode = currNode->left;
        }else{
            prevNode = stk.top();
            cout<<prevNode->data<<" ";
            stk.pop();
            currNode = prevNode->right;
        }
    }
}

void printPostorderIterative(Node* root){

    stack<Node*> stk;
    Node* currNode = root;
    Node* prevNode = NULL;
    unordered_set<Node*> processed;

    while(!stk.empty() || currNode != NULL){

        if(currNode != NULL){
            stk.push(currNode);
            currNode = currNode->left;
        }else{
            prevNode = stk.top();
            if(prevNode->right == NULL || processed.count(prevNode->right) > 0){
                cout<<prevNode->data<<" ";
                processed.insert(prevNode);
                stk.pop();
            }
            if(processed.count(prevNode->right) == 0){
                currNode = prevNode->right;
            }
        }
    }
}

void printLevelorder(Node* root){

    queue<Node*> q;
    if(root == NULL){
        return;
    }
    q.push(root);

    while(!q.empty()){
        Node* currNode = q.front();
        q.pop();
        cout<<currNode->data<<" ";
        if(currNode->left != NULL){
            q.push(currNode->left);
        }
        if(currNode->right){
            q.push(currNode->right);
        }
    }
}

void printLevelWise(Node* root){

    int sum = 0;
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
        sum += currNode->data;
        if(currNode->left != NULL){
            q.push(currNode->left);
        }
        if(currNode->right != NULL){
            q.push(currNode->right);
        }
    }
    cout<<endl<<"No of levels : "<<level<<endl;
    cout<<endl<<"Sum of nodes : "<<sum<<endl;
}

/* Input : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1 */

Node* buildLevelOrderTree(vector<int> v){

    Node* root = NULL;
    queue<Node*> q;
    for(int i=0; i<v.size(); i++){

        if(i==0){
            Node* node = new Node(v[i]);
            q.push(node);
            root = node;
        } else {
            Node* node = q.front();
            Node* newNode = NULL;
            if(v[i] != -1){
                newNode = new Node(v[i]);
                q.push(newNode);
            }

            // if the current index is odd we need to insert element on the left of the front element and not pop
            if(i&1){
                node->left = newNode;
            } else {
                // if the current index is even we need to insert element on the right of the front element and pop
                node->right = newNode;
                q.pop();
            }
        }

    }
    return root;
}

int height(Node* root){

    if(root==NULL){
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

int heightByLevelOrder(Node* root){

    int height=0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
            height++;
        }else {
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
    return height;
}

vector<int> printKthLevel(Node* root, int k){

    int currLevel=0;
    vector<int> v;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(currLevel<k){
        Node* curr = q.front();
        q.pop();
        if(curr == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
            currLevel++;
        }else{
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }

    Node* node = NULL;
    while (!q.empty() || node!=NULL)
    {
        node = q.front();
        q.pop();
        if(node!=NULL && (v.empty() || v[v.size()-1] != node->data)){
            v.push_back(node->data);
        }
    }
    return v;
}

int diameter(Node* root){
    if(root == NULL){
        return 0;
    }

    // diameter passes through root node 
    int d1 = height(root->left) + height(root->right);
    // diameter lies in the left subtree of root node
    int d2 = diameter(root->left);
    // diameter lies in the right subtree of root node
    int d3 = diameter(root->right);

    return max(d1, max(d2,d3));
}

DPair diameterOptimized(Node* root){
    DPair p;
    if(root == NULL){
        p.height = 0;
        p.diameter = 0;
        return p;
    }

    DPair leftPair = diameterOptimized(root->left);
    DPair rightPair = diameterOptimized(root->right);

    p.height = max(leftPair.height, rightPair.height) + 1;
    
    int d1 = leftPair.height + rightPair.height;
    int d2 = leftPair.diameter;
    int d3 = rightPair.diameter;
    p.diameter = max(d1, max(d2, d3));
    return p;
}

int minDepth(Node* root){

    int depth = 0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
            depth++;
        } else {
            if(curr->left == NULL && curr->right == NULL){
                break;
            }
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }

    }
    return depth+1;
}

int minDepthRecursive(Node* root){
    if(root->left == NULL && root->right != NULL){
        return 1 + minDepthRecursive(root->right);
    }
    if(root->left != NULL && root->right == NULL){
        return 1 + minDepthRecursive(root->left);
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }

    return 1 + min( minDepthRecursive(root->left), minDepthRecursive(root->right));
}

bool isSymmetric(Node* root) {
        //your code goes here
        
        if(root == NULL){
            return true;
        }
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        if(root->left == NULL && root->right != NULL){
            return false;
        }
        if(root->left != NULL && root->right == NULL){
            return false;
        }
        
        return isSymmetric(root->left) && isSymmetric(root->right);
}

Node* removeOneChildNodes(Node* root){
    
    if(root->left == NULL && root->right == NULL){
        return root;
    }
    if(root->left == NULL && root->right != NULL){
        return removeOneChildNodes(root->right);
        
    }
    if(root->left != NULL && root->right == NULL){
        return removeOneChildNodes(root->left);
    }
    
    root->left = removeOneChildNodes(root->left);
    root->right = removeOneChildNodes(root->right);
    return root;
}

void printVector(vector<int> v){

    for(int val : v){
        cout<<val<<" ";
    }
}

int main(){

    /*
    Node* r = buildTree();
    cout<<endl<<"Preorder:  ";
    printPreorder(r);
    cout<<endl<<"PreorderI: ";
    printPreorderIterative(r);
    cout<<endl<<"Inorder:  ";
    printInorder(r);
    cout<<endl<<"InorderI: ";
    printInorderIterative(r);
    cout<<endl<<"Postorder:  ";
    printPostorder(r);
    cout<<endl<<"PostorderI: ";
    printPostorderIterative(r);
    cout<<endl<<"Levelorder: ";
    printLevelorder(r);
    cout<<endl<<"Level Wise:"<<endl;
    printLevelWise(r);
    cout<<endl;
    */

    vector<int> v{1, 2, 3, 4, 5, -1, 6, -1, -1, 7, -1, -1, -1, -1, -1};

    Node* r = buildLevelOrderTree(v);
    cout<<endl<<"Preorder:  ";
    printPreorder(r);
    cout<<endl<<"PreorderI: ";
    printPreorderIterative(r);
    cout<<endl<<"Inorder:  ";
    printInorder(r);
    cout<<endl<<"InorderI: ";
    printInorderIterative(r);
    cout<<endl<<"Postorder:  ";
    printPostorder(r);
    cout<<endl<<"PostorderI: ";
    printPostorderIterative(r);
    cout<<endl<<"Levelorder: ";
    printLevelorder(r);
    cout<<endl<<"Level Wise:"<<endl;
    printLevelWise(r);
    cout<<endl;
    cout<<endl<<"Height : "<<height(r)<<endl;
    cout<<endl<<"Height by level order : "<<heightByLevelOrder(r)<<endl;

    printVector(printKthLevel(r,2));
    cout<<endl<<"Diameter : "<<diameter(r)<<endl;
    cout<<endl<<"Diameter Optimized : "<<diameterOptimized(r).diameter<<endl;
    cout<<endl<<"Min Depth : "<<minDepth(r)<<endl;
    cout<<endl<<"Min Depth Recursive : "<<minDepthRecursive(r)<<endl;
    cout<<endl<<"Symmetric : "<<isSymmetric(r)<<endl;

    removeOneChildNodes(r);

    cout<<endl<<"Inorder:  ";
    printInorder(r);

}