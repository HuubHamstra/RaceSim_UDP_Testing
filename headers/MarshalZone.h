#ifndef MARSHALZONE_H
#define MARSHALZONE_H

#include <cstdint>
#include <iostream>

struct MarshalZone
{
  float m_zoneStart; // Fraction (0..1) of way through the lap the marshal zone starts
  int8_t m_zoneFlag; // -1 = invalid/unknown, 0 = none, 1 = green, 2 = blue, 3 = yellow

  unsigned long get(char *buffer)
  {
    unsigned long offset = 0;
    memcpy(&this->m_zoneStart, &buffer[offset], sizeof(this->m_zoneStart));
    offset += sizeof(this->m_zoneStart);
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_zoneFlag, &buffer[offset], sizeof(this->m_zoneFlag));
      this->m_zoneFlag = static_cast<int8_t>(this->m_zoneFlag);
      offset += sizeof(this->m_zoneFlag);
    }
    return offset;
  }

  void print()
  {
    std::cout << "MarshalZone:" << std::endl;
    std::cout << "  m_zoneStart: " << this->m_zoneStart << std::endl;
    std::cout << "  m_zoneFlag: " << this->m_zoneFlag << std::endl;
  }
};

#endif