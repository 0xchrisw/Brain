// To do:
// Keyword colors
// Data simulator

#ifndef Brain_h
#define Brain_h

#include "WProgram.h"

#define MAX_PACKET_LENGTH 32
#define EEG_POWER_BANDS 8

class Brain {
	public:
	  // TK Support for soft serials
		Brain(HardwareSerial &_brainSerial);	
    void update();
    boolean sendCSV;
    boolean noisyErrors;
    boolean debug;

    byte getSignalQuality();    
    byte getAttention();
    byte getMediation();
    unsigned long* getPowerArray();
    unsigned long getDelta();
    unsigned long getTheta();
    unsigned long getLowAlpha();
    unsigned long getHighAlpha();
    unsigned long getLowBeta();
    unsigned long getHighBeta();
    unsigned long getLowGamma();
    unsigned long getMidGamma();

  private:
    HardwareSerial* brainSerial;    
    byte packetData[MAX_PACKET_LENGTH];
    boolean inPacket;
    byte latestByte;
    byte lastByte;
    byte packetIndex;
    byte packetLength;
    byte checksum;
    byte checksumAccumulator;
    byte eegPowerLength;
    boolean hasPower;
    void clearPacket();
    void clearEegPower();
    boolean parsePacket();
    void printPacket();
    void init();
    void printCSV(); // maybe should be public?    
    void printDebug();

    byte signalQuality;
    byte attention;
    byte meditation;
    
    // Lighter to just make this public, instead of using the getter?
    unsigned long eegPower[EEG_POWER_BANDS];
    



};

#endif