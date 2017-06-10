/** @file core.c
 *
 *  @brief wew
 *
 *
 *
 *
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct irc_user
{
    char *password,
         *nickname,
         *username,
         *realname;
};


int load_config(struct irc_user*);
int authenticate(struct irc_user*);

int main()
{
    struct irc_user *user_config = malloc(sizeof(struct irc_user));
    user_config->password = malloc(32); //TODO: Change to an alloc function
    user_config->nickname = malloc(32); //TODO: Also, remember to free() :)
    user_config->username = malloc(32);
    user_config->realname = malloc(32);
    load_config(user_config);
    return 0;
}

int load_config(struct irc_user* config)
{
    FILE* conf_file = fopen("usr.conf", "r");
    if (conf_file == NULL)
    {
        printf("Error opening file!\n");
        return -1;
    }
    char input[60];
    while (fgets(input, 60, conf_file) != NULL)
    {
        switch (isalpha(input[0]))
        {
            case 0: //skip commented or null lines
                continue;
            default:
                break;
        }
        if (sscanf(input, "password = \"%[^\"]\"\n", config->password) > 0)
        {
            printf("Using password %s\n", config->password);
        }
        if (sscanf(input, "nickname = \"%[^\"]\"\n", config->nickname) > 0)
        {
            printf("Using nickname %s\n", config->nickname);
        }
        if (sscanf(input, "username = \"%[^\"]\"\n", config->username) > 0)
        {
            printf("Using username %s\n", config->username);
        }
        if (sscanf(input, "realname = \"%[^\"]\"\n", config->realname) > 0)
        {
            printf("Using realname %s\n", config->realname);
        }
    }
    fclose(conf_file); //TODO: error checking for fclose (not sup important)
    return 0;
}
