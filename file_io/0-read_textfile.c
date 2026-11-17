#include "main.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_textfile - reads a text file and prints it to standard output
 * @filename: name of the file to read
 * @letters: maximum number of letters to read and print
 *
 * Return: number of letters printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t bytes_read, bytes_written;
	int file_descriptor;

	if (filename == NULL || letters == 0)
		return (0);
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	buffer = malloc(letters);
	if (buffer == NULL)
	{
		close(file_descriptor);
		return (0);
	}
	bytes_read = read(file_descriptor, buffer, letters);
	if (bytes_read == -1)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	free(buffer);
	close(file_descriptor);
	if (bytes_written != bytes_read)
		return (0);
	return (bytes_written);
}
