#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
int min_steps(int x, int y) {
	if (x == y) return 0;

	if (x > y) {
		int temp = x;
		x = y;
		y = temp;
	}

	int* minSteps = (int*)malloc((y + 1) * sizeof(int));

	minSteps[x] = 1;
	for (int i = x + 1; i <= y; ++i) {
		minSteps[i] = minSteps[i - 1] + 1;
		if (i % 2 == 0) {
			minSteps[i] = (minSteps[i] < minSteps[i / 2] + 1) ? minSteps[i] : minSteps[i / 2] + 1;
		}
	}

	int result = minSteps[y];
	free(minSteps);
	return result;
}
int main() {
	setlocale(LC_ALL, "Ukr");
	int x, y;
	printf("Введiть значення x та y: ");
	scanf("%d %d", &x, &y);

	int steps = min_steps(x, y);

	printf("Мiнiмальна кiлькiсть крокiв для переходу вiд %d до %d: %d\n", x, y, steps);

	return 0;
}