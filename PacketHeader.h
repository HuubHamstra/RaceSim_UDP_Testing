#ifndef PACKETHEADER_H
#define PACKETHEADER_H

typedef unsigned short uint16;
typedef unsigned char uint8;
typedef unsigned int uint32;
typedef unsigned long long uint64;

#include <cstdint> // Inclusie van cstdint voor het definiëren van uint16, uint8, uint32, uint64
#include <iostream>

struct PacketHeader
{
  uint16 m_packetFormat; // 2023
  uint8 m_gameYear; // Game year - last two digits e.g. 23
  uint8 m_gameMajorVersion; // Game major version - "X.00"
  uint8 m_gameMinorVersion; // Game minor version - "1.XX"
  uint8 m_packetVersion; // Version of this packet type, all start from 1
  uint16 m_packetId; // Identifier for the packet type, see below
  uint64 m_sessionUID; // Unique identifier for the session
  float m_sessionTime; // Session timestamp
  uint32 m_frameIdentifier; // Identifier for the frame the data was retrieved on
  uint32 m_overallFrameIdentifier; // Overall identifier for the frame the data was retrieved
  // on, doesn't go back after flashbacks
  uint8 m_playerCarIndex; // Index of player's car in the array
  uint8 m_secondaryPlayerCarIndex; // Index of secondary player's car in the array (splitscreen)
  // 255 if no second player

  unsigned long get(char* buffer){
        unsigned long offset = 0;
        memcpy(&this->m_packetFormat,&buffer[offset],sizeof(this->m_packetFormat));
        offset = offset + sizeof(this->m_packetFormat);
        memcpy(&this->m_gameMajorVersion,&buffer[offset],sizeof(this->m_gameMajorVersion));
        offset = offset + sizeof(this->m_gameMajorVersion);
        memcpy(&this->m_gameMinorVersion,&buffer[offset],sizeof(this->m_gameMinorVersion));
        offset = offset + sizeof(this->m_gameMinorVersion);
        memcpy(&this->m_packetVersion,&buffer[offset],sizeof(this->m_packetVersion));
        offset = offset + sizeof(this->m_packetVersion);
        memcpy(&this->m_packetId,&buffer[offset],sizeof(this->m_packetId));
        offset = offset + sizeof(this->m_packetId);
        memcpy(&this->m_sessionUID,&buffer[offset],sizeof(this->m_sessionUID));
        offset = offset + sizeof(this->m_sessionUID);
        memcpy(&this->m_sessionTime,&buffer[offset],sizeof(this->m_sessionTime));
        offset = offset + sizeof(this->m_sessionTime);
        memcpy(&this->m_frameIdentifier,&buffer[offset],sizeof(this->m_frameIdentifier));
        offset = offset + sizeof(this->m_frameIdentifier);
        memcpy(&this->m_playerCarIndex,&buffer[offset],sizeof(this->m_playerCarIndex));
        offset = offset + sizeof(this->m_playerCarIndex);
        memcpy(&this->m_secondaryPlayerCarIndex,&buffer[offset],sizeof(this->m_secondaryPlayerCarIndex));
        offset = offset + sizeof(this->m_secondaryPlayerCarIndex);

        return offset;
    }

    void print() {
        std::cout << " " << "PacketHeader {" << std::endl;
        std::cout << "   " << "m_packetFormat: " << this->m_packetFormat << std::endl;
        std::cout << "   " << "m_gameMajorVersion: " << this->m_gameMajorVersion << std::endl;
        std::cout << "   " << "m_gameMinorVersion: " << this->m_gameMinorVersion << std::endl;
        std::cout << "   " << "m_packetVersion: " << this->m_packetVersion << std::endl;
        std::cout << "   " << "m_packetId: " << this->m_packetId << std::endl;
        std::cout << "   " << "m_sessionUID: " << this->m_sessionUID << std::endl;
        std::cout << "   " << "m_sessionTime: " << this->m_sessionTime << std::endl;
        std::cout << "   " << "m_frameIdentifier: " << this->m_frameIdentifier << std::endl;
        std::cout << "   " << "m_playerCarIndex: " << this->m_playerCarIndex << std::endl;
        std::cout << "   " << "m_secondaryPlayerCarIndex: " << this->m_secondaryPlayerCarIndex << std::endl;
        std::cout << " " << "}" << std::endl;
    }
};

#endif
