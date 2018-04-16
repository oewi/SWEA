#include <stdio.h>
#include <string.h>

char stack[1000];
int cstack[1000];
int cur;
int ccur;

void push(char a) {
	stack[cur++] = a;
}

char pop() {
	if (cur > 0) return stack[--cur];
	else return 'x';
}

void cpush(int a) {
	cstack[ccur++] = a;
}

int cpop() {
	if (ccur > 0) return cstack[--ccur];
	else return 0xffffff;
}

int main() {

	for (int a = 0; a < 10; a++) {
		int N;
		char f[1000];
		char pos[1000];
		int pcur = 0;
		int ccur = 0;
		cur = 0;
		scanf("%d", &N);
		scanf("%s", f);

		for (int i = 0; i < N; i++) {
			if (f[i] >= '0' && f[i] <= '9')
				pos[pcur++] = f[i];
			else if (f[i] == '+' || f[i] == '-') {
				if (cur == 0) push(f[i]);
				else if (stack[cur - 1] == '+' || stack[cur - 1] == '-') {
					char tmp = pop();
					pos[pcur++] = tmp;
					push(f[i]);
				}
			}
			else if (f[i] == '*' || f[i] == '/') {

			}
		}
		while (cur > 0) pos[pcur++] = pop();

		pos[pcur] = 0;
		//printf("%s\n", pos);

		for (int i = 0; i < N; i++) {
			if (pos[i] >= '0' && pos[i] <= '9')
				cpush(pos[i] - '0');
			else if (pos[i] == '+') {
				int tmp2 = cpop();
				int tmp1 = cpop();
				cpush(tmp1 + tmp2);
			}
			else if (pos[i] == '-') {
				int tmp2 = cpop();
				int tmp1 = cpop();
				cpush(tmp1 + tmp2);
			}
			else if (pos[i] == '*') {
				int tmp2 = cpop();
				int tmp1 = cpop();
				cpush(tmp1 * tmp2);
			}
			else if (pos[i] == '/') {
				int tmp2 = cpop();
				int tmp1 = cpop();
				cpush(tmp1 / tmp2);
			}
		}

		printf("#%d %d\n", a+1, cpop());

		for (int i = 0; i < 1000; i++) {
			stack[i] = 0;
			cstack[i] = 0;
		}
	}
	return 0;
}
