#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 3

void program();
int input_from_user(char *passwd,int flag);
int solve_passwd(char *temp,int limit,int index,char *passwd,int flag);


int main()
{
	program();
	return 0;
}


void program()
{

	char *passwd;
	char *temp;
	int control,select;
	int limit;

	passwd = (char *) malloc(1*sizeof(char));


	do{

		printf("1- I will enter number Password\n");
		printf("2- I will enter alphabet Password\n");
		printf("3- I will enter number and alphabet Password\n");
		printf("4- I will enter number and alphabet and special Character(.|,|-|_) Password\n");
		scanf("%d",&select);
		getchar();
		control = input_from_user(passwd,select);
	}while(control != 1);

	printf("Solving your Password ! \n");
	for (limit = 1; limit <= MAX_CHAR ; ++limit)
	{

		temp = (char *) malloc((limit+1)*sizeof(char));

		control = solve_passwd(temp,limit,0,passwd,select);

		if (control == 1)
			break;
	}



	printf("%s\n",temp );

}


int input_from_user(char *passwd,int flag)
{
	int ii;
	int i;


	printf("Enter Password(Max Character %d)\n",MAX_CHAR);

	for (i = 0, ii = i; *(passwd+i)!='\n' && i < MAX_CHAR ; )
	{
	    scanf("%c",passwd+i);
	    getchar();
	    do{
	    	if (flag == 1)
	    	{
	    		printf("girdi: %c\n",*(passwd+i)	);

	    		if ( !( (*(passwd+i)>47 && *(passwd+i)<58) ) )
	    		{
	    			printf("1Enter again! It is not valid character.\n");
	    			scanf("%c",(passwd+i));
	    			getchar();
	    		}
	    		else 
	    			break;
	    	}
	    	else if (flag == 2)
	    	{
	    		if ( !( (*(passwd+i)>64 && *(passwd+i)<91) || (*(passwd+i)>96 && *(passwd+i)<123) ) )
	    		{
	    			printf("Enter again! It is not valid character.\n");
	    			scanf("%c",(passwd+i));
	    			getchar();
	    		}
	    		else 
	    			break;
	    	}
	    	else if (flag == 3)
	    	{
	    		if ( !( (*(passwd+i)>64 && *(passwd+i)<91) || (*(passwd+i)>96 && *(passwd+i)<123) || (*(passwd+i)>47 && *(passwd+i)<58) ) )
	    		{
	    			printf("Enter again! It is not valid character.\n");
	    			scanf("%c",(passwd+i));
	    			getchar();
	    		}
	    		else 
	    			break;
	    	}
	    	else if (flag == 4)
	    	{
	    		if ( !( (*(passwd+i)>64 && *(passwd+i)<91) || (*(passwd+i)>96 && *(passwd+i)<123) || (*(passwd+i)>47 && *(passwd+i)<58) || ((*(passwd+i)>43 && *(passwd+i)<47)) || (*(passwd+i)==95) ) )
	    		{
	    			printf("Enter again! It is not valid character.\n");
	    			scanf("%c",(passwd+i));
	    			getchar();
	    		}
	    		else 
	    			break;
	    	}
	    }while(1);
	    printf("asf\n");
	    ii=i;
	    ++i;
	    passwd = realloc(passwd,(i+1)*sizeof(char));
   	}
   	printf("Your Password is efficient.\n");
   	return 1;
}


int solve_passwd(char *temp,int limit,int index,char *passwd,int flag)
{
	int control;
	int j;

	if (index + 1 != limit)
	{
		for (j = 44; j < 123 ; ++j)
		{
			if (flag == 1)
			{
				if (j == 44)
					j = 48;
				if (j == 58)
					break;
			}
			else if (flag == 2)
			{
				if (j == 44)
					j = 65;
				if (j == 91)
					j == 97;
				else if(j == 123)
					break;
			}
			else if (flag == 3)
			{
				if (j == 44)
					j = 48;
				if (j == 58)
					j=65;
				else if (j == 91)
					j == 97;
				else if(j == 123)
					break;
			}			
			else if (flag == 4)
			{
				if (j == 47)
					j++;
				else if (j == 58)
					j = 65;
				else if (j == 91)
					j = 95;
				else if (j == 96)
					j++;
			}		


			*(temp + index) = j;
			control = solve_passwd(temp,limit,index+1,passwd,flag);
			
			if (control == 1)
			{
				return 1;
			}
		}
		return 0;
	}



	if (index + 1  == limit)
	{

		for (j = 44; j < 123 ; ++j)
		{
			if (flag == 1)
			{
				if (j == 44)
					j = 48;
				if (j == 58)
					break;
			}
			else if (flag == 2)
			{
				if (j == 44)
					j = 65;
				if (j == 91)
					j == 97;
				else if(j == 123)
					break;
			}
			else if (flag == 3)
			{
				if (j == 44)
				{
					j = 48;
				}
				if (j == 58)
					j=65;
				else if (j == 91)
					j == 97;
				else if(j == 123)
					break;
			}			
			else if (flag == 4)
			{
				if (j == 47)
					j++;
				else if (j == 58)
					j = 65;
				else if (j == 91)
					j = 95;
				else if (j == 96)
					j++;
			}	
			
			*(temp + index) = j;

			if (0 == strcmp(temp,passwd) )
			{
				return 1;
			}
		}
		return 0;
	}
	
}