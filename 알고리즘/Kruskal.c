#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int parent;
	int depth;
}nodetype;

typedef nodetype universe;
universe U[5];

void makeset(int i) {
	U[i].parent = i;
	U[i].depth = 0;
}

int find(int i) {
	int j = i;
	while (U[j].parent != j)
		j = U[j].parent;
	return j;
}

void merge(int p, int q) {
	if (U[p].depth == U[q].depth) {
		U[p].depth += 1;
		U[q].parent = p;
	}
	else if (U[p].depth < U[q].depth)
		U[p].parent = q;
	else U[q].parent = p;
}

_Bool equal(int p, int q) {
	if (p == q)
		return 1;
	else
		return 0;
}

void initial(int n) {
	int i;
	for (i = 1; i <= n; i++)
		makeset(i);
}

typedef struct set_of_edge {
	int i;
	int j;
	int distance;
}set_of_edge;

void sort(int m, set_of_edge* E) {
	set_of_edge temp;
	for (int i = 0; i < m - 1; i++)
		for (int j = 0; j < m - 1 - i; j++)
			if (E[j].distance > E[j + 1].distance) {
				temp = E[j];
				E[j] = E[j + 1];
				E[j + 1] = temp;
			}
}

void add(int n, set_of_edge e, set_of_edge* F) {
	for (int k = 0; k < n; k++)
		if (F[k].distance == 0) {
			F[k] = e;
			break;
		}
}

void kruskal(int n, int m, set_of_edge* E, set_of_edge* F) {
	int i, j, k = 0, p, q;
	set_of_edge e;

	sort(m, E);
	for (int k = 0; k < n; k++) {
		F[k].i = 0;
		F[k].j = 0;
		F[k].distance = 0;
	}
	initial(n);

	while (F[n-2].distance == 0) {
		e = E[k];
		i = e.i;
		j = e.j;
		p = find(i);
		q = find(j);
		if (!equal(p, q)) {
			merge(p, q);
			add(n, e, F);
		}
		k++;
	}
}

int main() {
	int n, m;
	set_of_edge* E, * F;

	printf("node의 갯수를 입력하세요 :");
	scanf("%d", &n);
	printf("\nedge의 갯수를 입력하세요 :");
	scanf("%d", &m);

	E = (set_of_edge*)malloc(m * (sizeof(set_of_edge)));
	F = (set_of_edge*)malloc(n * (sizeof(set_of_edge)));

	printf("\n두개의 vertex와 거리를 차례대로 모두 입력하세요 :\n");
	for (int k = 0; k < m; k++) {
		scanf("%d %d %d", &E[k].i, &E[k].j, &E[k].distance);
	}

	kruskal(n, m, E, F);

	for (int k = 0; k < n - 1; k++)
		printf("(v%d, v%d)  %d\n", F[k].i, F[k].j, F[k].distance);
}
