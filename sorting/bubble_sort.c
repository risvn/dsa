//====================Bubble Sort====================//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// here length =no.of element in the arr
int* sort(int* arr,size_t length)
{
  int* input_cpy= (int*) malloc(sizeof(int)*length);
  memcpy(input_cpy,arr,length*sizeof(int));  //memcpy takes size in bytes
for(int i=0;i<length-1;i++)
    {
  for(int j=0;j<length-1-i;j++){
  
    int current=input_cpy[j];
    int next=input_cpy[j+1];
    if(current>next)
      {


         int temp = input_cpy[j];
            input_cpy[j] = input_cpy[j + 1];
            input_cpy[j + 1] = temp;
        }

  }
    }
return input_cpy;
}


int main()
{
int arr[]={5,6,3,2,7,8,2,1};
size_t len=sizeof(arr)/sizeof(arr[0]);
int* sorted_arr=sort(arr,len);
  //priting the sorted_array
  for (int i = 0; i < len; i++) {
    printf("%d ", sorted_arr[i]);
}
printf("\n");


return 0;
}
