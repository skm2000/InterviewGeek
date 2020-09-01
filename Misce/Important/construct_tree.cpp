#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    int val = 0;
    TreeNode *left,*right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

int ans = 0;

void preOrder(TreeNode *root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


// void makeTree(vector<pair<string,int>>&p,int n,int r){
//     TreeNode *root = new TreeNode(r);
//     for(int i=0;i<n;i++){
//         string k = p[i].first;
//         // cout<<k<<" ";
//         int j=0,v=p[i].second;
//         // cout<<val<<" ";
//         // cout<<(root != NULL)<<endl;
//         while(j<k.size()-1){
//             if(k[j] == 'L') root = root->left;
//             else root = root->right;
//             j++;
//         }
//         // cout<<(k[j-1] == 'L')<<endl;
//         if(k[j] == 'L') {root->left = new TreeNode(v);return;}
//         else if(k[j] == 'R') root->right = new TreeNode(v);
//     }
//     preOrder(root);
// }


// void buildTree(TreeNode* root,string k,int v){
//     for(int i=0;i<k.size()-1;i++){
//         if(k[i] == 'L') root = root->left;
//         else root = root->right;
//     }
//     if(k[k.size()-1] == 'L') root->left = new TreeNode(v);
//     else if(k[k.size()-1] == 'R') root->right = new TreeNode(v);
//     preOrder(root);
// }

TreeNode* build(TreeNode* root,string k,int v,int i){
    TreeNode*newNode = new TreeNode(v);
    TreeNode*x = root;
    TreeNode*y = NULL;
    while(x != NULL){
        y = x;
        if(k[i] == 'L') x = x->left;
        else x = x->right;
        i++;
    }
    if(k[i-1] == 'L') y->left = newNode;
    else y->right = newNode;

    return y;
}


int sum(TreeNode* root){
    if(root == NULL) return 0;
    int left = sum(root->left);
    int right = sum(root->right);
    if((left%2 == 0 && right%2 == 1) || (left%2 == 1 && right%2 == 0)) ans += root->val;
    return root->val + left + right;
}


int main(){
    int n,val,r;
    string s;
    cin>>n>>r;
    vector<pair<string,int>>p;
    for(int i=0;i<n-1;i++){
        cin>>s>>val;
        p.push_back({s,val});
    }
    // for(auto x:p){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    // makeTree(p,n,r);
    TreeNode *root = new TreeNode(r);
    for(int i=0;i<n-1;i++){
        string k = p[i].first;
        int v = p[i].second;
        build(root,k,v,0);
    }
    preOrder(root);
    sum(root);
    cout<<"\n";
    cout<<ans;
}