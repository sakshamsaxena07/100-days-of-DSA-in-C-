#include <stdio.h>

int kadane(int arr[],int n){
    int max=arr[0],curr=arr[0];
    for(int i=1;i<n;i++){
        curr=(curr>0)?curr+arr[i]:arr[i];
        if(curr>max) max=curr;
    }
    return max;
}

int main(){
    int n,arr[100];
    scanf("%d",&n);

    int total=0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        total+=arr[i];
    }

    int normal=kadane(arr,n);

    for(int i=0;i<n;i++)
        arr[i]=-arr[i];

    int circular=total+kadane(arr,n);

    printf("%d",(circular>normal && circular!=0)?circular:normal);
}
