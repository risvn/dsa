#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<queue>

typedef struct node {
int data;
struct node* left;
struct node* right;
}node ;
node* GetNewNode(int data){
    node* newNode=(node*)(malloc(sizeof(node)));
        newNode->data=data;
        newNode->left=NULL;
        newNode->right=NULL;
       return newNode;
}


node* Insert(node* root,int data){
    if(root==NULL){
        root=GetNewNode(data);}
    else if (data<=root->data){
        root->left=Insert(root->left,data);}
    else{
        root->right=Insert(root->right,data);}
    return root;}

bool Search(node* root,int data){
    if(root==NULL)return false;
    else if(root==NULL)return true;
    else if (data<=root->data)return Search(root->left,data);
    else return Search(root->right,data);}

int Min(node* root){
    if(root->left==NULL)return root->data;
    return Min(root->left);}

void LvlOrderTrav(node* root){
    if(root==NULL)return;
    queue<node*>Q;
    Q.push(root);
    while(!Q.empty()){
    node* current =Q.first();
    cout<<current->data<<" ";
    if(current->left!=NULL)Q.push(current->left);
    if(current->right!=NULL)Q.push(current->right);
    Q.pop()}

int Max(node* root){
    if(root->right==NULL)return root->data;
    return Max(root->right);}

void main(){
    node* root =NULL;
    int min,max;
    root=Insert(root,5);
    root=Insert(root,6);
    root=Insert(root,7);
    root=Insert(root,8);
    root=Insert(root,9);
    min=Min(root);
    max=Max(root);
    printf("%d is the min from the bst\n",min);
    printf("%d is the min from the bst\n",max);
}





































