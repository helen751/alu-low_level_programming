#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - creates a file and writes text to it
 * @filename: name of the file to create
 * @text_content: null-terminated text to write
 *
 * Return: 1 on success, or -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor;
	ssize_t bytes_written;
	size_t length = 0;

	if (filename == NULL)
		return (-1);
	file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (file_descriptor == -1)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[length] != '\0')
			length++;
		bytes_written = write(file_descriptor, text_content, length);
		if (bytes_written != (ssize_t)length)
		{
			close(file_descriptor);
			return (-1);
		}
	}
	if (close(file_descriptor) == -1)
		return (-1);
	return (1);
}
