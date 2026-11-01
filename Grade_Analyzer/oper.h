#ifndef OPER_H
#define OPER_H
#include <stdio.h>

int readTotalStudents() {
	int totalNum;
	do {
		printf("Entre Total Students : ");
		scanf_s("%d", &totalNum);
	} while (totalNum <= 0 || totalNum > 100);
	return totalNum;
	
}

float readGrade(int index) {
	float grd;
	do {
		printf("Entre student %d grade : ", index);
		scanf_s("%f", &grd);
	} while (grd > 20 || grd < 0);

	return grd;
}

float avgGrade(const float grd[], int len) {
	float sum = 0;
	for (int i = 0; i < len; i++) {
		sum += grd[i];
	}

	return sum / len;
}

float max(const float grd[], int len) {
	float max = grd[0];
	for (int i = 1; i < len; i++) {
		if (grd[i] > max) {
			max = grd[i];
		}
	}
	return max;
}

float min(const float grd[], int len) {
	float min = grd[0];
	for (int i = 1; i < len; i++) {
		if (grd[i] < min) {
			min = grd[i];
		}
	}
	return min;
}

int passingRecord(const float grd[], int len) {
	int count = 0;
	for (int i = 0; i < len; i++) {
		if (grd[i] >= 10) {
			count++;
		}
	}
	return count;
}

float passingPercent(float totalNum, float passingCount) {
	return (passingCount / totalNum) * 100;
}


void printResult(int totalNum, float avg, float max, float min, int pass, int failed, float passRate) {
	printf(" --------- Grade Analysis --------- ");
	printf("\n	Number of students: %d", totalNum);
	printf("\n	Average grade: %2.f", avg);
	printf("\n	Highest grade: %2.f", max);
	printf("\n	Lowest grade: %2.f", min);
	printf("\n	Students passed: %d", pass);
	printf("\n	Students failed: %d", failed);
	printf("\n	Pass rate: %2.f%% \n", passRate);

}

#endif
