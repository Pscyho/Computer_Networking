 #include <stdio.h>
#define MAX 10
#define INFINITY 9999
void dijkstra(int graph[MAX][MAX], int n, int start) {
int distance[MAX], visited[MAX], count, minDistance, nextNode, i, j;
for (i = 0; i < n; i++) {
distance[i] = graph[start][i];
visited[i] = 0;
}
distance[start] = 0;
visited[start] = 1;
count = 1;
while (count < n - 1) {
minDistance = INFINITY;
for (i = 0; i < n; i++) {
    if (distance[i] < minDistance && !visited[i]) {
minDistance = distance[i];
nextNode = i;
} }
visited[nextNode] = 1;
for (i = 0; i < n; i++) {
if (!visited[i]) {
if (minDistance + graph[nextNode][i] < distance[i]) {
distance[i] = minDistance + graph[nextNode][i];
} } }
count++;
}
printf("\nShortest distances from node %d:\n", start);
for (i = 0; i < n; i++) {
printf("To node %d = %d\n", i, distance[i]);
} }
int main() {
int graph[MAX][MAX], n, i, j, start;
printf("Enter number of nodes: ");
scanf("%d", &n);
printf("Enter the cost adjacency matrix (9999 for no direct path):\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
scanf("%d", &graph[i][j]);
}
}
printf("Enter the starting node: ");
scanf("%d", &start);
dijkstra(graph, n, start);
return 0;
}