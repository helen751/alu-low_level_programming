#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_error - prints a file reading error and exits
 * @filename: name of the file that could not be read
 */
void read_error(char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	exit(98);
}

/**
 * write_error - prints a file writing error and exits
 * @filename: name of the file that could not be written to
 */
void write_error(char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	exit(99);
}

/**
 * close_file - closes a file descriptor
 * @file_descriptor: file descriptor to close
 */
void close_file(int file_descriptor)
{
	if (close(file_descriptor) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
			file_descriptor);
		exit(100);
	}
}

/**
 * copy_content - copies content between two open files
 * @file_from: source file descriptor
 * @file_to: destination file descriptor
 * @source_name: name of the source file
 * @destination_name: name of the destination file
 */
void copy_content(int file_from, int file_to, char *source_name,
		  char *destination_name)
{
	char buffer[1024];
	ssize_t bytes_read, bytes_written, total_written;

	while ((bytes_read = read(file_from, buffer, 1024)) > 0)
	{
		total_written = 0;

		while (total_written < bytes_read)
		{
			bytes_written = write(file_to, buffer + total_written,
					      bytes_read - total_written);
			if (bytes_written <= 0)
				write_error(destination_name);

			total_written += bytes_written;
		}
	}

	if (bytes_read == -1)
		read_error(source_name);
}

/**
 * main - copies the content of one file to another
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int file_from, file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		read_error(argv[1]);

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
	{
		close_file(file_from);
		write_error(argv[2]);
	}

	copy_content(file_from, file_to, argv[1], argv[2]);
	close_file(file_from);
	close_file(file_to);

	return (0);
}
