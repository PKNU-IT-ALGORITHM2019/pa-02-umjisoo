#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define MAX 100
int N;
int j = 0;
double sum = 0;
int x[MAX], y[MAX];
int tour[MAX],tour_min[MAX];
double min=10000000;
void perm(int k);
void swap(int x[], int y[], int i, int j);
double length(int x[], int y[], int i, int j);
int main(void) {
	FILE*in_fp = fopen("input.txt", "r");
	fscanf(in_fp,"%d", &N);
	
	for (int i = 0; i < N; i++) {
		fscanf(in_fp, "%d %d", &x[i], &y[i]);
	}
	fclose(in_fp);
	for (int i = 0; i < N; i++)
		tour[i] = i;
	perm(0);

	printf("sum : %lf ", min);
	for (int i = 0; i < N; i++)
		printf("%d ", tour_min[i]);
	printf("\n");

	return 0;
}

void perm(int k) {
	if (k == N) {
		for (int i = 0; i < k; i++) {
			sum+=length(x, y, i, i+1);
		}
		sum += length(x, y, N - 1, 0);
		if (min > sum) {
			min = sum;
			for (int i = 0; i < N; i++)
				tour_min[i] = tour[i];
		} sum = 0; j = 0;
		return;
	}
	for (int i = k; i < N; i++) {
		
		swap(x, y, k, i);
		perm(k + 1);
		swap(x, y, k, i);
		
	}
}
void swap(int x[],int y[] ,int i, int j) {
	int tmp_X = x[i];
	int tmp_Y = y[i];
	x[i] = x[j];y[i] = y[j];
	x[j] = tmp_X;y[j] = tmp_Y;
	int tmpi = tour[j];
	tour[j] = tour[i];
	tour[i] = tmpi;
}

double length(int x[],int y[],int i,int j) {
	double result = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
	return result;
}