#include<stdio.h>
#include<stdlib.h>

typedef struct{
int* arr;
int len;
} list;


list* split(list* elements,int start_index,int end_index){


    if (start_index < 0 || end_index >= elements->len || start_index > end_index)
    return NULL;

   int count = end_index - start_index + 1;
   int* new_arr = malloc(count * sizeof(int));
    if (!new_arr) return NULL;

  for(int i=0;i<count;i++){
      new_arr[i]=elements->arr[start_index+i];
  }
  list* tmp=malloc(sizeof(list));
  tmp->arr=new_arr;
  tmp->len = count;
  return tmp;
}



int merge(list* left,list* right,list* result){
  int i=0,j=0,k=0;
  while(i<left->len && j<right->len){
    if(left->arr[i]<right->arr[j]){
      result->arr[k++]=left->arr[i++];
    }

    else{
      result->arr[k++]=right->arr[j++];
    }

  }

    while(i<left->len){
    result->arr[k++]=left->arr[i++];
    }
  
    while(j<right->len){
    result->arr[k++]=right->arr[j++];
    }
  
  result->len=k;
  return 0;
}


void merge_sort(list* elements){
  
  
    if (elements->len < 2)
        return;

  int mid = elements->len/2;
   list* left=split(elements,0,mid-1); 
   list* right=split(elements,mid,elements->len-1); 
  
  merge_sort(left);
  merge_sort(right);
  merge(left,right,elements);

   // free allocated memory
    free(left->arr);
    free(left);
    free(right->arr);
    free(right);

  }

int main() {
    int raw[] = {8, 3, 1, 7, 4, 9, 2, 6};
    int n = sizeof(raw) / sizeof(raw[0]);

    list elements;
    elements.arr = raw;
    elements.len = n;

    printf("Before sort: ");
    for (int i = 0; i < n; i++)
        printf("%d ", elements.arr[i]);
    printf("\n");

    merge_sort(&elements);

    printf("After sort:  ");
    for (int i = 0; i < n; i++)
        printf("%d ", elements.arr[i]);
    printf("\n");

    return 0;
}

