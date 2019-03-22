#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define MAX 100
typedef struct DOT {
	int x;
	int y;
}dot;
int j = 0;
int N;
double sum = 0;
dot Dot[MAX];
int tour[MAX], tour_min[MAX];
double min;
void find_tour(int k, double result);
void swap(dot Dot[], int i, int j);
void tour_swap(dot Dot[], int i, int j);
double length(dot Dot[], int i, int j);
int main(void) {
	FILE*in_fp = fopen("input.txt", "r");
	fscanf(in_fp, "%d", &N);

	for (int i = 0; i < N; i++) {
		fscanf(in_fp, "%d %d", &Dot[i].x, &Dot[i].y);
	}
	fclose(in_fp);

	for (int i = 0; i < N; i++)
		tour[i] = i;
	find_tour(1, 0);
	printf("sum : %lf [ ", min);
	for (int i = 0; i < N; i++)
		printf("%d ", tour_min[i]);
	printf("]\n");

	return 0;
}
void find_tour(int k, double result) {
	if (k == N) {
		result += length(Dot, N - 1, 0);
		/*printf("result: %lf\n", result);*/
		if (j == 0) {
			min = result; j++;
		}
		else if (min > result) {
			min = result;
			for (int i = 0; i < N; i++)
				tour_min[i] = tour[i];
		}
		return;
	}
	for (int i = k; i < N; i++) {
		if (k > 0) {
			if (result > min) {
				i++;
			}

		}
		swap(Dot, k, i);
		find_tour(k + 1, result + length(Dot, k - 1, k));
		swap(Dot, k, i);
	}
}
void swap(dot Dot[], int i, int j) {
	dot tmp = Dot[i];
	Dot[i] = Dot[j];
	Dot[j] = tmp;
	tour_swap(Dot, i, j);
}
void tour_swap(dot Dot[], int i, int j) {
	int tmpi = tour[j];
	tour[j] = tour[i];
	tour[i] = tmpi;
}

double length(dot Dot[], int i, int j) {
	double result = sqrt((Dot[i].x - Dot[j].x)*(Dot[i].x - Dot[j].x) + (Dot[i].y - Dot[j].y)*(Dot[i].y - Dot[j].y));
	return result;
}
