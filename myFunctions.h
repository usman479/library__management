
// Function Declarations //
void printOptions();
void addBooks(int);
void printBooks(int);
void authorBooks(int);
void deleteBook();
void setCount();
void renderArray();
void addUser(int);
void showUsers(int);
void adminOptions();
void userOptions();
bool authAdmin();
void initialize();
void passwordGetting();
void start();
void searchBook();
// uncomlpete

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
       printf("5. Remove Book\n");
       printf("6. Add User\n");
       printf("7. Show Users\n");
       printf("8. Sign Out\n");
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
       counts = fopen("counts.bin", "wb");
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
              }
              else
              {
                     printf("%s Book Removed", bk_nm);

                     flag = true;
              }
       }
       fclose(temporary);

       remove(originalName);
       rename(temp, originalName);
       if (flag)
       {
              setCount();
              renderArray();
       }
}

void setCount()
{
       counts = fopen("counts.bin", "wb");
       count--;
       count = putw(count, counts);
       fclose(counts);
}

void renderArray()
{
       char str[20] = "books.txt";
       my_books = fopen(str, "rb");
       for (int i = 0; i < count; i++)
       {
              fread(&lib[i], sizeof(struct library), 1, my_books);
       }
       fclose(my_books);
}

void renderArrayUsers()
{

       my_users = fopen("users.txt", "rb");
       for (int i = 0; i < counts_of_user; i++)
       {
              fread(&users[i], sizeof(struct members), 1, my_users);
       }
       fclose(my_users);
}

void addUser(int i)
{
       printf("Enter Name = ");
       scanf(" %[^\n]s", users[i].user_name);

       printf("Enter Email = ");
       scanf(" %[^\n]s", users[i].user_email);

       printf("Enter Password = ");
       scanf(" %[^\n]s", users[i].user_password);

       printf("Enter Status = ");
       scanf(" %c", &users[i].status);

       my_users = fopen("users.txt", "ab");
       fwrite(&users[i], sizeof(struct members), 1, my_users);
       fclose(my_users);
       user_counts = fopen("usersCount.bin", "wb");
       counts_of_user++;
       putw(counts_of_user, user_counts);
       fclose(user_counts);
       printf("User Registered!\n");
}

void showUsers(int i)
{
       printf("you have entered"
              " the following "
              "information\n");
       renderArrayUsers();
       for (i = 0; i < counts_of_user; i++)
       {

              printf("user name = %s  ",
                     users[i].user_name);

              printf("user email = %s  ",
                     users[i].user_email);

              printf("user status = %c",
                     users[i].status);
              printf("\n");
       }
}

void adminOptions()
{
       int input = 1;
       int i = 1;
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
              case 6:
                     addUser(i);
                     break;
              case 7:
                     showUsers(i);
                     break;
              case 8:
                     start();
                     break;
              case 0:
                     exit(0);
              }
       }
}

void userOptions()
{
       int input = 1;
       int i = 1;
       printf("\n\n********######"
              "WELCOME TO E-LIBRARY "
              "#####********\n");
       printf("1. Display "
              "book information\n");
       printf("2. List all books of "
              "given author\n");
       printf("3. Search Book by Name \n");
       printf(
           "4. List the count of book"
           "s in the library\n");
       printf("5. Go Back\n");
       printf("0. Exit\n");

       // Iterate the loop
       while (input != 0)
       {

              // Enter the book details
              printf("\n\nEnter one of "
                     "the above: ");
              scanf("%d", &input);

              // Process the input
              switch (input)
              {

              // Print book information
              case 1:
                     printBooks(i);
                     break;

              // Take the author name as input
              case 2:
                     authorBooks(i);
                     break;

              // Search Book by Name
              case 3:
                     searchBook();
                     break;

              // Print total count
              case 4:
                     printf("\n No of books in "
                            "Library : %d",
                            count);
                     break;
              case 5:
                     start();
                     break;

              case 0:
                     exit(0);
              }
       }
}

bool authAdmin()
{
       char email[20];
       // char password[20];
       printf("Enter Email: ");
       scanf(" %[^\n]s", email);

       passwordGetting();

       int i = 0;
       for (i = 0; i < counts_of_user; i++)
       {
              if ((strcmp(email, users[i].user_email)) == 0 && (strcmp(password, users[i].user_password)) == 0 && users[i].status == 'a')
              {
                     return 1;
              }
       }
       return 0;
}

void passwordGetting()
{
       char ch;
       int i = 0;
       bool result = false;
       for (i = 0; result == false;)
       {
              printf("Enter your password: ");
              while (1)
              {
                     ch = getch();
                     if (ch == ENTER)
                     {
                            password[i] = '\0';
                            result = true;
                            break;
                     }
                     else if (ch == BKSP)
                     {
                            if (i > 0)
                            {
                                   i--;
                                   printf("\b \b");
                            }
                     }
                     else if (ch == TAB || ch == SPACE)
                     {
                            continue;
                     }
                     else
                     {
                            password[i] = ch;
                            i++;
                            printf("*");
                     }
              }
       }
}
void initialize()
{
       // Sets the counts of book from file
       counts = fopen("counts.bin", "rb");
       count = getw(counts);
       fclose(counts);

       // Sets the counts of user from file
       user_counts = fopen("usersCount.bin", "rb");
       counts_of_user = getw(user_counts);
       fclose(user_counts);

       // set books from file into lib array
       char str[20] = "books.txt";
       my_books = fopen(str, "rb");
       for (int i = 0; i < count; i++)
       {
              fread(&lib[i], sizeof(struct library), 1, my_books);
       }
       fclose(my_books);

       // set users from file into users array
       // char str[20] = "books.txt";
       my_users = fopen("users.txt", "rb");
       for (int i = 0; i < counts_of_user; i++)
       {
              fread(&users[i], sizeof(struct members), 1, my_users);
       }
       fclose(my_users);
}

void start(){
       // Keep the track of the number of
       // of books available in the library
       int i = 1, input;

       i = input = 1;
       // Iterate the loop
       while (input != 0)
       {
              printf("1:Admin  2:User  0:Exit");
              printf("\n\nEnter one of the above: ");

              if (0 == scanf("%d", &input))
              {
                     printf("Invalid input\n");
                     fflush(stdin);
                     continue;
              }

              // Process the input
              switch (input)
              {
              case 1:
                     if (authAdmin())
                     {
                            printf("\n********** Logged In **********\n");
                            adminOptions();
                            break;
                     }
                     else
                     {
                            printf("UnAuthenticated\n");
                            break;
                     }

              case 2:
                     userOptions();
                     break;

              case 0:
                     exit(0);
                     break;
              default:
                     printf("Invalid Input\n");
                     break;
              }
       }
}

void searchBook()
{
       char input[20];
       bool flag = true;
       printf("Enter Book Name: ");
       scanf(" %[^\n]s", input);
       int i = 0;
       // printf("%d",strcmp(input, lib[0].book_name));
       for (i = 0; i < count; i++)
       {
              if ((strcmp(input, lib[i].book_name)) == 0)
              {
                     flag = false;
                     printf("Book Name: %s Author: %s Category: %s Pages: %d Price: %f\n",
                            lib[i].book_name,
                            lib[i].author,
                            lib[i].category,
                            lib[i].pages,
                            lib[i].price);
                     break;
              }
       }
       if (flag)
       {
              printf("\"%s\" Book is not available");
       }
}
