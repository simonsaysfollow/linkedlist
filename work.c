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

	displayClassInfoSimonT();

	do { 

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

	int holder;
	int *arrayOfSorts;

	arrayOfSorts = (int *)malloc(numberOfIntegers * sizeof(int));

	for (int sortArray = 0; sortArray < numberOfIntegers; sortArray++) {

		arrayOfSorts[sortArray] = arrayOfIntegers[sortArray];
	}

	for (int sorting = 0; sorting < numberOfIntegers; sorting++) {

		for (int order = sorting + 1;order < numberOfIntegers; order++) {

			if (arrayOfSorts[sorting] > arrayOfSorts[order]){

				holder = arrayOfSorts[sorting];

				arrayOfSorts[sorting] = arrayOfSorts[order];

				arrayOfSorts[order] =  holder;
				
			}
		}
	}
	
	printf("\nCalling extractDigitInfoSimonT()\n\n");
	printf("After the function completed and returned the info, interesting \n"
			"facts are shown below.\n");

	typedef struct digitInfoNode {
		int digitValue;
		int countingDigits;
		int theValue;
		struct digitInfoNode* next;
	}digitInfoNodeSimonT;


	int countingDigits[10] = {0};
	int current;
	digitInfoNodeSimonT* head = NULL;
	

	for(int iterator = 0; iterator < numberOfIntegers; iterator++) {
		
		current = arrayOfSorts[iterator] > 0 ? arrayOfSorts[iterator] : -arrayOfSorts[iterator];
		
		do {
			countingDigits[current % 10]++;
			current /= 10;
		} while (current != 0);
	}


	for (int counter = 0; counter <= 9; counter++) {
	
		if (countingDigits[counter] <= 9){
			 head = (digitInfoNodeSimonT*)malloc(sizeof(digitInfoNodeSimonT));

			if (head != NULL) {

				head->digitValue = counter;
				head->countingDigits = arrayOfSorts[counter];
				head->next = NULL;	

			}
		}	
		
		if ((head->countingDigits = countingDigits[counter]) >= 1){

			printf("    Digit %d is seen %d time(s); and \n"
				" 	%d can be found in\n",head->digitValue = counter, 
				head->countingDigits = countingDigits[counter], head->digitValue = counter);

			for (int iterator = 0; iterator <= numberOfIntegers; iterator++){
				/* if (arrayOfSorts[iterator]%10 == counter){
					printf("          %d\n",arrayOfSorts[iterator]);
					------> this is the perfect spacing <-------- */
				//}
			}
		}
	}

	printf("\n");
	free(head);
	free(arrayOfSorts);
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

	free(arrayOfIntegers);

};





