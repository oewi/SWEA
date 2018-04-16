#include <stdio.h>

void push(int stack[], int* top, int val) {
	stack[++(*top)] = val;
}

int pop(int stack[], int* top) {
	return stack[(*top)--];
}

main() {

	for (int t = 0; t < 10; t++) {
		int stack[1000];
		int cstack[1000];
		int top = -1;
		int ctop = -1;
		int N;
		int i, j;
		char f[1000];
		int pos[1000];
		int pcur = 0;
		int pcount = 0;

		scanf("%d", &N);
		scanf("%s", f);
		for (i = 0; i < N; i++) {
			if (f[i] >= '0' && f[i] <= '9') {
				pos[pcur++] = f[i] - '0';
			}
			else if (f[i] == '+' || f[i] == '-') {
				
				if (stack[top] == '(') {
					push(stack, &top, f[i]);
				}
				else {
					while (top >= 0 && stack[top] != '(') {
						pos[pcur++] = pop(stack, &top);
					}
					push(stack, &top, f[i]);
				}
			}
			else if (f[i] == '*' || f[i] == '/') {
				if (stack[top] == '(')
					push(stack, &top, f[i]);
				else {
					while (top >= 0 && (stack[top] == '*' || stack[top] == '/') && stack[top] != '(') {
						pos[pcur++] = pop(stack, &top);
					}
					push(stack, &top, f[i]);
				}
			}
			else if (f[i] == '(') {
				push(stack, &top, f[i]);
				pcount++;
			}
			else if (f[i] == ')') {
				while (top >= 0 && (stack[top] != '(')) {
					pos[pcur++] = pop(stack, &top);
				}
				pop(stack, &top);
				pcount++;
			}
		}

		while (top >= 0)
			pos[pcur++] = pop(stack, &top);

		for (i = 0; i < N- pcount; i++) {
			if (pos[i] >= 0 && pos[i] <= 9) {
				push(cstack, &ctop, pos[i]);
			}
			else if (pos[i] == '+') {
				int tmp2 = pop(cstack, &ctop);
				int tmp1 = pop(cstack, &ctop);
				push(cstack, &ctop, tmp1 + tmp2);
			}
			else if (pos[i] == '-') {
				int tmp2 = pop(cstack, &ctop);
				int tmp1 = pop(cstack, &ctop);
				push(cstack, &ctop, tmp1 - tmp2);
			}
			else if (pos[i] == '*') {
				int tmp2 = pop(cstack, &ctop);
				int tmp1 = pop(cstack, &ctop);
				push(cstack, &ctop, tmp1 * tmp2);

			}
			else if (pos[i] == '/') {
				int tmp2 = pop(cstack, &ctop);
				int tmp1 = pop(cstack, &ctop);
				push(cstack, &ctop, tmp1 / tmp2);
			}
		}
		printf("#%d %d\n", t+1, pop(cstack, &ctop));
	}
	return 0;
}
