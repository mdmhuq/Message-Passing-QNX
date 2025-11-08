#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <string.h>

int main(void) {

	int coid;
	char msg[50];
	char rmsg[50];

	int a, b;
	pid_t pid;
	int chid;

	printf("Please enter pid number:\n");
	scanf("%d", &pid);

	printf("Please enter chid number:\n");
	scanf("%d", &chid);

	coid = ConnectAttach(ND_LOCAL_NODE, pid, chid, _NTO_SIDE_CHANNEL, 0);

	printf("Please enter 1st number for addition:\n");
	scanf("%d", &a);
	printf("Please enter 2nd number for addition:\n");
	scanf("%d", &b);

	sprintf(msg, "%d and %d", a, b);

	MsgSend(coid, msg, sizeof(msg), rmsg, sizeof(rmsg));

	printf("Reply\n%s\n", rmsg);

	ConnectDetach(coid);

	return EXIT_SUCCESS;
}
