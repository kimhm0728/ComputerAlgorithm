#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HASH 997  // 해시사이즈
#define LF 0.5 // 적재율의 임계점

int collision_count=0; // 충돌횟수 카운트

void printTable(int table[], int n) {
	for(int i=0;i<n;i++) 
		printf("key[%2d] : %d\n", i, table[i]);
}

int* createTable(int n) {
	int* htable=(int*)calloc(n, sizeof(int));
	// n만큼의 공간을 동적할당
	return htable;
}

int hashInsert(int table[], int key) {
	int i=0; // 충돌횟수
	int address;
	do{
		//address=(key+i)%HASH; // 선형조사
		//address=(key+i*i)%HASH; // 이차원 조사
		address=(key+i*(1+key%991))%HASH; // 더블 해싱
		// 991 -> 997 보다 조금 작은 소수
		if(table[address]==0){
			table[address]=key;
			return address;
		}
		else {
			i++;
			collision_count++;
			printf(">>>>>>collision : key - %d, address - %d\n", key, address);
		}
	}while(i!=HASH);
	printf("overflow");
	return -1;
}

int* reHashing(int table[], int n) {
    int* htable=createTable(n*2);
    for(int i=0;i<n;i++)
        if(table[n]!=0) hashInsert(htable, table[n]);
    return htable;
}
int main() {
	int key=0;
	int address=0;
	int* table;
	int* table1;
	int n=0; // 저장된 원소의 개수
	double lf=0.0;
	
	srand((unsigned int)time(NULL));
	table=createTable(HASH);
	while(lf<LF){
	    key=rand();
		address=hashInsert(table, key);
		n++;
		lf=(double)n/HASH; // 적재율 계산
		printf("Address : %2d, Key : %10d\n", address, key);
	}		
	table1=createTable(HASH*2);
	table1=reHashing(table, HASH);
	while(lf<LF){
		key=rand();
	    address=hashInsert(table1, key);
	    n++;
		lf=(double)n/(HASH*2); // 적재율 계산
		printf("Address : %2d, Key : %10d\n", address, key);
	}
	
	printTable(table1, HASH*2);
	printf("total collision : %d\n", collision_count);
	free(table);
	free(table1);
	
	return 0;
}


