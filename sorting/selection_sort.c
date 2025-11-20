#include<stdio.h>

void select(int* arr,int len)
{
  for(int i=0;i<=len;i++){
    int imin =i;
    for(int j=i+1;j<=len;j++){
      // get the index of the smallest value
      if(arr[j]<arr[imin]) imin=j;}
    
      //swap [sorted | unsorted]
      int temp=arr[i];
      arr[i]=arr[imin];
      arr[imin]=temp;
  }

}
        
int main()
{
  int arr[7]={9,8,5,4,8,4,2};
  int len=(sizeof(arr)/sizeof(int)-1);
  select(arr,len);
 for(int i=0;i<=len;i++){
    printf("sorted:%d\n",arr[i]);
  }
  return 0;
}
