#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * close_file - closes a file descriptor and handles failure
 * @file_descriptor: descriptor to close
 */
void close_file(int file_descriptor)
{
	if (close(file_descriptor) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor);
		exit(100);
	}
}

/**
 * main - copies the contents of one file to another
 * @argc: number of command-line arguments
 * @argv: command-line arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char buffer[1024];
	ssize_t bytes_read, bytes_written, total_written;
	int file_from, file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_file(file_from);
		exit(99);
	}
	while ((bytes_read = read(file_from, buffer, 1024)) > 0)
	{
		total_written = 0;
		while (total_written < bytes_read)
		{
			bytes_written = write(file_to, buffer + total_written,
				bytes_read - total_written);
			if (bytes_written <= 0)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
				close_file(file_from);
				close_file(file_to);
				exit(99);
			}
			total_written += bytes_written;
		}
	}
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close_file(file_from);
		close_file(file_to);
		exit(98);
	}
	close_file(file_from);
	close_file(file_to);
	return (0);
}
