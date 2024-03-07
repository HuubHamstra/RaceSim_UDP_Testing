#ifndef PACKETHEADER_H
#define PACKETHEADER_H

#include <cstdint> // Inclusie van cstdint voor het definiëren van uint16_t, uint8_t, uint32_t, uint64_t

struct PacketHeader
{
  uint16_t m_packetFormat; // 2023
  uint8_t m_gameYear; // Game year - last two digits e.g. 23
  uint8_t m_gameMajorVersion; // Game major version - "X.00"
  uint8_t m_gameMinorVersion; // Game minor version - "1.XX"
  uint8_t m_packetVersion; // Version of this packet type, all start from 1
  uint8_t m_packetId; // Identifier for the packet type, see below
  uint64_t m_sessionUID; // Unique identifier for the session
  float m_sessionTime; // Session timestamp
  uint32_t m_frameIdentifier; // Identifier for the frame the data was retrieved on
  uint32_t m_overallFrameIdentifier; // Overall identifier for the frame the data was retrieved
  // on, doesn't go back after flashbacks
  uint8_t m_playerCarIndex; // Index of player's car in the array
  uint8_t m_secondaryPlayerCarIndex; // Index of secondary player's car in the array (splitscreen)
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

};

#endif
