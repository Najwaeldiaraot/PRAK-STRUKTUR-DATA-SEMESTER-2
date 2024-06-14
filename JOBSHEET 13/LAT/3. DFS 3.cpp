//Created by 23343079_Najwa Eldiara Owilia Tiksa
#include <stdio.h>
void DFS(int);
int G[10][10], visited[10], n; // n adalah jumlah simpul dan graf disimpan dalam array G[10][10]
int main()
{
    int i, j;
    printf("Masukkan jumlah simpul:");

    scanf("%d", &n);
    // membaca matriks keberdekatan
    printf("\nMasukkan matriks keberdekatan dari graf:");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    // visited diinisialisasi menjadi nol
    for (i = 0; i < n; i++)
        visited[i] = 0;
    DFS(0);
}
void DFS(int i)
{
    int j;
    printf("\n%d", i);
    visited[i] = 1;
    for (j = 0; j < n; j++)
        if (!visited[j] && G[i][j] == 1)
            DFS(j);
}
