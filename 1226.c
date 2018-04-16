#include <stdio.h>


typedef struct loc {
	int x;
	int y;
} loc;


char map[16][16];
int visited[16][16];
loc queue[5000];
int top;
int bot;

void push(int x, int y) {
	queue[top].x = x;
	queue[top].y = y;
	top++;
}

loc pop() {
	if (top == bot) {
		loc tmp;
		tmp.x = -1;
		tmp.y = -1;
		return tmp;
	}
	return queue[bot++];
}

int ans(loc goal) {
	
	while (1) {
		loc temp = pop();
		//printf("%d %d\n", temp.x, temp.y);
		if (temp.x == -1 && temp.y == -1) break;
		if (temp.x == goal.x && temp.y == goal.y) return 1;
		
		visited[temp.x][temp.y] = 1;
		if (map[temp.x - 1][temp.y] != '1' && visited[temp.x-1][temp.y] == 0) { //up
			push(temp.x - 1, temp.y);
		}
		if (map[temp.x][temp.y + 1] != '1' && visited[temp.x][temp.y+1] == 0) { //right
			push(temp.x, temp.y + 1);
		}
		if (map[temp.x + 1][temp.y] != '1' && visited[temp.x + 1][temp.y] == 0) { //down
			push(temp.x + 1, temp.y);
		}
		if (map[temp.x][temp.y - 1] != '1' && visited[temp.x][temp.y-1] == 0) { //left
			push(temp.x, temp.y - 1);
		}
	}
	return 0;
}

int main() {

	for (int t = 0; t < 10; t++) {
		int ta;
		scanf("%d", &ta);
		int i, j;
		loc st, goal;

		for (i = 0; i < 16; i++) {
			scanf("%s", map[i]);
		}

		for (i = 0; i < 16; i++) {
			for (j = 0; j < 16; j++) {
				if (map[i][j] == '2') {
					st.x = j;
					st.y = i;
				}
				if (map[i][j] == '3') {
					goal.x = j;
					goal.y = i;
				}
			}
		}

		push(st.x, st.y);
		ans(goal) ? printf("#%d 1\n", ta) : printf("#%d 0\n", ta);

		for (i = 0; i < 16; i++)
			for (j = 0; j < 16; j++)
				visited[i][j] = 0;
		top = 0;
		bot = 0;
	}

	return 0;
}
