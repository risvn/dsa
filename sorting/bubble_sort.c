//====================Bubble Sort====================//
#include<stdio.h>

int bubble_sort(int* arr,int len)
{
  for(int j=0;j<=len;j++){
  for(int i=0;i<=len-j;i++){
      if(arr[i]>arr[i+1]){
     int temp=arr[i+1];
      arr[i+1]=arr[i];
      arr[i]=temp;
      }
  }
}
return 0;
}
int main(){
  int arr[5]={1,5,4,2,6};
  int len=((sizeof(arr)/sizeof(int))-1);
  bubble_sort(arr,len);
  for(int i=0;i<=len;i++){
      printf("sorted:%d\n",arr[i]);
      }
}

