#include <stdio.h>

char check[10000];
int cur = 0;

void push(char a) {
	//if (cur >= 9999) return;
	check[cur++] = a;
}

char pop() {
	if (cur <= 0) return 0;
	return check[--cur];
}

int main() {
	char str[10000];
	for (int i = 0; i < 10; i++) {
		int cnt, j;
		int tmp;
		int cur = 0;
		scanf("%d", &cnt);
		scanf("%s", str);
		for (j = 0; j < cnt; j++) {
			tmp = str[j];
			if (tmp == '(' || tmp == '[' || tmp == '{' || tmp == '<')
				push(tmp);
			else {
				char tmp2 = pop();
				if (tmp2 == 0) break;
				if (tmp == ')' && tmp2 == '(');
				else if (tmp == ']' && tmp2 == '[');
				else if (tmp == '}' && tmp2 == '{');
				else if (tmp == '>' && tmp2 == '<');
				else break;
			}
		}
		if (!cur && j == cnt) printf("#%d 1\n", i + 1);
		else printf("#%d 0\n", i + 1);

		for (j = 0; j < cnt; j++)
			check[j] = 0;
	}
	return 0;
}
