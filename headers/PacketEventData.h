#ifndef PACKETEVENTDATA_H
#define PACKETEVENTDATA_H

#include <cstdint>
#include <iostream>
#include "PacketHeader.h"
#include "EventDataDetails.h"

struct PacketEventData
{
  PacketHeader m_header; // Header

  uint8_t m_eventStringCode[4];    // Event string code, see below
  EventDataDetails m_eventDetails; // Event details - should be interpreted differently
                                   // for each type

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
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_eventStringCode[i], &buffer[offset], sizeof(this->m_eventStringCode[i]));
        offset = offset + sizeof(this->m_eventStringCode[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_eventDetails, &buffer[offset], sizeof(this->m_eventDetails));
      offset += sizeof(m_eventDetails);
    }
    return offset;
  }

  void print()
  {
    std::cout << "PacketEventData:" << std::endl;
    std::cout << "  m_header: " << std::endl;
    this->m_header.print();
    std::cout << "  m_eventStringCode[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_eventStringCode[" << i << "]: " << this->m_eventStringCode[i] << std::endl;
    }
    std::cout << "  m_eventDetails: " << this->m_eventDetails << std::endl;
  }
};

#endif
