#include <iostream>
#include <cstdio>
#include <pcap.h>

#include "PIPELINING.h"

PACKET* ReadPacket(const char fileName[], const int loopSize, int *counter){

	PACKET* rTempBuffer = 0x00L;
	char errorBuffer[PCAP_ERRBUF_SIZE];
	const unsigned char* packet = 0x00L;
	struct pcap_pkthdr header;
	pcap_t* handle = 0x00L;
	int totalPacketCounter = 0;

	rTempBuffer = new PACKET[MAX_PACKET_LENGTH];

	if(rTempBuffer == 0x00L) return 0x00L;	
	
	/* 
		[initialize]
	*/
	for(int i = 0; i < PCAP_ERRBUF_SIZE; ++i){
		rTempBuffer[i].packetBuffer = 0x00L;
		rTempBuffer[i].packetLength = 0;
	}

	std::cout << "===============================================" << std::endl;
	std::cout << "[File Read Start] -> " << loopSize << " times" << std::endl;
	
	for(int i = 0; i < loopSize; ++i){

		handle = 0x00L;
		handle = pcap_open_offline(fileName, errorBuffer);
		
		while(packet = pcap_next(handle, &header)){			
			rTempBuffer[totalPacketCounter].packetLength = header.len;
			rTempBuffer[totalPacketCounter++].packetBuffer = new unsigned char[header.len];
		}
	}
	*counter = totalPacketCounter;

	std::cout << "[File Read end] : " << totalPacketCounter <<  std::endl;
	std::cout << "===============================================" << std::endl;
	
	return rTempBuffer;
}

int *CalculatePrime(void){
	int* rTempArray = 0x00L;
	rTempArray = new int[32];

	if(rTempArray == 0x00L) return 0x00L;
	
	




}
