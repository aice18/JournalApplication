#include<stdio.h>
#include<string.h>

#define MAX_NAME_LEN 50
#define MAX_ENTRY_LEN 1500

int main()
{
	char name[MAX_NAME_LEN];
	char entry[MAX_ENTRY_LEN];
	char filename[MAX_ENTRY_LEN + 4];
	char response[4];
	FILE *file;

	printf("Enter your name:");
	scanf("%s",name);

	strcpy(filename,name);
	strcat(filename,".txt");

	file=fopen(filename,"r");

	if(file==NULL)
	{
		printf("WELCOME %s ! A journal is your completely unaltered voice. Do you want to start your journal(yes/no)?\n\n",name);
		scanf("%s",response);


		if(strcmp(response,"yes")==0)
		{
			file=fopen(filename,"a");
			if(file!=NULL)
			{
				printf("YOUR JOURNEY BEGINS...\n\n");
				getchar();
				fgets(entry,MAX_ENTRY_LEN,stdin);
				fprintf(file,"%s\n",entry);
				fclose(file);
				printf("Journal saved.");
			}
			else
			{
				printf("ERROR:File cannot be created.");
			}
		}
		else
		{
			printf("THANK YOU.HAVE A NICE DAY!");
		}

	}
	else
	{
		fclose(file);
		printf("WELCOME BACK %s !",name);
		printf("If you wanna view your previous entry press 1 or If you wanna start a new journal press 2:");
		int choice;
		scanf("%d",&choice);
		if(choice==1)
		{
			file=fopen(filename,"r");
			if(file!=NULL)
			{
				printf("Previous journal entries\n");
				while(fgets(entry,MAX_ENTRY_LEN,file))
				{
					printf("%s",entry);
				}
				fclose(file);

			}

			else
			{
				printf("File cannot be read.");
			}

		}
		else if(choice==2)
		{
			file=fopen(filename,"a");
			if(file!=NULL)
			{
				printf("\n");
				getchar();
				fgets(entry,MAX_ENTRY_LEN,stdin);
				fprintf(file,"%s\n",entry);
				fclose(file);
				printf("Journal saved.");
			}
		    
		}
		else
		{
			printf("Invalid choice.");
		}
	}
}