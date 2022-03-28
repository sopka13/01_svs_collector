
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <cstring>
#include <string>
#include <arpa/inet.h>

typedef struct			s_vars
{
	int					argc;
	char				**argv;
	char				**envp;

	int					src_sock_fd;
	struct sockaddr_in	src_addr;
	char				buff[256];
}						t_vars;
