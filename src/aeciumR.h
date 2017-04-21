#include <stdio.h>	//for print
#include <string.h>	//for memset
#include <stdbool.h>//for bool
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <stdlib.h>	//for exit()
#include <errno.h>	//for errno
#include <getopt.h>	//for argv
#include <sys/ioctl.h>
#include "md5.h"
#include <unistd.h>	//for sleep()

struct usrinfoSet{
	char * usr;
	char * pw;
	char * session;
	char * service;
	char dev[0xc];
	char local_ip[0x10];
	char host_ip[0x10];
	char mac[0x8];
	bool login_states;
	bool recv_states;
	bool find_host;
	bool find_service;
};

struct infoset{
	struct sockaddr_in * pss;
	struct usrinfoSet * psu;
};

void get_session(const char * const pkt, struct usrinfoSet * psu);
void get_service(const char * const pkt, struct usrinfoSet * psu);
unsigned int index_bits1(long index);
unsigned int index_bits2(long index);
unsigned int index_bits3(long index);
unsigned int index_bits4(long index);