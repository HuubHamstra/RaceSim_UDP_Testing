#ifndef PACKETPARTICIPANTSDATA_H
#define PACKETPARTICIPANTSDATA_H

#include <cstdint>
#include <iostream>
#include "PacketHeader.h"
#include "ParticipantData.h"

struct PacketParticipantsData
{
  PacketHeader m_header; // Header

  uint8_t m_numActiveCars; // Number of active cars in the data – should match number of
                           // cars on HUD
  ParticipantData m_participants[22];

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
      memcpy(&this->m_numActiveCars, &buffer[offset], sizeof(this->m_numActiveCars));
      this->m_numActiveCars = static_cast<uint8_t>(this->m_numActiveCars);
      offset += sizeof(m_numActiveCars);
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 22; i++)
      {
        memcpy(&this->m_participants[i], &buffer[offset], sizeof(this->m_participants[i]));
        offset = offset + sizeof(this->m_participants[i]);
      }
    }
    return offset;
  }

  void print()
  {
    std::cout << "PacketParticipantsData:" << std::endl;
    std::cout << "  m_header: " << std::endl;
    this->m_header.print();
    std::cout << "  m_numActiveCars: " << this->m_numActiveCars << std::endl;
    std::cout << "  m_participants[22]: " << std::endl;
    for (int i = 0; i < 22; i++)
    {
      this->m_participants[i].print();
    }
  }
};

#endif
