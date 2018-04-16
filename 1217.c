#include <stdio.h>

int ans(int n, int m) {
	if (m > 0) return n * ans(n,m-1);
	else return 1;
}

int main() {
	for (int i = 0; i < 10; i++) {
		int z;
		scanf("%d", &z);
		int a, b;
		scanf("%d %d", &a, &b);
		printf("#%d %d\n", z, ans(a, b));
	}
	return 0;
}
