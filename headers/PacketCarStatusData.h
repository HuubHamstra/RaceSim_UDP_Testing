#ifndef PACKETCARSTATUSDATA_H
#define PACKETCARSTATUSDATA_H

#include <cstdint>
#include <iostream>
#include "PacketHeader.h"
#include "CarStatusData.h"

struct PacketCarStatusData
{
  PacketHeader m_header; // Header

  CarStatusData m_carStatusData[22];

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
        memcpy(&this->m_carStatusData[i], &buffer[offset], sizeof(this->m_carStatusData[i]));
        offset = offset + sizeof(this->m_carStatusData[i]);
      }
    }
    return offset;
  }

  void print()
  {
    std::cout << "PacketCarStatusData:" << std::endl;
    std::cout << "  m_header: " << std::endl;
    this->m_header.print();
    std::cout << "  m_carStatusData[22]: " << std::endl;
    for (int i = 0; i < 22; i++)
    {
      this->m_carStatusData[i].print();
    }
  }
};

#endif
