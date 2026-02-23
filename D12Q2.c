#include <stdio.h>

int main() {
    int m,n;
    scanf("%d %d",&m,&n);

    int a[m][n];

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    int flag=1;

    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            if(a[i][j]!=a[i-1][j-1])
                flag=0;

    if(flag) printf("true");
    else printf("false");
}
