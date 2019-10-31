#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

#define DISKNUM 5
#define CYLINDERNUM 3

int cylinders[CYLINDERNUM];

void cylindersRequest(){ // Obtain Random Cylinder Requests
	for(int i = 0; i < CYLINDERNUM; i++){ // Initialize Every Value In Cylinder To -1
		cylinders[i] = -1; // This Is So That 0 Could Be Apart Of Cylinder
	}
	srand(time(NULL)); // Different Seed For Random Number Generator
	for (int i = 0; i < CYLINDERNUM; i++){ // 1000 Cylinders Request
		while(1){ // Loop To Make Sure Value Is Unique Before Moving On
			bool found = false; // Assume Found Is False
			int random = rand() % DISKNUM; // Random Number From 0 to 9999
			for (int j = i; j > -1; j--){ // Check To See If It was Entered Already
				if(cylinders[j] == random){ // If It's Found, It's Not Unique, Break And
					found = true; // If Found, Found = True and Reloop To Get New Random Value
					break; // Break Out
				}
			}
			if(found == false){ // Not Fount After Looping Through Array
				printf("%d- random: %d \n", i, random);
				cylinders[i] = random; // Requesting From a Range From 0-9999
				break; // Unique Is True So i++. Break.
			}
		}
	}
}

int FCFS(int cylinders[],int head){
	int sum = 0;
	for(int i = 0; i < CYLINDERNUM; i++){
		sum += abs(head - cylinders[i]);
		head = cylinders[i];
	}
	return sum;
}

int SSTF(int cylinders[],int head){
	return 0;
}

int SCAN(int cylinders[],int head){
	return 0;
}

int CSCAN(int cylinders[],int head){
	return 0;
}

int LOOK(int cylinders[],int head){
	return 0;
}

int main(){
	cylindersRequest(); // Obtain a Random Series of 1000 Cylinders Requests
	int input; // To Store Disk Head
	printf("Insert Initial Position of the Disk Head Between 0 and %d: ", CYLINDERNUM - 1); // Print
	scanf("%d", &input); // Obtain Initial Position of the Disk Head
	while(input < 0 || input > CYLINDERNUM - 1){ // Makes Sure Input Is Appropriate
		printf("Incorrect Input. Input Has to be Between 0 and %d. You Inputted %d.\n", CYLINDERNUM - 1, input); // Print
		printf("Insert Initial Position of the Disk Head Between 0 and %d: ", CYLINDERNUM -1); // Print
		scanf("%d", &input); // Obtain Initial Position of the Disk Head
	}
	int FCFS_SUM = FCFS(cylinders,input);
	int SSTF_SUM = SSTF(cylinders,input);
	int SCAN_SUM = SCAN(cylinders,input);
	int CSCAN_SUM = CSCAN(cylinders,input);
	int LOOK_SUM = LOOK(cylinders,input);
	printf("Algorithm\t|Total Head Movement\n");
	printf("________________|___________________\n");
	printf("FCFS\t\t|%d\n", FCFS_SUM);
	printf("SSTF\t\t|%d\n", SSTF_SUM);
	printf("SCAN\t\t|%d\n", SCAN_SUM);
	printf("CSCAN\t\t|%d\n", CSCAN_SUM);
	printf("LOOK\t\t|%d\n", LOOK_SUM);
	return 0;
}