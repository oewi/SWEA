#include <stdio.h>
#include <string.h>

char queue[10000][7];
int top, bot;

void push(char num[]) {
	strcpy(queue[top++ % 10000], num);
}

char* pop() {
	if (top % 10000 == bot % 10000) return 0;
	return queue[bot++ % 10000];
}

void print(char queue[10000][7]) {
	printf("--------\n");
	for (int i = bot; i < top; i++) {
		printf("%s ", queue[i]);
	}
	printf("\n");
	printf("--------\n");
}

void sol(char num[], int c) {

	char max[7] = { 0, };

	for (int j = 0; j < c; j++) {
		int NUM = top - bot;
		int z = 0;
		char visited[10000][7];
		int vcount = 0;
		//print(queue);

		while (z++ < NUM) {
			char* a = pop();
			if (a == 0) break;

			for (int i = 0; i < strlen(a); i++) {
				for (int j = 0; j < strlen(a); j++) {
					if (i == j) continue;
					char tmp[7];
					char temp;
					strcpy(tmp, a);
					temp = tmp[i];
					tmp[i] = tmp[j];
					tmp[j] = temp;
					
					if (vcount == 0) {
						push(tmp);
						strncpy(visited[vcount++], tmp,7);
						//printf("1: %s\n", tmp);
					}
					else {
						int k=0;
						int flag = 1;
						for (k = 0; k < vcount; k++) {
							if (strcmp(tmp, visited[k]) == 0) {
								flag = 0;
								break;
							}
						}
						if (flag) {
							push(tmp);
							strncpy(visited[vcount++], tmp,7);
							//printf("2: %s\n", tmp);
						}
					}
				}
			}
		}
	}

	//print(queue);
	while (1) {
		char* a = pop();
		if (a == 0) break;
		
		if (strncmp(max, a,7) < 0)
			strncpy(max, a,7);
	}
	printf("%s\n", max);
}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		char num[7];
		int c;
		top = bot = 0;

		scanf("%s %d", &num, &c);
		push(num);

		printf("#%d ", i+1);
		sol(num, c);
	}
}
