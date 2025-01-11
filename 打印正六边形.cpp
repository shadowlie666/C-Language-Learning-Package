#include<stdio.h>
int main()
{
	int N;
	printf("输入边长:");
	scanf("%d", &N);
	//第一行
	for (int i = 0;i < N;i++) {
		if (i == 0) {
            for (int j = 0;j <N;j++) {
			printf(" ");
		    }
		}
		printf("*");
	}
	printf("\n");
	//第2到2*n-2行
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
	//最后一行
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
