#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text to an existing file
 * @filename: name of the file
 * @text_content: null-terminated text to append
 *
 * Return: 1 on success, or -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor;
	ssize_t bytes_written;
	size_t length = 0;

	if (filename == NULL)
		return (-1);
	file_descriptor = open(filename, O_WRONLY | O_APPEND);
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
