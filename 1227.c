#include <stdio.h>

typedef struct loc {
	int x;
	int y;
} loc;

char map[100][100];
int visited[100][100];
loc queue[10000];
int top, bot;

int push(int x, int y) {
	queue[top % 10000].x = x;
	queue[top % 10000].y = y;
	top++;
	if (top % 10000 == bot % 10000) return -1;
	return 0;
}

loc pop() {
	if (top % 10000 == bot % 10000) {
		loc temp;
		temp.x = -1;
		temp.y = -1;
		return temp;
	}
	return queue[bot++];
}

int ans(loc go) {
	while (1) {
		loc tmp = pop();
		if (tmp.x == -1 && tmp.y == -1) break;
		if (tmp.x == go.x && tmp.y == go.y) return 1;

		visited[tmp.x][tmp.y] = 1;
		if (map[tmp.x - 1][tmp.y] != '1' && visited[tmp.x - 1][tmp.y] == 0) {
			push(tmp.x - 1, tmp.y);
		}
		if (map[tmp.x + 1][tmp.y] != '1' && visited[tmp.x + 1][tmp.y] == 0) {
			push(tmp.x+1, tmp.y);
		}
		if (map[tmp.x][tmp.y-1] != '1' && visited[tmp.x][tmp.y-1] == 0) {
			push(tmp.x, tmp.y-1);
		}
		if (map[tmp.x][tmp.y+1] != '1' && visited[tmp.x][tmp.y+1] == 0) {
			push(tmp.x, tmp.y+1);
		}
	}
	return 0;
}


int main() {
	int t = 10;
	while (t--) {
		int i, j;
		int a;
		loc st, go;
		scanf("%d", &a);
		for (i = 0; i < 100; i++) {
			scanf("%s", map[i]);
		}

		for (i = 0; i < 100; i++) {
			for (j = 0; j < 100; j++) {
				if (map[i][j] == '2') {
					st.x = j;
					st.y = i;
				}
				if (map[i][j] == '3') {
					go.x = j;
					go.y = i;
				}
			}
		}
		push(st.x, st.y);
		ans(go) ? printf("#%d 1\n", a) : printf("#%d 0\n",a);
		
		top = 0;
		bot = 0;
		
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				visited[i][j] = 0;
	}
	return 0;
}
