#include <stdio.h>

int queue[8];
int top, bot;
int push(int n) {
	queue[top++ % 8] = n;
}

int pop() {
	return queue[bot++ % 8];
}

void print() {
	for (int i = 0; i < 8; i++) 
		printf("%d ", queue[i]);
	printf("\n");
}

int main() {
	int t = 10;
	while (t--) {
		int i, num, flag = 1;
		int val;
		top = 0;
		bot = 0;

		scanf("%d", &val);
		for (i = 0; i < 8; i++) {
			scanf("%d", &num);
			push(num);
		}
		//print();

		while (flag) {
			for (int j = 1; j <= 5; j++) {
				int tmp = pop();
				if (tmp - j > 0) push(tmp - j);
				else {
					push(0);
					flag = 0;
					break;
				}
			}
			//print();
		}

		printf("#%d ", val);
		for (i = 0; i < 8; i++) {
			printf("%d ", pop());
		}
		printf("\n");
	}
	return 0;
}
