#include <stdio.h>

int road[100][2];
int cnt[100];
int visited[100];
int flag;

int ans(int from) {
	if (visited[from] != 0) return -1;
	if (from == 99) {
		flag = 1;
		return 0;
	}

	visited[from] = 1;
	if (cnt[from] == 0) return -1;
	else if (cnt[from] == 1) ans(road[from][0]);
	else if (cnt[from] == 2) {
		ans(road[from][0]);
		ans(road[from][1]);
	}
	return -1;
}

int main() {
	for (int i = 1; i <= 10; i++) {
		int a, N;
		int st, goal;
		scanf("%d %d", &a, &N);
		for (int j = 0; j < N; j++) {
			scanf("%d %d", &st, &goal);
			road[st][cnt[st]++] = goal;
		}

		ans(0);

		if (flag) printf("#%d 1\n", a);
		else printf("#%d 0\n", a);

		for (int j = 0; j < 100; j++) {
			cnt[j] = 0;
			visited[j] = 0;
		}
		flag = 0;
	}
	return 0;
}
