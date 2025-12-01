#include<stdio.h>
#define MAX_NODES 10
#define INFINITY 9999

int main(){
    int dist[MAX_NODES][MAX_NODES], via[MAX_NODES][MAX_NODES];
    int i, j, k, n;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter distance matrix (use %d for infinity):\n", INFINITY);
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &dist[i][j]);
            if(i == j) dist[i][j] = 0;
            via[i][j] = j;
        }
    }

    for(k = 0; k < n; k++){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    via[i][j] = via[i][k];
                }
            }
        }
    }
    
    // Print routing tables
    for(i = 0; i < n; i++){
        printf("\nRoute %d routing table:\n", i);
        printf("Destination\tNext Hop\tDistance\n");
        for(j = 0; j < n; j++){
            printf("%d\t\t%d\t\t%d\n", j, via[i][j], dist[i][j]);
        }
    }
    
    return 0;
}