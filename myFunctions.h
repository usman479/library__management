// Function Declarations //
void printOptions();
int addBooks(int);
void printBooks(int);
void authorBooks(int);
void removeBook();
void setCount();
void renderArray();
int addUser(int);
void showUsers(int);
void adminOptions();
void userOptions();
bool authAdmin();
void initialize();
void passwordGetting();
void start();
void searchBook();
bool verifyEmail(char str[]);
bool nameValidator(char str[]);
void removeUser();
void setUsersCount();

// Function Definitions //

void printOptions()
{
       printf("\n\n********######"
              "WELCOME TO E-LIBRARY "
              "#####********\n\n");
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
       printf("7. Remove User\n");
       printf("8. Show Users\n");
       printf("9. Sign Out\n");
       printf("0. Exit\n");
}

bool nameValidator(char str[])
{
       bool flag = true;

       for (int i = 0; i < strlen(str); i++)
       {
              if (isdigit(str[i]) == 0 && (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == SPACE || str[i] == DOT || str[i] == HYPHEN)
              {
                     flag = false;
              }
              else
              {
                     flag = true;
                     break;
              }
       }
       return flag;
}

int addBooks(int i)
{

       // welcomeHead();
       printf("Enter book name = ");
       scanf(" %[^\n]s", lib[i].book_name);

       printf("Enter author name = ");
       scanf(" %[^\n]s", lib[i].author);
       if (nameValidator(lib[i].author))
       {
              printf("Invalid Input");
              return 0;
       }

       printf("Enter category = ");
       scanf(" %[^\n]s", lib[i].category);
       if (nameValidator(lib[i].category))
       {

              printf("Invalid Input");
              fflush(stdin);
              return 0;
       }

       printf("Enter pages = ");
       if (0 == scanf("%d", &lib[i].pages))
       {

              printf("Invalid input\n");
              fflush(stdin);
              return 0;
       }
       fflush(stdin);

       printf("Enter price = ");
       if (0 == scanf("%f", &lib[i].price))
       {

              printf("Invalid input\n");
              fflush(stdin);
              return 0;
       }
       fflush(stdin);

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

       printf("\nyou have entered"
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

              printf("\t price = %.1f\n",
                     lib[i].price);
       }
}

void authorBooks(int i)
{

       char ar_nm[30];
       printf("Enter author name : ");
       scanf(" %[^\n]s", ar_nm);
       for (i = 0; i < count; i++)
       {

              if (strcmp(ar_nm, lib[i].author) == 0)
                     printf("Book Name: %s Author: %s Category: %s Pages: %d Price: %.1f\n",
                            lib[i].book_name,
                            lib[i].author,
                            lib[i].category,
                            lib[i].pages,
                            lib[i].price);
       }
}

void removeBook()
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

void setUsersCount()
{
       user_counts = fopen("usersCount.bin", "wb");
       counts_of_user--;
       counts_of_user = putw(counts_of_user, user_counts);
       fclose(user_counts);
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

void removeUser()
{

       bool flag = false;
       char userEmail[20];
       printf("Enter User email to remove: ");
       scanf(" %s", userEmail);

       char originalName[50] = "users.txt";
       char temp[50] = "temp.txt";
       temporary = fopen(temp, "ab");

       for (int i = 0; i < counts_of_user; i++)
       {
              if (strcmp(userEmail, users[i].user_email) != 0)
              {
                     fwrite(&users[i], sizeof(struct members), 1, temporary);
              }
              else
              {
                     printf("%s User Removed", userEmail);

                     flag = true;
              }
       }
       fclose(temporary);

       remove(originalName);
       rename(temp, originalName);
       if (flag)
       {
              setUsersCount();
              renderArrayUsers();
       }
       else
       {
              printf("\nThe user you entered is not a member\n");
       }
}

int addUser(int i)
{
       printf("Enter Name = ");
       scanf(" %[^\n]s", users[i].user_name);
       if (nameValidator(users[i].user_name))
       {
              printf("Invalid Input");
              return 0;
       }

       printf("Enter Email = ");
       scanf(" %[^\n]s", users[i].user_email);
       if (!verifyEmail(users[i].user_email))
       {
              printf("\nInvalid Pattern eg.\"xyz@email.com\"");
              return 0;
       }

       passwordGetting();
       strcpy(users[i].user_password, password);

       printf("\nEnter Status = ");
       scanf(" %c", &users[i].status);
       if (users[i].status != 'a' && users[i].status != 'u')
       {

              printf("Invalid Input");
              return 0;
       }

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
       // welcomeHead();
       printf("\n********** Logged In **********\n");
       while (input != 0)
       {
              printOptions();

              // Enter the book details
              printf("\n\nEnter one of "
                     "the above: ");

              if (0 == scanf("%d", &input))
              {
                     printf("Invalid input\n");
                     fflush(stdin);
                     continue;
              }
              fflush(stdin);

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
                     removeBook();
                     break;
              case 6:
                     addUser(i);
                     break;
              case 7:
                     removeUser();
                     break;
              case 8:
                     showUsers(i);
                     break;
              case 9:
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
       // Iterate the loop
       while (input != 0)
       {

              printf("\n\n1. Display "
                     "book information\n");
              printf("2. List all books of "
                     "given author\n");
              printf("3. Search Book by Name \n");
              printf(
                  "4. List the count of book"
                  "s in the library\n");
              printf("5. Go Back\n");
              printf("0. Exit\n");

              // Enter the book details
              printf("\n\nEnter one of "
                     "the above: ");
              if (0 == scanf("%d", &input))
              {
                     printf("\nInvalid Input");
                     fflush(stdin);
                     continue;
              };

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

bool verifyEmail(char email[])
{
       int i, j;
       char pattern[12] = "@email.com";
       bool flag = false;
       bool flag2 = false;
       if((strcmp(email,pattern)) == 0) {
              return true;
       }
       for (i = 0; i < strlen(email); i++)
       {
              if (email[i] == '@')
              {
                     flag = true;
                     for (j = 0; j < strlen(pattern); j++)
                     {
                            if (pattern[j] != email[i])
                            {
                                   flag = false;
                                   flag2 = true;
                                   break;
                            }
                            i++;
                     }
              }
              else
              {
                     flag = false;
              }
              if (flag2)
              {
                     break;
              }
       }
       if (flag)
       {
              return true;
       }
       else
       {
              return false;
       }
}

bool authAdmin()
{
       char email[20];
       // char password[20];
       printf("Enter Email: ");
       scanf(" %s", email);

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

void start()
{
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
              fflush(stdin);
              // Process the input
              switch (input)
              {
              case 1:
                     if (authAdmin())
                     {

                            adminOptions();
                            break;
                     }
                     else
                     {

                            printf("\nUnAuthenticated\n");
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
