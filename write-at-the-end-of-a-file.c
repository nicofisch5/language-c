#include <stdio.h>
#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	char validation[2];
	char *filename, *textToAdd;
	int fd, cursorPos;

	// Check number of arguments, if not enough display error and finish the program
	if (argc < 3) {
		printf("Missing argument\n");
  		exit(-1);
	}

	filename = argv[1];
	textToAdd = argv[2];

	// Ask for validation
	printf("Do you want to add %s at the end of %s ?\n", textToAdd, filename);
	scanf("%1s", validation);

	// Open the file with the right rights
	fd = open(filename, O_WRONLY | O_CREAT, 0660);
	// If error then display error and finish the program
	if (fd < 0) {
		printf("Error when opening file %s\n", filename);
		exit(-1);
	}

	// Position the cursor
	lseek(fd, 0, SEEK_END);

	// Write text at the end of the file
	cursorPos = write(fd, textToAdd, strlen(textToAdd));
	if(cursorPos < 0) {
		// If error then display error and finish the program
		printf("Error when writing in file %s\n", filename);
		exit(-1);
	}

	// Display new size of the file
	printf("New size of the file: %ld octets\n", lseek(fd, 0, SEEK_END));

	// Close the file
	if(close(fd) < 0) {
		// If error then display error and finish the program
		printf("Error when closing file %s\n", filename);
		exit(-1);
	}

	// Finish program without error
	return 0;
}
