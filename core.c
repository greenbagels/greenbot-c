/** @file core.c
 *
 *  @brief Core IRC bot functionality
 *
 *  Copyright (C) 2018 greenbagels
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

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#include "network.h"
//#include "auth.h"
//#include "plugin.h"
#include "config.h"

#define BUF_SIZE 512

int main()
{
	struct c8n_info conn_info;
	// TODO: add parsing for nondefault conf file
	const char *fname = "./conf/default.conf";
	if (load_config(&conn_info, fname) != 0)
	{
		fprintf(stderr, "Something happened\n");
		return 1;
	}
	return 0;
}
