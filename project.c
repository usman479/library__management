// C program for the E-library
// Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>  

// Create Structure of Library
struct library
{
	char book_name[20];
	char author[20];
	char category[20];
	int pages;
	float price;
};

// >>  GLOBAL VARIABLES  << //
// Create a instance
struct library lib[100];
// Create file pointer for books
FILE *my_books;
// Create file pointer for counts
FILE *counts;
FILE *temporary;
int count = 0;

// Importing functions from other file //
#include "myFunctions.h"


// Driver Code
int main()
{

	// Keep the track of the number of
	// of books available in the library
	int i = 0, input;

	// Sets the counts of book from file
	counts = fopen("counts.bin", "rb");
	count = getw(counts);
	fclose(counts);

	// set books from file into lib array
	char str[20] = "books.txt";
	my_books = fopen(str, "rb");
	for (int i = 0; i < count; i++)
	{
	fread(&lib[i], sizeof(struct library), 1, my_books);
	}
	fclose(my_books);

	i  = input = 1;

	// Iterate the loop
	while (input != 0)
	{

		printOptions();

		// Enter the book details
		printf("\n\nEnter one of "
			   "the above: ");
		scanf("%d", &input);

		// Process the input
		switch (input)
		{

		// Add book
		case 1:
			addBooks(i);
			break;

		// Print book information
		case 2:
			printBooks(i);
			break;

		// Take the author name as input
		case 3:
			authorBooks(i);
			break;

		// Print total count
		case 4:
			printf("\n No of books in "
				   "Library : %d",
				   count);
			break;
		case 5:
			deleteBook();
			break;
		case 0:
			exit(0);
		}
	}
	return 0;
}


