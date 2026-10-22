#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

void strcpy_upper(char* dest, const char* src);
void strremdup(char* dest, const char* src);
void swap_random(char* src);
void string_histogram(int* count, const char* src);
void print_string_histogram(int* count);

int main(void)
{
	printf("Welcome.\n");
	char dest[50] = "";
	//char* pDest = dest;
	const char string[] = "Bro Code";
	//const char* pString = string;
	strcpy_upper(dest, string);
	printf("Old: %s, new: %s\n", string, dest);

	char dest2[50] = "";
	char* pDest2 = dest2;
	const char string2[] = "AABBCDDz";
	const char* pString2 = string2;
	strremdup(pDest2, pString2);

	printf("Old: %s, new: %s\n", string2, dest2);

	swap_random(pDest2);
	printf("Swapped: %s\n", dest2);

	int array[26] = { 0 };
	
	string_histogram(array, string2);
	print_string_histogram(array);

	//printf("%d, %d, %d, %d, %d", 'a', 'z', 'A', 'Z', toupper('A'));


	return 0;
}

void strcpy_upper(char* dest, const char* src) {
	for (int i = 0; src[i]!='\0' ;i++)
	{
		dest[i] = (char)toupper(src[i]);
	}
}

void strremdup(char* dest, const char* src) {
	dest[0] = src[0];
	int dest_write = 1;
	for (int i =1; src[i]!='\0'; i++)
	{
		char last_input = src[i - 1];

		if (last_input!=src[i]) /// AABBC
		{
			dest[dest_write++] = src[i];
		}
	}

}

void swap_random(char* src){
	srand((unsigned int)time(NULL));
	int possible_max = (int)strlen(src);
	int possible_min = 1;
	int number_of_changed_chars = (rand() % (possible_max - possible_min + 1)) + possible_min;

	for (int i = 0; i < number_of_changed_chars; i++)
	{
		int j = rand() % strlen(src);
		int k = rand() % strlen(src);
		char tmp = src[j];
		src[j] = src[k];
		src[k] = tmp;
	}
}

void string_histogram(int* count, const char* src) {
	for (int i = 0; src[i]!='\0'; i++)
	{
		//int index = toupper(src[i]) - 65;
		count[toupper(src[i]) - 65]++;
	}

}

void print_string_histogram(int* count) {
	//int size =(int) sizeof(count) / sizeof(count[0]);

	for (int i = 0; i <26; i++)
	{
		if (count[i]!=0)
		printf("%c: %d\n", 97 + i, count[i]);
	}

}