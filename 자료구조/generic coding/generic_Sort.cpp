#include<stdio.h>
#include<stdlib.h>
#include<memory.h> // memcpy()함수를 쓰기위해 include
#include<string.h>
void genericSort(void*, int, size_t, int (*)(void*, void*));
void display(void*, int, size_t, void (*)(void*));
int integerCompare(void*, void*);
int doubleCompare(void*, void*);
int stringCompare(void*, void*);
void integerPrint(void*), doublePrint(void*), stringPrint(void*);
int main()
{
	//정수형데이터 정렬하여 출력하기
	int iArray[10] = { 5,2,9,11,1,8,10,15,20,3 };
	genericSort(iArray, sizeof(iArray) / sizeof(iArray[0]), sizeof(iArray[0]),
		integerCompare);
	printf("[[정수형 데이터 정렬하여 출력하기]]\n");
	display(iArray, sizeof(iArray) / sizeof(iArray[0]), sizeof(iArray[0]),
		integerPrint);

	//실수형데이터 정렬하여 출력하기
	double dArray[5] = { 12.5, 3.12, 7.7, 20.35, 9.8 };
	genericSort(dArray, sizeof(dArray) / sizeof(dArray[0]), sizeof(dArray[0]),
		doubleCompare);

	printf("[[실수형 데이터 정렬하여 출력하기]]\n");
	display(dArray, sizeof(dArray) / sizeof(dArray[0]), sizeof(dArray[0]),
		doublePrint);

	//문자열형데이터 정렬하여 출력하기
	char sArray[7][10] = { "희망", "꿈", "도전", "용기", "노력", "믿음",
	 "협력" };
	genericSort(sArray, sizeof(sArray) / sizeof(sArray[0]), sizeof(sArray[0]),
		stringCompare);
	printf("[[문자열형 데이터 정렬하여 출력하기]]\n");
	display(sArray, sizeof(sArray) / sizeof(sArray[0]), sizeof(sArray[0]),
		stringPrint);
	return 0;
} // end of main()

void genericSort(void *ary, int num, size_t size, int (*compare)(void*, void*)){
	void *p1, *p2, *temp;
	temp = malloc(size);
	for(p1=ary; p1<(char*)ary+(num-1)*size; p1=(char*)p1+size){
		for(p2=(char*)p1+size; p2<(char*)ary+(num)*size; p2=(char*)p2+size){
			if(compare(p1, p2) == 1){
				memcpy(temp, p1, size);
				memcpy(p1, p2, size);
				memcpy(p2, temp, size);
			}
		}
	}
	free(temp);
}

void display(void *ary, int num, size_t size, void (*print)(void*)){
	for(int i=0; i<num; i++){
		print(ary);
		ary = (char*)ary + size;
	}
}

int integerCompare(void *p1, void *p2){
	if(*(int*)p1 > *(int*)p2)
		return 1;
	else if(*(int*)p1 < *(int*)p2)
		return -1;
	else return 0;
}

int doubleCompare(void *p1, void *p2){
	if(*(double*)p1 > *(double*)p2)
		return 1;
	else if(*(double*)p1 < *(double*)p2)
		return -1;
	else return 0;
}

int stringCompare(void *p1, void *p2){
		return strcmp((char*)p1, (char*)p2);
}

void integerPrint(void *p){
	printf("%d\n", *(int*)p);
}

void doublePrint(void *p){
	printf("%.2lf\n", *(double*)p);
}

void stringPrint(void *p){
	printf("%s\n", (char*)p);
}



  /*
[[정수형 데이터 정렬하여 출력하기]]
1. 1
2. 2
3. 3
4. 5
5. 8
6. 9
7. 10
8. 11
9. 15
10. 20
[[실수형 데이터 정렬하여 출력하기]]
1. 3.12
2. 7.70
3. 9.80
4. 12.50
5. 20.35
[[문자열형 데이터 정렬하여 출력하기]]
1. 꿈
2. 노력
3. 도전
4. 믿음
5. 용기
6. 협력
7. 희망
*/
