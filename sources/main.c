#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int helpCommand()
{
    printf("\nThe following commands are available as arguments or in interactive form:\n\n");
    printf("createsite | cs : Create a new website project\n");
    printf("generatesite | gs : Generate html for an existing website project\n");
    printf("modifysite | ms : Modify an existing website project\n");
    printf("help | h : Print this help text\n\n");

    return 0;
}

char* toLower(const char* stringInput)
{
    size_t inputLenght = strlen(stringInput);
    char* lowerString = (char *) malloc(inputLenght);

    for(int i=0; i<strlen(stringInput); i++)
    {
        lowerString[i] = tolower(stringInput[i]);
    }

    return lowerString;
}

int manageCommand(const char* command, int argumentCount, const char* arguments[])
{
    char* lowerCommand = toLower(command);

    if (strcmp("createsite", lowerCommand) == 0 || strcmp("cs", lowerCommand) == 0)
    {
        return 0;
    }

    if (strcmp("generatesite", lowerCommand) == 0 || strcmp("gs", lowerCommand) == 0)
    {
        return 0;
    }

    if (strcmp("modifysite", lowerCommand) == 0 || strcmp("ms", lowerCommand) == 0)
    {
        return 0;
    }

    if (strcmp("help", lowerCommand) == 0 || strcmp("h", lowerCommand) == 0)
    {
        return helpCommand();
    }

    printf("Invalid command \"%s\". Use command help or h to get a list of all supported commands.\n", command);

    free(lowerCommand);

    return -1;
}

int managePrompt()
{
    printf("Please enter a supported command:\n");

    char entry[20];
    scanf("%19s", entry);

    return manageCommand(entry, 0, NULL);
}

int manageArguments(int argumentCount, const char* arguments[]) 
{
    if(argumentCount > 1) // a command is specified
    {
        return manageCommand(arguments[1], argumentCount - 2, arguments);
    }
    else // interactive mode, no command is specified
    {
        return managePrompt();
    }
}

int main(int argc, const char* argv[]) 
{
    printf("MiniSiteGenerator v0.01\n"); // empty file as a first test commit

    manageArguments(argc, argv);

    return 0;
}