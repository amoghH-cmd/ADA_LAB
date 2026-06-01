

#include <stdio.h>
#define INF 9999
#define MAX 10

int main() {
    int n, cost[MAX][MAX];
    int near[MAX], t[MAX][2];
    int i, j, k, l, min, mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF; 
        }
    }

    
    min = INF;
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                k = i;
                l = j;
            }
        }
    }

   
    t[1][1] = k;
    t[1][2] = l;
    mincost = cost[k][l];

   
    for (i = 1; i <= n; i++) {
        if (cost[i][k] < cost[i][l])
            near[i] = k;
        else
            near[i] = l;
    }

    near[k] = 0;
    near[l] = 0;

    for (i = 2; i <= n - 1; i++) {
        min = INF;

        
        for (j = 1; j <= n; j++) {
            if (near[j] != 0 && cost[j][near[j]] < min) {
                min = cost[j][near[j]];
                k = j;
            }
        }

        
        t[i][1] = k;
        t[i][2] = near[k];
        mincost += cost[k][near[k]];

        near[k] = 0;

        
        for (j = 1; j <= n; j++) {
            if (near[j] != 0 && cost[j][near[j]] > cost[j][k]) {
                near[j] = k;
            }
        }
    }

    
    printf("\nEdges in MST:\n");
    for (i = 1; i <= n - 1; i++) {
        printf("%d - %d\n", t[i][1], t[i][2]);
    }

    printf("Minimum cost = %d\n", mincost);

    return 0;
}