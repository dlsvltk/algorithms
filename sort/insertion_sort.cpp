#include<bits/stdc++.h>
int A[1000];
int main(){
  int n;
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d", A+i);
    for(int k=i;k>0;k--){
      if(A[k] < A[k-1]){
        int temp = A[k];
        A[k] = A[k-1];
        A[k-1] = temp;
      }
      else break;
    }
  }
  for(int i=0;i<n;i++) printf("%d ", A[i]);
  return 0;
}
