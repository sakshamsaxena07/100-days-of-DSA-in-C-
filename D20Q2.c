#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    return (*(int*)a-*(int*)b);
}

int main(){
    int n,arr[100];
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    qsort(arr,n,sizeof(int),cmp);

    for(int i=0;i<n-2;i++){
        int l=i+1,r=n-1;

        while(l<r){
            int sum=arr[i]+arr[l]+arr[r];

            if(sum==0){
                printf("%d %d %d\n",arr[i],arr[l],arr[r]);
                l++; r--;
            }
            else if(sum<0) l++;
            else r--;
        }
    }
}
