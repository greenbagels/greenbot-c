#ifndef CONFIG_H
#define CONFIG_H

struct c8n_info
{
    const char *server_name;
		const char *port;
		const char *nickname; // only 10 allowed by RFC 2812
		const char *password;
		const char *username;
		const char *realname;
};

int load_config(struct c8n_info *c8n_info, const char *filename);
#endif
