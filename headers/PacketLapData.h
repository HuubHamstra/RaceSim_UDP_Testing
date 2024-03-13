#ifndef PACKETLAPDATA_H
#define PACKETLAPDATA_H

#include <cstdint>
#include <iostream>
#include "PacketHeader.h"
#include "LapData.h"

struct PacketLapData
{
  PacketHeader m_header; // Header

  LapData m_lapData[22]; // Lap data for all cars on track

  uint8_t m_timeTrialPBCarIdx;    // Index of Personal Best car in time trial (255 if invalid)
  uint8_t m_timeTrialRivalCarIdx; // Index of Rival car in time trial (255 if invalid)

  unsigned long get(char *buffer)
  {
    unsigned long offset = 0;
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_header, &buffer[offset], sizeof(this->m_header));
      offset += sizeof(m_header);
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 22; i++)
      {
        memcpy(&this->m_lapData[i], &buffer[offset], sizeof(this->m_lapData[i]));
        offset = offset + sizeof(this->m_lapData[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_timeTrialPBCarIdx, &buffer[offset], sizeof(this->m_timeTrialPBCarIdx));
      this->m_timeTrialPBCarIdx = static_cast<uint8_t>(this->m_timeTrialPBCarIdx);
      offset += sizeof(m_timeTrialPBCarIdx);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_timeTrialRivalCarIdx, &buffer[offset], sizeof(this->m_timeTrialRivalCarIdx));
      this->m_timeTrialRivalCarIdx = static_cast<uint8_t>(this->m_timeTrialRivalCarIdx);
      offset += sizeof(m_timeTrialRivalCarIdx);
    }
    return offset;
  }

  void print()
  {
    std::cout << "PacketLapData:" << std::endl;
    std::cout << "  m_header: " << std::endl;
    this->m_header.print();
    std::cout << "  m_lapData[22]: " << std::endl;
    for (int i = 0; i < 22; i++)
    {
      this->m_lapData[i].print();
    }
    std::cout << "  m_timeTrialPBCarIdx: " << this->m_timeTrialPBCarIdx << std::endl;
    std::cout << "  m_timeTrialRivalCarIdx: " << this->m_timeTrialRivalCarIdx << std::endl;
  }
};

#endif
