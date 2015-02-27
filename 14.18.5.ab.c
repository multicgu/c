#include<stdio.h>
typedef struct {
	char fname[10];
	char lname[10];
} name;
typedef struct {
	name names;
	float grade[3];
	float avegrade;
} student;
