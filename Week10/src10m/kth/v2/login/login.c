/****************************************************************************
 * login.c
 *
 * Rob Bowden
 * rob@cs.harvard.edu
 *
 * A silly program that validates a username and password combination
 ***************************************************************************/

#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    // get username
    printf("Please enter your username: ");
    char* username = GetString();
    if (username == NULL)
        return 1;

    // get password
    printf("Please enter your password: ");
    char* password = GetString();
    if (password == NULL)
        return 1;

    // check to see if the username/password combination
    // was valid
    if ((strcmp(username, "rob") == 0 && strcmp(password, "thisiscs50") == 0) ||
        (strcmp(username, "tommy") == 0 && strcmp(password, "i<3javascript") == 0))
    {
        printf("Success!! You now have access.\n");
    }

    // deny them access!
    else
    {
        printf("Invalid login.\n");
    }

    // free memory allocated by GetString
    free(username);
    free(password);

    // that's all folks!
    return 0;
}
