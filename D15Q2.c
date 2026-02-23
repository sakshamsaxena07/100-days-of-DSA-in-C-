#include <stdio.h>

int main() {
    int m,n;
    scanf("%d %d",&m,&n);

    int a[m][n];

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    int row[m],col[n];

    for(int i=0;i<m;i++) row[i]=0;
    for(int j=0;j<n;j++) col[j]=0;

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(a[i][j]==0){
                row[i]=1;
                col[j]=1;
            }

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(row[i]||col[j])
                a[i][j]=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
