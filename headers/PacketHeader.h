#ifndef PACKETHEADER_H
#define PACKETHEADER_H

#include <cstdint> // Inclusie van cstdint voor het definiëren van uint16_t, uint8_t, uint32_t, uint64_t
#include <iostream>

struct PacketHeader
{
  uint16_t m_packetFormat;           // 2023
  uint8_t m_gameYear;                // Game year - last two digits e.g. 23
  uint8_t m_gameMajorVersion;        // Game major version - "X.00"
  uint8_t m_gameMinorVersion;        // Game minor version - "1.XX"
  uint8_t m_packetVersion;           // Version of this packet type, all start from 1
  uint8_t m_packetId;                // Identifier for the packet type, see below
  uint64_t m_sessionUID;             // Unique identifier for the session
  float m_sessionTime;               // Session timestamp
  uint32_t m_frameIdentifier;        // Identifier for the frame the data was retrieved on
  uint32_t m_overallFrameIdentifier; // Overall identifier for the frame the data was retrieved
  // on, doesn't go back after flashbacks
  uint8_t m_playerCarIndex;          // Index of player's car in the array
  uint8_t m_secondaryPlayerCarIndex; // Index of secondary player's car in the array (splitscreen)
  // 255 if no second player

  unsigned long get(char *buffer)
  {
    unsigned long offset = 0;
    memcpy(&this->m_packetFormat, &buffer[offset], sizeof(this->m_packetFormat));
    offset += sizeof(this->m_packetFormat);
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_gameMajorVersion, &buffer[offset], sizeof(this->m_gameMajorVersion));
      offset += sizeof(this->m_gameMajorVersion);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_gameMinorVersion, &buffer[offset], sizeof(this->m_gameMinorVersion));
      offset += sizeof(this->m_gameMinorVersion);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_packetVersion, &buffer[offset], sizeof(this->m_packetVersion));
      offset += sizeof(this->m_packetVersion);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_packetId, &buffer[offset], sizeof(this->m_packetId));
      this->m_packetId = static_cast<uint8_t>(this->m_packetId);
      offset += sizeof(this->m_packetId);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_sessionUID, &buffer[offset], sizeof(this->m_sessionUID));
      offset += sizeof(this->m_sessionUID);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_sessionTime, &buffer[offset], sizeof(this->m_sessionTime));
      offset += sizeof(this->m_sessionTime);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_frameIdentifier, &buffer[offset], sizeof(this->m_frameIdentifier));
      offset += sizeof(this->m_frameIdentifier);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_overallFrameIdentifier, &buffer[offset], sizeof(this->m_overallFrameIdentifier));
      offset += sizeof(this->m_overallFrameIdentifier);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_playerCarIndex, &buffer[offset], sizeof(this->m_playerCarIndex));
      offset += sizeof(this->m_playerCarIndex);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_secondaryPlayerCarIndex, &buffer[offset], sizeof(this->m_secondaryPlayerCarIndex));
      this->m_secondaryPlayerCarIndex = static_cast<uint8_t>(this->m_secondaryPlayerCarIndex);
      offset += sizeof(this->m_secondaryPlayerCarIndex);
    }

    return offset;
  }

  void print()
  {
    std::cout << " "
              << "PacketHeader {" << std::endl;
    std::cout << "   "
              << "m_packetFormat: " << this->m_packetFormat << std::endl;
    std::cout << "   "
              << "m_gameMajorVersion: " << this->m_gameMajorVersion << std::endl;
    std::cout << "   "
              << "m_gameMinorVersion: " << this->m_gameMinorVersion << std::endl;
    std::cout << "   "
              << "m_packetVersion: " << this->m_packetVersion << std::endl;
    std::cout << "   "
              << "m_packetId: " << static_cast<int>(this->m_packetId) << std::endl; // Cast naar int voor weergave
    std::cout << "   "
              << "m_sessionUID: " << this->m_sessionUID << std::endl;
    std::cout << "   "
              << "m_sessionTime: " << this->m_sessionTime << std::endl;
    std::cout << "   "
              << "m_frameIdentifier: " << this->m_frameIdentifier << std::endl;
    std::cout << "   "
              << "m_playerCarIndex: " << this->m_playerCarIndex << std::endl;
    std::cout << "   "
              << "m_secondaryPlayerCarIndex: " << this->m_secondaryPlayerCarIndex << std::endl;
    std::cout << " "
              << "}" << std::endl;
  }
};

#endif
