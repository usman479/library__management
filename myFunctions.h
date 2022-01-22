// Function Declarations //
void printOptions();
void addBooks(int);
void printBooks(int);
void authorBooks(int);
void deleteBook();
void setCount();
void renderArray();


// Function Definitions //
void printOptions()
{
    printf("\n\n********######"
           "WELCOME TO E-LIBRARY "
           "#####********\n");
    printf("\n\n1. Add book infor"
           "mation\n2. Display "
           "book information\n");
    printf("3. List all books of "
           "given author\n");
    printf(
        "4. List the count of book"
        "s in the library\n");
    printf("5.Remove Book\n");
    printf("0. Exit\n");
}

void addBooks(int i)
{
    printf("Enter book name = ");
    scanf(" %[^\n]s", lib[i].book_name);

    printf("Enter author name = ");
    scanf(" %[^\n]s", lib[i].author);

    printf("Enter category = ");
    scanf(" %[^\n]s", lib[i].category);

    printf("Enter pages = ");
    scanf("%d", &lib[i].pages);

    printf("Enter price = ");
    scanf("%f", &lib[i].price);

    my_books = fopen("books.txt", "ab");
    fwrite(&lib[i], sizeof(struct library), 1, my_books);
    fclose(my_books);
    counts = fopen("C:\\Users\\DELL\\Desktop\\pf project\\counts.bin", "wb");
    count++;
    putw(count, counts);
    fclose(counts);
}

void printBooks(int i)
{
    printf("you have entered"
           " the following "
           "information\n");
           renderArray();
    for (i = 0; i < count; i++)
    {

        printf("book name = %s",
               lib[i].book_name);

        printf("\t author name = %s",
               lib[i].author);

        printf("\t category = %s",
               lib[i].category);

        printf("\t pages = %d",
               lib[i].pages);

        printf("\t price = %f\n",
               lib[i].price);
    }
}

void authorBooks(int i)
{
    char ar_nm[30];
    printf("Enter author name : ");
    scanf("%s", ar_nm);
    for (i = 0; i < count; i++)
    {

        if (strcmp(ar_nm, lib[i].author) == 0)
            printf("Book Name: %s Author: %s Category: %s Pages: %d Price: %f\n",
                   lib[i].book_name,
                   lib[i].author,
                   lib[i].category,
                   lib[i].pages,
                   lib[i].price);
    }
}

void deleteBook()
{
	bool flag = false;
	char bk_nm[20];
	printf("Enter Book name to remove: ");
	scanf(" %[^\n]s", bk_nm);

	char originalName[50] = "books.txt";
	char temp[50] = "temp.txt";
	temporary = fopen(temp, "ab");

	for (int i = 0; i < count; i++)
	{
		if (strcmp(bk_nm, lib[i].book_name) != 0)
		{
			fwrite(&lib[i], sizeof(struct library), 1, temporary);
			
		} else{
			printf("%s Book Removed", bk_nm);
			
			flag=true;
		}
		
	}
	fclose(temporary);

	remove(originalName);
	rename(temp, originalName);
	if(flag){
              setCount();
		renderArray();
	}
	
}

void setCount()
{
	counts = fopen("C:\\Users\\DELL\\Desktop\\pf project\\counts.bin", "wb");
	count--;
	count = putw(count, counts);
	fclose(counts);
}

void renderArray() {
	char str[20] = "books.txt";
	my_books = fopen(str, "rb");
	for (int i = 0; i < count; i++)
	{
	fread(&lib[i], sizeof(struct library), 1, my_books);
	}
	fclose(my_books);
}