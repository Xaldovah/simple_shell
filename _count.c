#include "shell.h"

/**
  * count_words - This function counts the words the user types
  * @input: contains str
  *
  * Return: Number of words counted
  */

int count_words(char *input)
{
	int a = 0, word_count = 0, status = 0;

	while (input[a])
	{
		if (input[a] == ' ' || input[a] == '\n' || input[a] == '\t')
			status = 0;
		else if (status == 0)
		{
			status = 1;
			word_count++;
		}

		a++;
	}

	return (word_count);
}

/**
  * count_chars - This function counts the delimiters present
  * @input: Contains delimiters
  * @delimiters: The delimiters to be searched in the string
  *
  * Return: Number of delimiters found
  */
int count_chars(char *input, char *delimiters)
{
	int a = 0, b = 0, char_count = 0;

	while (delimiters[a])
	{
		b = 0;
		while (input[b])
		{
			if (input[b] == delimiters[a])
				char_count++;
			b++;
		}
		a++;
	}

	return (char_count);
}
