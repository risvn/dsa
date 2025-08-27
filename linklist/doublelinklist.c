#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* nxt;
    struct node* prv;}node;

 node* head=NULL; //global var

struct node* GetNewNode(int x){
    node* new_node=(node*)(malloc(sizeof(node)));
    new_node->data=x;
    new_node->nxt=NULL;
    new_node->prv=NULL;
    return new_node;
}

void InsertAtNode(int x){
    node* new_node=GetNewNode(x);
    if(head==NULL){head=new_node;
    return;};  //edge case
    //for existing list
    new_node->nxt=head;
    head->prv=new_node;
    head=new_node;}

void Print(){
    node* temp=head;
    printf("forward:" );
    while(temp!=NULL){
    printf(" %d",temp->data);
    temp=temp->nxt;
    }
    printf("\n");
}

void RevPrint(){
    node* temp=head;
    if(temp==NULL)return;                 //edge case for empty list
    while(temp->nxt!=NULL)temp=temp->nxt;     //travresing to the last node
    printf("reverse_print :");
    while(temp!=NULL){
    printf(" %d",temp->data);
    temp=temp->prv;}
}

int main(){
    InsertAtNode(1);
    InsertAtNode(2);
    InsertAtNode(3);
    InsertAtNode(4);
    InsertAtNode(5);
    Print();
    RevPrint();
    }

















