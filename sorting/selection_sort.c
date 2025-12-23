#include<stdio.h>

void select(int* arr,int len)
{
  for(int i=0;i<len;i++){
    int min=i;
  for(int j=i+1;j<len;j++){
    if(arr[j]<=arr[min]){
        min=j;
      }

      //swap
      int tmp=arr[i];
      arr[i]=arr[min];
      arr[min]=tmp;

    }

}
}
        
int main()
{
  int arr[7]={9,8,5,4,8,4,2};
  int len=(sizeof(arr)/sizeof(int));
  select(arr,len);
 for(int i=0;i<=len-1;i++){
    printf("sorted:%d\n",arr[i]);
  }
  return 0;
}
