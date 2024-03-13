#ifndef LAPHISTORYDATA_H
#define LAPHISTORYDATA_H

#include <cstdint>
#include <iostream>

struct LapHistoryData
{
  uint32_t m_lapTimeInMS;       // Lap time in milliseconds
  uint16_t m_sector1TimeInMS;   // Sector 1 time in milliseconds
  uint8_t m_sector1TimeMinutes; // Sector 1 whole minute part
  uint16_t m_sector2TimeInMS;   // Sector 2 time in milliseconds
  uint8_t m_sector1TimeMinutes; // Sector 2 whole minute part
  uint16_t m_sector3TimeInMS;   // Sector 3 time in milliseconds
  uint8_t m_sector3TimeMinutes; // Sector 3 whole minute part
  uint8_t m_lapValidBitFlags;   // 0x01 bit set-lap valid, 0x02 bit set-sector 1 valid
                                // 0x04 bit set-sector 2 valid, 0x08 bit set-sector 3 valid

  unsigned long get(char *buffer)
  {
    unsigned long offset = 0;
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_lapTimeInMS, &buffer[offset], sizeof(this->m_lapTimeInMS));
      this->m_lapTimeInMS = static_cast<uint32_t>(this->m_lapTimeInMS);
      offset += sizeof(m_lapTimeInMS);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_sector1TimeInMS, &buffer[offset], sizeof(this->m_sector1TimeInMS));
      this->m_sector1TimeInMS = static_cast<uint16_t>(this->m_sector1TimeInMS);
      offset += sizeof(m_sector1TimeInMS);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_sector1TimeMinutes, &buffer[offset], sizeof(this->m_sector1TimeMinutes));
      this->m_sector1TimeMinutes = static_cast<uint8_t>(this->m_sector1TimeMinutes);
      offset += sizeof(m_sector1TimeMinutes);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_sector2TimeInMS, &buffer[offset], sizeof(this->m_sector2TimeInMS));
      this->m_sector2TimeInMS = static_cast<uint16_t>(this->m_sector2TimeInMS);
      offset += sizeof(m_sector2TimeInMS);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_sector1TimeMinutes, &buffer[offset], sizeof(this->m_sector1TimeMinutes));
      this->m_sector1TimeMinutes = static_cast<uint8_t>(this->m_sector1TimeMinutes);
      offset += sizeof(m_sector1TimeMinutes);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_sector3TimeInMS, &buffer[offset], sizeof(this->m_sector3TimeInMS));
      this->m_sector3TimeInMS = static_cast<uint16_t>(this->m_sector3TimeInMS);
      offset += sizeof(m_sector3TimeInMS);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_sector3TimeMinutes, &buffer[offset], sizeof(this->m_sector3TimeMinutes));
      this->m_sector3TimeMinutes = static_cast<uint8_t>(this->m_sector3TimeMinutes);
      offset += sizeof(m_sector3TimeMinutes);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_lapValidBitFlags, &buffer[offset], sizeof(this->m_lapValidBitFlags));
      this->m_lapValidBitFlags = static_cast<uint8_t>(this->m_lapValidBitFlags);
      offset += sizeof(m_lapValidBitFlags);
    }
    return offset;
  }

  void print()
  {
    std::cout << "LapHistoryData:" << std::endl;
    std::cout << "  m_lapTimeInMS: " << this->m_lapTimeInMS << std::endl;
    std::cout << "  m_sector1TimeInMS: " << this->m_sector1TimeInMS << std::endl;
    std::cout << "  m_sector1TimeMinutes: " << this->m_sector1TimeMinutes << std::endl;
    std::cout << "  m_sector2TimeInMS: " << this->m_sector2TimeInMS << std::endl;
    std::cout << "  m_sector1TimeMinutes: " << this->m_sector1TimeMinutes << std::endl;
    std::cout << "  m_sector3TimeInMS: " << this->m_sector3TimeInMS << std::endl;
    std::cout << "  m_sector3TimeMinutes: " << this->m_sector3TimeMinutes << std::endl;
    std::cout << "  m_lapValidBitFlags: " << this->m_lapValidBitFlags << std::endl;
  }
};

#endif
