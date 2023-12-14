#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct GRAPH {
    int n;
    int a[MAX][MAX];
}DOTHI;

// hàm thêm cạnh vào đồ thị
void add_edge(DOTHI *g, int from, int to) {
    g->a[from][to] = 1;
}

// hàm in ra ma trận kề
void print_matrix(DOTHI g) {
    int i, j;
    for(i = 1; i <= g.n; i++) {
        for(j = 1; j <= g.n; j++) {
            printf("%d ", g.a[i][j]);
        }
        printf("\n");
    }
}

// hàm khởi tạo đồ thị với giá trị 0
void init_graph(DOTHI *g, int n) {
    int i, j;
    g->n = n;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            g->a[i][j] = 0;
        }
    }
}

int main() {
    int n, m, i, u, v;
    DOTHI g;
    g.n = 4;
    init_graph(&g, g.n);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 2, 4);
    add_edge(&g, 3, 4);
    print_matrix(g);


    return 0;
}
