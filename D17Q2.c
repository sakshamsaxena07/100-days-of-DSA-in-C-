#include <stdio.h>

int main(){
    int n,arr[100];
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int maxSum=arr[0],curr=arr[0];

    for(int i=1;i<n;i++){
        if(curr<0) curr=arr[i];
        else curr+=arr[i];

        if(curr>maxSum)
            maxSum=curr;
    }

    printf("%d",maxSum);
}
