#include<stdio.h>
#include<conio.h>

void main()
{
	FILE *fp;
	char str[100];

	clrscr();

	fp = fopen("myfile.txt","w");
	if(fp == NULL)
	{
		printf("Error opening file..!");
		getch();
		return;
	}

	printf("Enter a string to write into file : ");
	gets(str);
	fprintf(fp, "%s",str);
	fclose(fp);

	fp=fopen("myfile.txt", "r");
	if(fp==NULL)
	{
		printf("Error opening file..!");
		getch();
		return;
	}

	printf("\nContents of file : \n");
	fscanf(fp, "%[^\n]",str);
	printf("%s",str);

	fclose(fp);
	getch();
}