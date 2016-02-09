#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "PIPELINING.h"

/* 
	four step.
	Packet read from pcap file n times.
	Chunking.
	Table lookup.
	write.(pipelining)
*/
int main(int argc, char* argv[]){

	/* 
		[Declaration]
		packetLoopSize : for n * pcap file.
		hashTableLoopSize : n for 2 ^ n		
		hashTableSize : 2 ^ n.
		gBufferSize : for bufferSize (at least 10000). 
		threadHandles : for write Thread.
		buffer : two buffer(temporary save buffer, write buffer)
	*/

	int packetLoopSize = 0;
	int hashTableLoopSize = 0;	
	int hashTableSize = 1;
	int gBufferSize = 0;
	int *primeArray = 0x00L;

	pthread_t* threadHandles = 0x00L;
	WBUFFER* buffer = 0x00L;

	unsigned char** pBuffer = 0x00L;
	int* pLength = 0x00L;

	int totalPacketCounter = 0;
	PACKET* readBuffer = 0x00L;

	/*
		[Definition]
	*/
	if(argc < 4){
		fprintf(stderr, "Usage : [packetLoopSize] [hashTableSize] [bufferSize] [pcapFileName]\n");
		return 0;
	}

	packetLoopSize = atoi(argv[1]);
	hashTableLoopSize = atoi(argv[2]);
	gBufferSize = atoi(argv[3]); 

	readBuffer = ReadPacket(argv[4], packetLoopSize, &totalPacketCounter);	
	
	for(int i = 0; i < hashTableLoopSize; ++i)
		hashTableSize <<= 1;

	

	std::cout << "[hash Table size] : " << hashTableSize <<  std::endl;
	std::cout << "===============================================" << std::endl;
	
	if(readBuffer == 0x00L){
		fprintf(stderr, "Don`t allocate memory in readPacket.\n");
		return 0;
	}

	/*
		[free memory]
	*/

	if(readBuffer != 0x00L){
		for(int i = 0; i < totalPacketCounter; ++i)
			delete[] readBuffer[i].packetBuffer;
		delete[] readBuffer;
		readBuffer = 0x00L;
	}

	return 1;
}
