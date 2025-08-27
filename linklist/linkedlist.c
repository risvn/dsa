#include<stdio.h>
#include<stdlib.h> 

typedef struct node {
int data ;
struct node *link;
}node;

struct node* head; //global variable

//prepend function
void Prepend(int num){
  struct node* temp=(node*)(malloc(sizeof(node)));
  temp->data=num;
  temp->link=head;
  head=temp;
}

//print function
void Print(){
struct node* temp=head;
printf("List is . ");
while(temp!=NULL){
    printf(" %d",temp->data);
    temp=temp->link;
}
printf("\n");
}

void Delete(int n){
    struct node* temp=head;
    if(n==1){head=temp->link;    //edgecase
    return;};//  
    for(int i=0;i<n-2&&temp!=NULL;i++) {temp=temp->link;};      //n-2 because head=1 and traversing n-1 length
      struct node*  del_temp=temp->link;
        temp->link=del_temp->link;
        free(del_temp);}

void Insert(int data,int index){
struct node* insert_node=(node*)(malloc(sizeof(node)));
    insert_node->data=data;
    insert_node->link=NULL;
    if(index==1){insert_node->link=head; //edge case
    head=insert_node;
    return; };
    node* temp = head;
    for(int i=0;i<index-2;i++){
        temp=temp->link;}
    insert_node->link=temp->link;
    temp->link=insert_node;}

struct node* Reverse(node* head){
        node* current = head;
        node* pre=NULL;
        node* after;
        while(current!=NULL){
        after=current->link; 
        current->link=pre;
        pre=current;
        current=after;
         
        }
    return pre;}

   
void r_reverse(node* p){
    if(p->link==NULL){head=p; return;}
    r_reverse(p->link);   
    node* q=p->link;     //usingn recursion coping nxt node while traversing back and changing links;
    q->link=p;
    p->link=NULL;}

void print_rev(node* head){
    while(head!=NULL){
    printf("%d ",head->data);
    head=head->link;}}

void r_print(node* head){
    if(head==NULL){return;}
    r_print(head->link);
    printf(" %d",head->data);}

int main(){
  
    Insert(1,1);
    Insert(2,2);
    Insert(3,3);
    Insert(4,4);
    Insert(5,5);
    Insert(5,5);
    Print();
    printf("deleting  the number\n");
    Delete(5);
    Print();
   // head = Reverse(head);
   // printf("The rev list is ");
  //  print_rev(head);
    r_reverse( head);
    printf("reversing using recursion\n");
    Print();

    printf("printing reverse_order list by recursion\n");
    r_print(head);
}







