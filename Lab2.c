//Zeke Wood
//This program takes a specified file and creates a backup with a specified name. It handles 
//the many types of different file names that are allowed by the computer
//instances like a '.' in a file name or a space. If the file exists that it is told to read into
// it will fill it, or it will make a new file with the specified name.

#include <string.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	//the file read from and the file to be written to
	FILE *fileIn, *fileOut;
	//the individual character that is transfered
	int ch;
	//the counters used to find the locations of the '.' & '\'
	int periodCounter;
	int dashCounter;
	//the array that the read in file name is stored to
	char arr[MAX_PATH];


	//if the program is called in command line but no additional arguments are given
	//this error message is displayed
	if(argc == 1)
	{
		printf("Error: source file must be specified\n%s");
	}
	else
	{
		//this is the instance that only a source file is given 
		//so the program must create a name for the new file
		if(argc == 2)
		{
			fileIn = fopen(argv[1], "rb");
			strcpy (arr, argv[1]);
			//searches through till a '\' is found in the code
			for( dashCounter = MAX_PATH; dashCounter > 0; dashCounter-- )
			{
				if(arr[dashCounter] == '\\')
			{
				break;
			}
		}
			//searches through till a '.' is found in the code
		for( periodCounter = MAX_PATH; periodCounter > 0; periodCounter-- )
		{
			if(arr[periodCounter] == '.')
			{
				//the lower number that is stored in a counter
				//corralates with closer proximity to the start of the file name
				//a period farther from the start than the last dash is assumed to be the
				//start of an extension
				if(dashCounter < periodCounter)
				{
					arr[periodCounter] = NULL;
				}
					break;
			}
		}
		//concatinates the .bak extension to the file name	
		strcat (arr, ".bak");
		fileOut = fopen(arr, "wb");
		}
		else
		{
			//this is the case if both a source and a destination file name are given
			fileIn = fopen(argv[1], "rb");
			fileOut = fopen(argv[2], "wb");
		}

		//countinues to transfer character by character untill the EOF
		while((ch = fgetc(fileIn)) != EOF)
			{ 
				fputc(ch, fileOut);
			}
	}
	//closes the files that were opened in the application
	fcloseall;
   
	return 0;
}
