#include<stdio.h>
int main()
{
	int N;
	printf("����߳�:");
	scanf("%d", &N);
	//��һ��
	for (int i = 0;i < N;i++) {
		if (i == 0) {
            for (int j = 0;j <N;j++) {
			printf(" ");
		    }
		}
		printf("*");
	}
	printf("\n");
	//��2��2*n-2��
	for (int i = 1;i < N;i++) {
		for (int j = 0;j <=N-i-1;j++) {
			printf(" ");
		}
		printf("*");
		for (int k = 0;k < N+2*i-2;k++) {
			printf(" ");
		}
		printf("*");
		printf("\n");
	}
	for (int i = N-2;i >0;i--) {
		for (int j = 0;j <= N - i - 1;j++) {
			printf(" ");
		}
		printf("*");
		for (int k = 0;k < N + 2 * i - 2;k++) {
			printf(" ");
		}
		printf("@");
		printf("\n");
	}
	//���һ��
	for (int i = 0;i < N;i++) {
		if (i == 0) {
			for (int j = 0;j < N;j++) {
				printf(" ");
			}
		}
		printf("*");
	}
	return 0;
}
