#include <stdio.h>
int main()
{
	char line[150];
	int vowels, consonant, i, option, j, k;
	vowels = consonant = 0;
	printf("Enter a line of string: ");
	fgets(line, sizeof(line), stdin);
	for (i = 0; i <= 2000; i++)
	{



		for (int i = 0; line[i] != '\0'; ++i) {
			if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' ||
				line[i] == 'o' || line[i] == 'u' || line[i] == 'A' ||
				line[i] == 'E' || line[i] == 'I' || line[i] == 'O' ||
				line[i] == 'U') {
				++vowels;
			}
			else if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) {
				++consonant;
			}

		}
		printf("select your option");
		printf("\n1.Show the number of vowels\n2.Show the number of consonants\n3.Convert the string to upper case\n4.Convert the string to lower case\n5.Show the string\n6.Add another string\n7.Exit");
		scanf("%d", &option);
		if (option == 1) {
			printf("Vowels: %d", vowels);
		}
		else if (option == 2)
		{
			printf("\nConsonants: %d", consonant);
		}
		else if (option == 3)
		{
			printf("\n upper case of the string is:\n");
			for (j = 0; line[j] !='\0' ; ++j)
			{
				printf("%c", toupper(line[j]));
			}
		}
		else if (option == 4)
		{
			printf("\n lower case of the string is : \n");
			for (k = 0; line[k] != '\0'; k++)
			{
				printf("%c", tolower(line[k]));
			}
		}
		else if (option == 5)
		{
			printf("\n The String is:\n");
			for (i = 0; i <= 100; i++)
			{
				printf("%c", line[i]);
			}
		}
		else if (option == 6)
		{
			printf("\n Please enter another string\n");
			fgets(line, sizeof(line), stdin);

		}
		else {
			break;
		}

		printf("Enter any key to continue");
		getch();
	}
	return 0;
}
