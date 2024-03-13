#ifndef PACKETCARSETUPDATA_H
#define PACKETCARSETUPDATA_H

#include <cstdint>
#include <iostream>
#include "PacketHeader.h"
#include "CarSetupData.h"

struct PacketCarSetupData
{
  PacketHeader m_header; // Header

  CarSetupData m_carSetups[22];

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
        memcpy(&this->m_carSetups[i], &buffer[offset], sizeof(this->m_carSetups[i]));
        offset = offset + sizeof(this->m_carSetups[i]);
      }
    }
    return offset;
  }

  void print()
  {
    std::cout << "PacketCarSetupData:" << std::endl;
    std::cout << "  m_header: " << std::endl;
    this->m_header.print();
    std::cout << "  m_carSetups[22]: " << std::endl;
    for (int i = 0; i < 22; i++)
    {
      this->m_carSetups[i].print();
    }
  }
};

#endif
