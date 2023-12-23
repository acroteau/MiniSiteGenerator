#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<strfunc.h>
#include<taggen.h>

int helpCommand()
{
    printf("\nThe following commands are available as arguments or in interactive form:\n\n");
    printf("createsite | cs : Create a new website project\n");
    printf("generatesite | gs : Generate html for an existing website project\n");
    printf("modifysite | ms : Modify an existing website project\n");
    printf("help | h : Print this help text\n\n");

    return 0;
}

int manageCommand(const char* command, int argumentCount, const char* arguments[])
{
    char* lowerCommand = toLower(command);

    if (strcmp("createsite", lowerCommand) == 0 || strcmp("cs", lowerCommand) == 0)
    {
        char* classes[3] = {"test1", "test34", "test456"};
        char* generatedTag = generateTag("h1", "un osti de titre", "titre_test", classes);
        printf(generatedTag);
        free(generatedTag);
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