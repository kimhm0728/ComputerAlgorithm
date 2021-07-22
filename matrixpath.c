#include <stdio.h>
#define MAX(a, b) (((a)>(b))?(a):(b))
int matrix[5][5]={
	{0, 0, 0 , 0, 0},
	{0, 6, 7, 12, 5},
	{0, 5, 3, 11, 18},
	{0, 7, 17, 20, 3},
	{0, 8, 10, 14, 9}
};
int path[5][5]={0}; // 경로를 저장할 배열

void printArray(int n) {
	printf("MATRIX : \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%2d ", matrix[i][j]);
		printf("\n");
	}
	printf("Path : \n");
		for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%2d ", path[i][j]);
		printf("\n");
	}
}

void printResult(int n) {
	int i=n;
	int j=n;
	while(!(i==1&&j==1)) { // i와 j가 모두 1이면 종료
		printf("matrix[%d][%d] : %d\n", i, j, matrix[i][j]);
		if(path[i-1][j]<path[i][j-1]) j--;
		else i--;
	}
}

int matrixPath(int n) {
	for(int i=0;i<=n;i++) path[i][0]=0;
	for(int j=0;j<=n;j++) path[0][j]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			path[i][j]=matrix[i][j]+MAX(path[i-1][j], path[i][j-1]);
	}
	return path[n][n]; // 가장 큰 값(경로) 반환
}

int main() {
	int result=matrixPath(4);
	printf("result = %d\n", result);
	printArray(5);
	printResult(4);
}

