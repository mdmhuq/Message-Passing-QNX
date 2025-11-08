#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/neutrino.h>

int main(void) {

	int chid;
	int rcvid;
	int a, b;
	char msg[50];
	int result;

	chid = ChannelCreate(0);
	printf("PID is %d and chid is %d\n", getpid(), chid);

	while (1) {
		rcvid = MsgReceive(chid, msg, sizeof(msg), NULL);
		sscanf(msg, "%d and %d", &a, &b);
		result = a + b;
		memset(msg, 0, sizeof(msg));

		sprintf(msg, "Result: %d", result);

		MsgReply(rcvid, 0, msg, sizeof(msg));
	}

	ChannelDestroy(chid);

	return EXIT_SUCCESS;
}
