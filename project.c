// C program for the E-library
// Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32

// Create Structure of Library
struct library
{
	char book_name[20];
	char author[20];
	char category[20];
	int pages;
	float price;
};

// Create Structure of Users
struct members
{
	char user_email[20];
	char user_name[20];
	char user_password[20];
	char status;
};

// >>  GLOBAL VARIABLES  << //
// Create a instance
struct library lib[100];
struct members users[100];
// Create file pointer for books
FILE *my_books;
// Create file pointer for counts
FILE *counts;
// Create file pointer for users
FILE *my_users;
// Create file pointer for usercounts
FILE *user_counts;
FILE *temporary;
int count = 0;
int counts_of_user = 0;
char password[20];
#include "myFunctions.h"

// Importing functions from other file //

// Driver Code
int main()
{

	

	// Initialize and get all values from files
	initialize();

	// Start Our Program
	start();

	return 0;
}
