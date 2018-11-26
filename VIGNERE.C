#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

void vigenereCipher(char *,char *);
void encipher();
void decipher();

void main()

{
//clrscr();

     int choice;
     //loop takes choice from user and calles appropriate function
     while(1)
     {
	  printf(" press 1 to Encrypt Text");
	  printf(" \n press 2 Decrypt Text");
	  printf("\n press 3 to Exit");
	  printf("\nEnter Your Choice : ");
	  scanf("%d",&choice);
	  fflush(stdin);
	  if(choice == 3)
	       exit(0);
	  else if(choice == 1)
	  {
	       encipher();
	       }
	  else if(choice == 2)
	       decipher();
	  else
	       printf("Please Enter Valid Option.");
     }

     getch();
}

void encipher()
{
     unsigned int i,j;
     char input[257],key[33];
     printf("Enter Text to be Encrypted [Max. 256 characters/ only alphabets]: ");
     gets(input);
     printf("Enter Encryption Key [Max. 32 Characters/ only aphabets]: ");
     gets(key);
     for(i=0,j=0;i<strlen(input);i++,j++)
     {
	  //repeat the key if you are at end of it.
	  if(j>=strlen(key))
	  {
	       j=0;
	  }

	  //actual logic -> character from input + character from key % 26 is encrypted charater
	  printf("%c",65+(((toupper(input[i])-65)+(toupper(key[j])-65))%26));
     }
     printf("\n");
}

void decipher()
{
     unsigned int i,j;
     char input[257],key[33];
     int value;
     printf("Enter Text to be Decrypted [Max. 256 characters/ only alphabets]:- ");
     gets(input);
     printf("Enter Decryption Key [Max. 32 Characters/ only aphabets]: ");
     gets(key);
     for(i=0,j=0;i<strlen(input);i++,j++)
     {
	  //repeat the key if you are at end of it.
	  if(j>=strlen(key))
	  {
	       j=0;
	  }
	  //similar to encipher only difference is you need to subtract
	  value = (toupper(input[i])-64)-(toupper(key[j])-64);
	  //make positive if value is negative.
	  if( value < 0)
	  {
	       value = value * -1;
	  }
	  printf("%c",65 + (value % 26));
     }
  printf("\n");
}