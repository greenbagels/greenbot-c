/** @file core.c
 *
 *  @brief Core IRC bot functionality
 *
 *  Copyright (C) 2017 greenbagels
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

//TODO: Refactor code to generic bot with IRC functionality
//      See emgram's changes to greenbot for more info.

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

struct irc_user *alloc_user();
int free_user(struct irc_user *user);
int load_config(struct irc_user*);
int authenticate(struct irc_user*);

int main()
{
    struct irc_user *user_config = alloc_user();
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

struct irc_user *alloc_user()
{
    struct irc_user *conf = malloc(sizeof(struct irc_user));
    conf->password = malloc(32);
    conf->nickname = malloc(32);
    conf->username = malloc(32);
    conf->realname = malloc(32);
    return conf;
}

int free_user(struct irc_user *user)
{
    free(user->password);
    free(user->nickname);
    free(user->username);
    free(user->realname);
    free(user);
    user = NULL;
    return 0;
}
