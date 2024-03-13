#ifndef PACKETFINALCLASSIFICATIONDATA_H
#define PACKETFINALCLASSIFICATIONDATA_H

#include <cstdint>
#include <iostream>
#include "PacketHeader.h"
#include "FinalClassificationData.h"

struct PacketFinalClassificationData
{
  PacketHeader m_header; // Header

  uint8_t m_numCars; // Number of cars in the final classification
  FinalClassificationData m_classificationData[22];

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
      memcpy(&this->m_numCars, &buffer[offset], sizeof(this->m_numCars));
      this->m_numCars = static_cast<uint8_t>(this->m_numCars);
      offset += sizeof(m_numCars);
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 22; i++)
      {
        memcpy(&this->m_classificationData[i], &buffer[offset], sizeof(this->m_classificationData[i]));
        offset = offset + sizeof(this->m_classificationData[i]);
      }
    }
    return offset;
  }

  void print()
  {
    std::cout << "PacketFinalClassificationData:" << std::endl;
    std::cout << "  m_header: " << std::endl;
    this->m_header.print();
    std::cout << "  m_numCars: " << this->m_numCars << std::endl;
    std::cout << "  m_classificationData[22]: " << std::endl;
    for (int i = 0; i < 22; i++)
    {
      this->m_classificationData[i].print();
    }
  }
};

#endif
