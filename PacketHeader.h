#ifndef PACKETHEADER_H
#define PACKETHEADER_H

#include <cstdint> // Inclusie van cstdint voor het definiëren van uint16_t, uint8_t, uint32_t, uint64_t
#include <iostream>

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

  unsigned long get(const char* buffer) {
    unsigned long offset = 0;
    
    // Gebruik reinterpret_cast om gegevens uit de buffer te halen en in de struct te plaatsen
    this->m_packetFormat = *reinterpret_cast<const uint16_t*>(&buffer[offset]);
    offset += sizeof(this->m_packetFormat);
    
    this->m_gameYear = *reinterpret_cast<const uint8_t*>(&buffer[offset]);
    offset += sizeof(this->m_gameYear);
    
    this->m_gameMajorVersion = *reinterpret_cast<const uint8_t*>(&buffer[offset]);
    offset += sizeof(this->m_gameMajorVersion);
    
    this->m_gameMinorVersion = *reinterpret_cast<const uint8_t*>(&buffer[offset]);
    offset += sizeof(this->m_gameMinorVersion);
    
    this->m_packetVersion = *reinterpret_cast<const uint8_t*>(&buffer[offset]);
    offset += sizeof(this->m_packetVersion);
    
    this->m_packetId = *reinterpret_cast<const uint8_t*>(&buffer[offset]);
    offset += sizeof(this->m_packetId);
    
    this->m_sessionUID = *reinterpret_cast<const uint64_t*>(&buffer[offset]);
    offset += sizeof(this->m_sessionUID);
    
    this->m_sessionTime = *reinterpret_cast<const float*>(&buffer[offset]);
    offset += sizeof(this->m_sessionTime);
    
    this->m_frameIdentifier = *reinterpret_cast<const uint32_t*>(&buffer[offset]);
    offset += sizeof(this->m_frameIdentifier);
    
    this->m_overallFrameIdentifier = *reinterpret_cast<const uint32_t*>(&buffer[offset]);
    offset += sizeof(this->m_overallFrameIdentifier);
    
    this->m_playerCarIndex = *reinterpret_cast<const uint8_t*>(&buffer[offset]);
    offset += sizeof(this->m_playerCarIndex);
    
    this->m_secondaryPlayerCarIndex = *reinterpret_cast<const uint8_t*>(&buffer[offset]);
    offset += sizeof(this->m_secondaryPlayerCarIndex);

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
