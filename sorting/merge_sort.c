#include<stdio.h>
#include<stdlib.h>

typedef struct{
int* arr;
int len;
} list;





int merge(list left,list right,list result){
  int i=0,j=0,k=0;
  while(i<left.len && j<right.len){
    if(left.arr[i]<right.arr[j]){
      result.arr[k++]=left.arr[i++];
    }

    else{
      result.arr[k++]=right.arr[j++];
    }

  }

    while(i<left.len){
    result.arr[k++]=left.arr[i++];
    }
  
    while(j<right.len){
    result.arr[k++]=left.arr[j++];
    }
  
  result.len=k;
  return 0;
}


void merge_sort(list elements){
  
  
    if (elements.len < 2)
        return;

    int mid = elements.len / 2;
 // allocate left and right subarrays
    list left, right;
    left.len = mid;
    right.len = elements.len - mid;

    left.arr = malloc(left.len * sizeof(int));
    right.arr = malloc(right.len * sizeof(int));

    // fill left
    for (int i = 0; i < mid; i++)
        left.arr[i] = elements.arr[i];

    // fill right
    for (int i = mid; i < elements.len; i++)
        right.arr[i - mid] = elements.arr[i];


  merge_sort(left);
  merge_sort(right);
  merge(left,right,elements);

  // free temp arrays
    free(left.arr);
    free(right.arr);

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

    merge_sort(elements);

    printf("After sort:  ");
    for (int i = 0; i < n; i++)
        printf("%d ", elements.arr[i]);
    printf("\n");

    return 0;
}

