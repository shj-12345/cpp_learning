#include <memory>
#include <vector>
#include <iostream>
using namespace std;
struct BST_node
{
    /* data */
    int data;
    BST_node* left;
    BST_node* right;
};
BST_node* get_new_node(int data){
    BST_node* new_node = new BST_node;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
/*循环：构建二叉树*/
// void insert_node(BST_node** root,int data)
// {
//     if((*root)==NULL){(*root)=get_new_node(data);}
//     else
//     {
//         BST_node* node_tmp = *root;
//         for(;;)
//         {
//             if(data<=node_tmp->data){
//                 if(node_tmp->left==NULL){node_tmp->left=get_new_node(data);break;}
//                 else{node_tmp=node_tmp->left;}
//             }
//             else{
//                 if(node_tmp->right==NULL){node_tmp->right=get_new_node(data);break;}
//                 else{node_tmp=node_tmp->right;}
//             }    
//         }
//     }
    
// }
/*递归：构建二叉树*/
BST_node* insert_node(BST_node* root,int data)
{
    if(root==NULL){return get_new_node(data);}
    else if(data<=root->data){root->left=insert_node(root->left,data);return root;}
    else {root->right=insert_node(root->right,data);return root;}
}
void search_node(BST_node* root,int data)
{
    if(root==NULL){cout<<"not found "<<data<<endl;}
    else if(data==root->data){cout<<"found "<<data<<endl;}
    else if(data<=root->data){search_node(root->left,data);}
    else if(data>root->data){search_node(root->right,data);}
}
void get_min(BST_node* root)
{
    if(root==NULL){cout<<"empty tree"<<endl;}
    else{
        if(root->left==NULL){cout<<"the minimum="<<root->data<<endl;}
        else{get_min(root->left);}
    } 
}
void get_max(BST_node* root)
{
    if(root==NULL){cout<<"empty tree"<<endl;}
    else{
        if(root->right==NULL){cout<<"the maximum="<<root->data<<endl;}
        else{get_max(root->right);}
    } 
}
// int get_height(BST_node* root)
// {
//     if(root->left==NULL&&root->right==NULL){return 0;}
//     else{
//         int left_height=0,right_height=0;
//         if(root->left!=NULL){   left_height=get_height(root->left);}
//         if(root->right!=NULL){ right_height=get_height(root->right);}
//         return max(left_height,right_height)+1;
//     }
// }
int get_height(BST_node* root)
{
    //退出条件
    if(root==NULL){return -1;}
    int left_height=get_height(root->left);
    int right_height=get_height(root->right);
    return max(left_height,right_height)+1;
}
void delete_tree(BST_node* root)
{
    if(root->left!=NULL){delete_tree(root->left);root->left=NULL;}
    if(root->right!=NULL){delete_tree(root->right);root->right=NULL;}
    if(root->left==NULL&&root->right==NULL){
        cout<<"address="<<root<<"  value="<<root->data<<endl;  
        delete root;
    }
}
int main()
{
    BST_node* root = NULL;
    vector<int> v{12,1,11,4,8,13,2,3,7,6,9,5,10};
    for(int i=0;i<v.size();i++)
    {
        root=insert_node(root,v[i]);
    }
    search_node(root,12);
    get_min(root);
    get_max(root);
    cout<<"the height of tree ="<<get_height(root)<<endl;
    delete_tree(root);
    return 0;
}
