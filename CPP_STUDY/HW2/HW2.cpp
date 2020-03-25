#pragma warning (disable : 4996)
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "doublyLinkedlist.h"
#include "string.h"
#define WLEN 60

void getpointWord(List*, char(*)[WLEN]);
void printState(List*, List*, int);
void userInput(List*, List*, int*, int*);

int main()
{
	List pointWord, inputWord;
	char word[5][WLEN];
	int cnt=1, point=0;
	char firstWord[WLEN] = "pointer";
	createList(&pointWord);
	createList(&inputWord);
	assert(addFirst(&inputWord, firstWord, WLEN, stringMemCopy));
	getpointWord(&pointWord, word);
	
	while (point != 100) {
		printState(&pointWord, &inputWord, cnt);
		userInput(&pointWord, &inputWord, &cnt, &point);
	}

	printf("** 당신의 점수는 %d점입니다.\n", point);
}
void getpointWord(List *pointWord, char(*word)[WLEN]) {
	FILE* fp;
	char* res;
	int len;

	printf("# 포인트 단어를 파일로부터 입력 받는 중입니다...\n\n");
	fp = fopen("C:\\Users\\jm943\\Documents\\C\\generic coding\\generic list\\pointWord.txt", "rt");
	assert(fp != NULL);
	for (int i = 0; i < 5; i++) {
		res = fgets(word[i], WLEN, fp);
		assert(res != NULL);
		len = strlen(word[i]);
		word[i][len-1] = '\0';
		assert(addFirst(pointWord, word[i], WLEN, stringMemCopy));
	}
	fclose(fp);

	sortList(pointWord, WLEN, stringCompare, stringMemCopy, stringClear);

}

void printState(List *pointWord, List *inputWord, int cnt) {
	Node* curp;
	curp = pointWord->head->next;
	printf("* 포인트단어 : ");
	for (int i = 0; i < pointWord->size; i++) {
		stringPrint(curp+1);
		curp = curp->next;
	}
	printf("\n* 사용자 입력 단어 : ");
	curp = inputWord->head->next;
	for (int i = 0; i < inputWord->size; i++) {
		stringPrint(curp + 1);
		curp = curp->next;
	}
	printf("\n끝말잇기 단어 입력(%d회차) : ", cnt);
}

void userInput(List* pointWord, List* inputWord, int *cnt, int *point) {
	char temp[WLEN];
	int len;
	len = strlen((char*)(inputWord->tail->prev + 1));
	scanf("%s", temp);
	if (temp[0] != ((char*)(inputWord->tail->prev + 1))[len - 1]) {
		printf("잘못 입력하셨습니다.\n\n\n");
	}
	else {
		printf("\n\n");
		addLast(inputWord, temp, WLEN, stringMemCopy);
		if (removeNode(pointWord, temp, stringCompare, stringClear))
			*point += 20;
		++* cnt;
	}
}