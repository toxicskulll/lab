//Graph
#include <stdio.h>
#include <stdlib.h>

int city[10][10], visited[10], n;

void dfs(int start) {
    printf("%d ", start);
    visited[start] = 1;
    for (int i = 1; i <= n; i++)
        if (city[start][i] && !visited[i])
            dfs(i);
}

void bfs(int start) {
    int queue[10], front = 0, rear = 0;
    printf("%d ", start);
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        for (int i = 1; i <= n; i++) {
            if (city[node][i] && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int start, choice;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &city[i][j]);

    printf("Enter starting city: ");
    scanf("%d", &start);

    printf("Choose 1 for DFS, 2 for BFS: ");
    scanf("%d", &choice);

    printf("Cities reachable from %d: ", start);
    if (choice == 1) dfs(start);
    else bfs(start);

    return 0;
}
