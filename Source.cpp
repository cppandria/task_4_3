#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>

int get_count_from_file(char* file_content, char* key) {

	int count = 0;
	int content_lenght = strlen(file_content);
	int key_lenght = strlen(key);
	for (int i = 0; i < key_lenght; i++) {
		for (int j = 0; j < content_lenght; j++) {
			if (file_content[j] == key[i])
			{
				count++;
			}
		}
	}
	return count;
}

char *str_replace(char *orig, char *rep, char *with) {
	char *result;
	char *ins;
	char *tmp;
	int len_rep;
	int len_with;
	int len_front;
	int count;
	char empty[] = "";

	if (!orig || !rep)
		return NULL;
	len_rep = strlen(rep);
	if (len_rep == 0)
		return NULL;
	if (!with)
		with = empty;
	len_with = strlen(with);

	ins = orig;
	for (count = 0; tmp = strstr(ins, rep); ++count) {
		ins = tmp + len_rep;
	}

	tmp = result = (char*)malloc(strlen(orig) + (len_with - len_rep) * count + 1);

	if (!result)
		return NULL;

	while (count--) {
		ins = strstr(orig, rep);
		len_front = ins - orig;
		tmp = strncpy(tmp, orig, len_front) + len_front;
		tmp = strcpy(tmp, with) + len_with;
		orig += len_front + len_rep;
	}
	strcpy(tmp, orig);
	return result;
}
int main() {

	char key_word[] = "BASIC";
	char example_string[] = "This is text about basic language. Basic is the best! Remember that only case sensitive LETTERS could be represented as substrings of the word BASIC. So word basic will have count of 0 matched letters and BASIC will have 5 count!		Best regards,		SIGN ME.txt";

	printf("Line is %s \n", example_string);

	printf("Count =%d \n", get_count_from_file(example_string, key_word));
	char replacer[] = "Delphi";
	printf("Line is: %s \n", str_replace(example_string, key_word, replacer));

	return 0;
}
