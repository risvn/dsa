#include<stdio.h>

void insert(int* arr,int len)
{
  for(int i=0;i<len;i++){
    int key=arr[i];
    int j=len-i;
    while(j>=0&&key<arr[j]){
    int tmp=arr[j];
      arr[j]=key;
      arr[i]=tmp;
      j--;

    }

}
}
        
int main()
{
  int arr[7]={9,8,5,4,8,4,2};
  int len=(sizeof(arr)/sizeof(int));
  insert(arr,len);
 for(int i=0;i<=len;i++){
    printf("sorted:%d\n",arr[i]);
  }
  return 0;
}
