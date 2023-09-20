// online banking system
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// header files importing complete
struct user
{
   char phone[50];
   char ac[50];
   char password[50];
   float balance;
};
// structure for storing the details of the user

int main()
{
   struct user usr, usr1;                   // usr is an instance of user
   int choice, opt;                         // for the users choice
   int cont = 1;                            // counter variable used for loop control
   float amount = 0.0, amount1 = 0.0;       // initialization before the arithmetics
   FILE *fp;                                // storinig the user in the file
   char filename[50], phone[50], pword[50]; // for storing the information passed by the user
   printf("\n WHat do you want to do ? ");
   printf("\n Enter 1 to Register an account ");
   printf("\n Enter 2 to  Log in to existing account \n");
   printf("\n Enter your choice : ");
   scanf("%d", &choice);
   if (choice == 1) // register a new account
   {
      printf("\n Enter your account number \n > ");
      scanf("%s", usr.ac);
      printf("\n Enter your phone number \n > ");
      scanf("%s", usr.phone);
      printf("\n Enter your password for your new account \n > ");
      scanf("%s", usr.password);
      usr.balance = 0.0;
      // storing the structure in the file according to the phone number
      // when accessing the structure in the file , it would be done
      // according to the file name
      strcpy(filename, usr.phone); // for copying the string
      // using string contcatination
      fp = fopen(strcat(filename, ".dat"), "w"); // w for write mode
      fwrite(&usr, sizeof(struct user), 1, fp);
      if (fwrite != 0)
      {
         printf("\n\n Account sucessfully registered ");
      }
      else
      {
         printf("\n\n Sorry something went wrong ");
         printf("\n Account registration failed ");
      }
   }
   if (choice == 2)
   {
      printf("\n Enter the phone number \n > ");
      scanf("%s", phone);
      printf("\n Enter the password \n > ");
      scanf("%s", pword);
      strcpy(filename, phone); // copying the string
      fp = fopen(strcat(filename, ".dat"), "r");
      // concatinating the string for the read only purpose
      if (fp == NULL)
      {
         printf("\n Account number not registered \n ");
      } // checking if the file exists or not
      else
      {
         fread(&usr, sizeof(struct user), 1, fp);
         // it ill read the content of the file name
         // and store it in the usr type which is created
         fclose(fp);
         if (!strcmp(pword, usr.password))
         { // checking for the matching of the passwords
            printf("\n Password matched, opening account ");
            printf("\n Account opened \n");
            while (cont != 0)
            {
               printf("\n Enter 1 for balance inquiry");
               printf("\n Enter 2 for depositing cash into account ");
               printf("\n Enter 3 for withdrawing amount ");
               printf("\n Enter 4 for online transfer ");
               printf("\n Enter 5 for changing the password ");
               printf("\n > "); // giving the user choices
               scanf(" %d", &opt);
               switch (opt)
               {
               case 1:
                  printf("\n Your current balance is Rs. %.2f ", usr.balance);
                  break; // displaying complete
               case 2:
                  printf("\n For depositing the cash , ");
                  printf("\n Enter the amount ");
                  printf("\n > ");
                  scanf("%f", &amount); // for storing the balance in the amount variable
                  usr.balance = usr.balance + amount;
                  // adding amount entered by the user to the existing amount
                  fp = fopen(filename, "w"); // opening the file in write mode
                  fwrite(&usr, sizeof(struct user), 1, fp);
                  if (fwrite != NULL)
                  {
                     printf("\n Sucess !! ");
                     printf("\n Transaction complete ");
                  }
                  fclose(fp); // file editiing over thus closing the file
                  break;
               case 3:
                  printf("\n For withrawing the cash , ");
                  printf("\n Enter the amount ");
                  printf("\n > ");
                  scanf("%f", &amount1); // for storing the balance in the amount variable
                  usr.balance = usr.balance - amount1;
                  // adding amount entered by the user to the existing amount
                  fp = fopen(filename, "w");
                  fwrite(&usr, sizeof(struct user), 1, fp); // opening the file in write mode
                  if (fwrite != NULL)
                  {
                     printf("\n Sucess !! ");
                     printf("\n Transaction complete ");
                  }
                  fclose(fp); // file editing complete thus closing the file
                  break;
               case 4:
                  printf("\n For the online transfer, ");
                  printf("\n Enter the phone number of the account holder ");
                  printf("\n > ");
                  scanf("%s", phone);
                  printf("\n Enter the amount to transfer ");
                  printf("\n > ");
                  scanf("%f", &amount);
                  strcpy(filename, phone);                   // checking for the file in database
                  fp = fopen(strcat(filename, ".dat"), "r"); // opening the file in read mode
                  if (fp == NULL)
                  {
                     printf("\n Phone number not registered ");
                     printf("\n Account not found ");
                     return 0;
                  }
                  else
                  {
                     fread(&usr1, sizeof(struct user), 1, fp);
                     fclose(fp); // file cclosing complete
                     if (amount > usr.balance)
                     { // checking for the balance
                        printf("\n Amount to transfer not available ");
                        printf("\n Insufficient balance ");
                     }
                     else
                     {
                        fp = fopen(filename, "w"); // opening the file in write mode
                        usr1.balance = usr1.balance + amount;
                        fwrite(&usr1, sizeof(struct user), 1, fp);
                        fclose(fp); // editing complete thus closing the file
                        if (fwrite != NULL)
                        {
                           printf("\n Sucess !! ");
                           printf("\n Transaction complete ");
                           strcpy(filename, usr.phone);
                           fp = fopen(strcat(filename, ".dat"), "w");
                           usr.balance = usr.balance - amount;
                           fwrite(&usr, sizeof(struct user), 1, fp);
                           fclose(fp);
                        }
                     }
                  }
                  break;
               case 5:
                  int a;
                  printf("\n Are you sure u want to change the password ? ");
                  printf("\n Enter 1 for YES and 0 for NO ");
                  printf("\n > ");
                  scanf("%d", &a);
                  if (a == 1)
                  {
                     printf("\n Please enter the new password ");
                     printf("\n > ");
                     scanf("%s", pword);
                     fp = fopen(filename, "w");
                     strcpy(usr.password, pword);
                     fwrite(&usr, sizeof(struct user), 1, fp);
                     if (fwrite != NULL)
                     {
                        printf("\n Sucess !! ");
                        printf("\n Password changed ");
                     }
                  }
                  break;
               default:
                  printf("\n SORRY WRONG CHOICE ");
               }
               printf("\n\n Do you want to want to continue the transactions ");
               printf("\n Enter any number for YES and 0 for NO : ");
               scanf("%d", &cont);
            }
         }
         else
         {
            printf("\n INVALID PASSWORD ");
            printf("\n Try again !\n");
         }
      }
   }
   return 0;
}