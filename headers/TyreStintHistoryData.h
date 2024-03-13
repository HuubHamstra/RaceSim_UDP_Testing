#ifndef TYRESTINTHISTORYDATA_H
#define TYRESTINTHISTORYDATA_H

#include <cstdint>
#include <iostream>

struct TyreStintHistoryData
{
  uint8_t m_endLap;             // Lap the tyre usage ends on (255 of current tyre)
  uint8_t m_tyreActualCompound; // Actual tyres used by this driver
  uint8_t m_tyreVisualCompound; // Visual tyres used by this driver

  unsigned long get(char *buffer)
  {
    unsigned long offset = 0;
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_endLap, &buffer[offset], sizeof(this->m_endLap));
      this->m_endLap = static_cast<uint8_t>(this->m_endLap);
      offset += sizeof(m_endLap);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_tyreActualCompound, &buffer[offset], sizeof(this->m_tyreActualCompound));
      this->m_tyreActualCompound = static_cast<uint8_t>(this->m_tyreActualCompound);
      offset += sizeof(m_tyreActualCompound);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_tyreVisualCompound, &buffer[offset], sizeof(this->m_tyreVisualCompound));
      this->m_tyreVisualCompound = static_cast<uint8_t>(this->m_tyreVisualCompound);
      offset += sizeof(m_tyreVisualCompound);
    }
    return offset;
  }

  void print()
  {
    std::cout << "TyreStintHistoryData:" << std::endl;
    std::cout << "  m_endLap: " << this->m_endLap << std::endl;
    std::cout << "  m_tyreActualCompound: " << this->m_tyreActualCompound << std::endl;
    std::cout << "  m_tyreVisualCompound: " << this->m_tyreVisualCompound << std::endl;
  }
};

#endif
