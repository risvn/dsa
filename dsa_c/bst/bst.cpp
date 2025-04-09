#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<queue>
#include<iostream>
using namespace std;

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

void LvlOrdTrav(node* root){
    if (root==NULL)return;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
    node* current=q.front();
    cout<<current->data <<" ";
    if(current->left!=NULL) q.push(current->left);
    if(current->right!=NULL) q.push(current->right);
    q.pop();
    }
}

int Max(node* root){
    if(root->right==NULL)return root->data;
    return Max(root->right);}


node* Delete(node* root,int data){
    if (!root) return root;                           //base-case
    if (data>root->data) root->left=Delete(root->left,data);
    else if (data<root->data)root->right= Delete(root->right,data);
    else{
        //case-1
        if(!root->right && !root->left) {
            free(root);
            return NULL;}
        //case-2 any one of child is null
        else if (!root->right){
            node* temp = root;
            root=root->left;
            printf("%d print from case-2 ",root->data);
            free(temp);
            return root;}
        else if (!root->left){
            node* temp = root;
            root=root->right;
            printf("%d print from case-2 ",root->data);
            free(temp);
            return root;}
       //case-3(complicated) 
        else {
                root->data=Min(root->right);
                root->right=Delete(root->right,root->data);
            }
        }
    return root;
}
        


int main(){
    node* root =NULL;
    int min,max;
    root=Insert(root,5);
    root=Insert(root,6);
    root=Insert(root,7);
    root=Insert(root,8);
    root=Insert(root,9);
    min=Min(root);
    printf("%d is the min from the bst\n",min);
    max=Max(root);
    printf("%d is the max from the bst\n",max);
    LvlOrdTrav(root);
    printf("Lvl order trav using bst\n");
    root=Delete(root,7);
    LvlOrdTrav(root);
    printf("Lvl order trav after deleting \n");
    
}





































