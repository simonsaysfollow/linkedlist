#include<stdio.h>
#include<stdlib.h>

/*    functiion prototype      */

	void displayClassInfoSimonT();
	void displayMenu();
	void extractDigitInfoSimonT();
	int *createArray(int *arrayOfIntegers, int numberOfIntegers);
	void printOriginal(int *arrayOfIntegers, int numberOfIntegers);
	void linkedList(int *arrayOfIntegers,int numberOfIntegers);

/* 		Driver		*/

int main() {

	int option;

	do { 

		displayClassInfoSimonT();
		displayMenu();

		printf("Enter an integer for option + Enter:  ");
		scanf("%d", &option);

		switch(option) {
			case 1:
				extractDigitInfoSimonT();
				break;
			case 2:
				printf("\nHave fun!\n\n");
				break;
			default:
				printf("\nWrong Option!\n\n");
		}

	} while (option != 2);

};

	/* 		Function Definition        */


void displayClassInfoSimonT() {
	printf("\nCIS 27 - Data Strutures\n"
		   "Laney College\n"
		   "Simon Tekeste\n\n"
		"Assignment Information --\n"
		"  Assignment Number: Homework 2,\n"
		"                     Coding Assignment -- Exercise #1\n"
		"  Written by:        Simon T\n"
		"  Submitted Date:    03/01/2018");
};

void displayMenu() {
 	printf("\n\n****************************************************\n"
				 "*                  MENU - HW #2                    *\n"
				 "*  1. Calling extractDigitInfoSimonT()            *\n"
				 "*  2. Quit                                         *\n"
				 "****************************************************\n\n");
};

int* createArray(int *arrayOfIntegers,int numberOfIntegers) {	
 	
	for(int countOfIntegers = 0; countOfIntegers < numberOfIntegers; countOfIntegers++) {
		printf("    Enter integer #%d: ",countOfIntegers + 1);
		scanf("\n%d", &(*(arrayOfIntegers + countOfIntegers)));
	}	

 	return arrayOfIntegers;
};

void printOriginal(int* arrayOfIntegers,int numberOfIntegers) {
	
	printf("\nThe original array: \n");
 	 for (int original = 0; original < numberOfIntegers; original++) {		
 	 	printf("  %d\n", arrayOfIntegers[original]);
	}

 };

void linkedList(int* arrayOfIntegers,int numberOfIntegers) {

	typedef struct digitInfoNode {
		int digitValue;

		struct digitInfoNode* next;
	}digitInfoNodeSimonT;


	int digitCountAry[10] = {0};
	int current;
	digitInfoNodeSimonT* head = NULL;
	

	for(int iterator = 0; iterator < numberOfIntegers; iterator++) {
		
		current = arrayOfIntegers[iterator] > 0 ? arrayOfIntegers[iterator] : -arrayOfIntegers[iterator];
		
		do {
			digitCountAry[current % 10] = 1;
			current /= 10;
		} while (current != 0);
	}


	for (int counter = 0; counter <= 9; counter++) {
	
		head = (digitInfoNodeSimonT*) malloc(sizeof(digitInfoNodeSimonT));

		if (head == NULL){
			printf("%d\n",head->digitValue);
		}else{
			head->digitValue = counter;
			printf("hello %d\n",head->digitValue=counter);
			head->next = NULL;	
		}	
	}
};


void extractDigitInfoSimonT() {
	int *arrayOfIntegers;
	int numberOfIntegers;

	printf("\n  How many integers? ");  //  finds the size of the array
	scanf("%d", &numberOfIntegers); 

		if (numberOfIntegers <= 0) {
			printf("  \n\nInvalid input!\n\n");
			extractDigitInfoSimonT();
		}   

	arrayOfIntegers = (int *)malloc(numberOfIntegers * sizeof(int));

	createArray(arrayOfIntegers,numberOfIntegers);
	printOriginal(arrayOfIntegers, numberOfIntegers);
	linkedList(arrayOfIntegers, numberOfIntegers);

};





