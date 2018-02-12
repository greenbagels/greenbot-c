#include <stdio.h>
#include <libconfig.h>

#include "config.h"

int load_config(struct c8n_info *c8n_info, const char *filename)
{
	config_t config;
	printf("Ok, going to open file with name %s\n", filename);
	config_init(&config);
	int status = CONFIG_TRUE;
	status &= config_read_file(&config, filename);
	status &= config_lookup_string(&config, "connection.user.nickname", &c8n_info->nickname);
	status &= config_lookup_string(&config, "connection.user.username", &c8n_info->username);
	status &= config_lookup_string(&config, "connection.user.realname", &c8n_info->realname);
	status &= config_lookup_string(&config, "connection.user.password", &c8n_info->password);
	status &= config_lookup_string(&config, "connection.server.name", &c8n_info->server_name);
	status &= config_lookup_string(&config, "connection.server.port", &c8n_info->port);
	config_destroy(&config);
	return !status;
}
