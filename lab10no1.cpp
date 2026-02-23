#include<stdio.h>
#include<iostream>
#include <cstring>

using namespace std;

typedef struct {
	char loginname[64];
	char password[64];
} account ;

typedef struct {
	char stdID[25];
	char nameSurname[25];
	account stdACC;
} hoststd;

int check(char *userr,char *pass,hoststd cs[],int size){
	int i;
	for(i = 0;i < size;i++){
		if(strcmp(userr,cs[i].stdACC.loginname) == 0 && 
		   strcmp(pass,cs[i].stdACC.password) == 0){
			return i;
		}
	}
	return -1;
}

int main(){
	hoststd cs[5] = {
		{"66-040626-2686-9","MR.A",{"user1", "passwd1"}},
		{"66-040626-2686-8","MR.B",{"user2", "passwd2"}},
		{"66-040626-2686-7","MR.C",{"user3", "passwd3"}},
		{"66-040626-2686-6","MR.D",{"user4", "passwd4"}},
		{"66-040626-2686-5","MR.E",{"user5", "passwd5"}}
	};
			
	char userr[64];
	char pass[64];
	
	cin >> userr >> pass;

	int index = check(userr, pass, cs, 5);

	if(index != -1){
		cout << "Welcome " << cs[index].nameSurname << endl;
	}
	else{
		cout << "Incorrect login or password" << endl;
	}
}
