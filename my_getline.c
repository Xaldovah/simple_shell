#include "shell.h"

/**
 * read_buffer - Reads data into the buffer from the file descriptor
 * @buffer: The buffer to store the data
 * @desc: The file descriptor
 * @start: The starting position in the buffer
 * @finish: The ending position in the buffer
 *
 * Return: Number of bytes read
 */
int read_buffer(char *buffer, int desc, int *start, int *finish)
{
	int total = 0;
	int bytes_read = 1;
	int b;

	while (total < 1024 && bytes_read != 0)
	{
		bytes_read = read(desc, buffer + total, 1024 - total);
		*start = 0;
		total += bytes_read;
		*finish = total;

		for (b = 0; bytes_read != 0 && b < *finish; b++)
		{
			if (buffer[b] == '\n')
			{
				bytes_read = 0;
			}
		}
	}

	if (total == 0)
	{
		buffer[0] = 0;
		return (total);
	}

	buffer[total] = 0;
	return (total);
}

/**
 * process_buffer - Processes the buffer to extract the line
 * @buffer: The buffer containing the data
 * @start: The starting position in the buffer
 * @lineptr: Pointer to the line buffer
 * @line_length: Length of the line
 *
 * Return: Number of characters in the line
 */
int process_buffer(char *buffer, int *start, char **lineptr, int line_length)
{
	for (; buffer[*start]; (*start)++)
	{
		if (*start == 1024)
		{
			break;
		}

		if (buffer[*start] == '\n')
		{
			(*lineptr)[line_length] = '\n';
			(*start)++;
			line_length++;
			(*lineptr)[line_length] = '\0';
			return (line_length);
		}
		else
		{
			(*lineptr)[line_length] = buffer[*start];
		}

		line_length++;
	}

	if (line_length + *start >= 1024)
	{
		int prev_size = line_length;
		int new_size = prev_size + 1024;

		*lineptr = _realloc(*lineptr, prev_size, new_size);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	else
	{
		(*lineptr)[line_length + *start] = 0;
		return (line_length);
	}

	return (line_length);
}

/**
 * _getline - Reads a line from a file descriptor or standard input
 * @ptr: Pointer to the buffer that will store the line
 * @desc: File descriptor
 *
 * Return: Number of characters read
 */
int _getline(char **ptr, int desc)
{
	int buffer_size = 1025, total_bytes = 0;
	int line_length = 0;
	static char buffer[1025];
	static int start, finish;

	if (desc == -2)
	{
		start = 0;
		finish = 0;
	}
	if (ptr == NULL)
		return (0);
	if (*ptr == NULL)
	{
		*ptr = malloc(sizeof(char) * buffer_size + 1);
		if (*ptr == NULL)
		{
			return (-1);
		}
	}
	while (1)
	{
		if (start == finish)
		{
			total_bytes = read_buffer(buffer, desc, &start, &finish);
			if (total_bytes == 0)
			{
				buffer[0] = 0;
				return (total_bytes);
			}
		}
		line_length = process_buffer(buffer, &start, ptr, line_length);

		if (line_length == -1)
		{
			return (-1);
		}
		else if (line_length != 0)
		{
			return (line_length);
		}
	}
}

