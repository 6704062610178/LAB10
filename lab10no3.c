#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct studentRecord {
	char name[64];
	int age;
};
void displayRecord(struct studentRecord student);
void addAge(struct studentRecord *student, int age);

int main () {
	struct studentRecord student[5];
	char tempName[64]; int i;
	for(i = 0; i < 5; i++) {
		sprintf(tempName, "Student%d", i);
		strcpy(student[i].name, tempName);
		student[i].age = i+15;
	}
	for(i = 0; i < 5; i++){
		addAge(&student[i], 10);
	}
	for(i = 0; i < 5; i++){
		displayRecord(student[i]);
	}
	return 0;
}
void displayRecord(struct studentRecord student){
	printf("Name: %s, Age: %d\n", student.name, student.age);
}
void addAge(struct studentRecord *student, int age){
	student->age += age;
}

