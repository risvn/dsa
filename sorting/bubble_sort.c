//====================Bubble Sort====================//
#include<stdio.h>

int* bubble(int* arr,int len){
  for(int i=0;i<len;i++){
  for(int j=0;j<len-i-1;j++){
  if(arr[j]>arr[j+1]){
  int tmp=arr[j];
  arr[j]=arr[j+1];
  arr[j+1]=tmp;

       }
      }
  }
return arr;
  }

int main(){
  int arr[5]={2,5,3,8,1};
  int len=sizeof(arr)/sizeof(arr[0]);
  int* sorted=bubble(arr,len);
  for(int i=0;i<len;i++){
    printf("%d\n",sorted[i]);


  }
}
