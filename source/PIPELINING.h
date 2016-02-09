#ifndef _PIPELINING_H_
#define _PIPELINING_H_

#define MAX_PACKET_LENGTH 10000000

#define MAX_CHUNK_LENGTH

typedef struct _packet{
	unsigned char* packetBuffer;
	int packetLength;
}PACKET;

typedef struct _format{
	char flag;
	short chunkLength;
	unsigned char* chunk;
}WFORMAT;

typedef struct _wBuffer{
	char bufferFlag;
	WFORMAT* wParameter;
}WBUFFER;

/* function for pcap file read. (n times) */

PACKET* ReadPacket(const char fileName[], const int loopSize, int *counter);

/* set prime array, from P^1 to P^32 */
int *CalculatePrime(void);

#endif
