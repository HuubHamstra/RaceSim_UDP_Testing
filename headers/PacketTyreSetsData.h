#ifndef PACKETTYRESETSDATA_H
#define PACKETTYRESETSDATA_H

#include <cstdint>
#include <iostream>
#include "PacketHeader.h"
#include "TyreSetData.h"

struct PacketTyreSetsData
{
  PacketHeader m_header; // Header

  uint8_t m_carIdx; // Index of the car this data relates to

  TyreSetData m_tyreSetData[20]; // 13 (dry) + 7 (wet)

  uint8_t m_fittedIdx; // Index into array of fitted tyre

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
      memcpy(&this->m_carIdx, &buffer[offset], sizeof(this->m_carIdx));
      this->m_carIdx = static_cast<uint8_t>(this->m_carIdx);
      offset += sizeof(m_carIdx);
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 20; i++)
      {
        memcpy(&this->m_tyreSetData[i], &buffer[offset], sizeof(this->m_tyreSetData[i]));
        offset = offset + sizeof(this->m_tyreSetData[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_fittedIdx, &buffer[offset], sizeof(this->m_fittedIdx));
      this->m_fittedIdx = static_cast<uint8_t>(this->m_fittedIdx);
      offset += sizeof(m_fittedIdx);
    }
    return offset;
  }

  void print()
  {
    std::cout << "PacketTyreSetsData:" << std::endl;
    std::cout << "  m_header: " << std::endl;
    this->m_header.print();
    std::cout << "  m_carIdx: " << this->m_carIdx << std::endl;
    std::cout << "  m_tyreSetData[20]: " << std::endl;
    for (int i = 0; i < 20; i++)
    {
      this->m_tyreSetData[i].print();
    }
    std::cout << "  m_fittedIdx: " << this->m_fittedIdx << std::endl;
  }
};

#endif
