#include "../get_next_line.h"
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void	test_get_next_line(void)
{
	int		fd;
	char	*line;

	// Test 1: reading an empty file
	fd = open("empty_file.txt", O_RDONLY);
	assert(get_next_line(fd) == NULL);
	close(fd);
	// Test 2: reading from a file with a single line
	fd = open("one_line_file.txt", O_RDONLY);
	line = get_next_line(fd);
	assert(line != NULL);
	assert(strcmp(line, "This is a single line file\n") == 0);
	free(line);
	assert(get_next_line(fd) == NULL);
	close(fd);
	// Test 3: reading from a file with multiple lines
	fd = open("multiple_lines_file.txt", O_RDONLY);
	line = get_next_line(fd);
	assert(line != NULL);
	assert(strcmp(line, "This is the first line\n") == 0);
	free(line);
	line = get_next_line(fd);
	assert(line != NULL);
	assert(strcmp(line, "This is the second line\n") == 0);
	free(line);
	close(fd);
}

int	main(void)
{
	test_get_next_line();
	printf("All tests passed!\n");
	return (0);
}