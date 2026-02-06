#include<stdio.h>

void swap(int* lst,int curr_idx,int nxt_idx){
int temp=lst[nxt_idx];
lst[nxt_idx]=lst[curr_idx];
lst[curr_idx]=temp;
}


void selection_sort(int* lst,int len){
  for(int i=0;i<len;i++){
    int min_idx=i;
    int remaning=len-i;
    while(remaning){
    if(lst[min_idx]>lst[i+remaning]) min_idx=i+remaning; 
      remaning--;
    }
    swap(lst,i,min_idx);
  }
}


void insertion_sort(int* lst,int len){
     for(int i=0;i<len;i++){

       //TODO:Think about it
     }
}

void bubble_sort(int* lst,int len){
  for(int k=0;k<len;k++){
    for(int i=0;i<len-k-1;i++){
    
  if(lst[i]>lst[i+1]) swap(lst,i,i+1);
      }
  }
}


int main(){
  int lst[6]={9,7,8,4,5,3};
  int len=sizeof(lst)/sizeof(int);
  selection_sort(lst,len);
  for(int i=0;i<len;i++){
    printf("sorted lst %d\n",lst[i]);
  }
  return 0;
}
