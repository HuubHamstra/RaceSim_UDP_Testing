#ifndef PACKETCARTELEMETRYDATA_H
#define PACKETCARTELEMETRYDATA_H

#include <cstdint>
#include <iostream>
#include "PacketHeader.h"
#include "CarTelemetryData.h"

struct PacketCarTelemetryData
{
  PacketHeader m_header; // Header

  CarTelemetryData m_carTelemetryData[22];

  uint8_t m_mfdPanelIndex;                // Index of MFD panel open - 255 = MFD closed
                                          // Single player, race – 0 = Car setup, 1 = Pits
                                          // 2 = Damage, 3 = Engine, 4 = Temperatures
                                          // May vary depending on game mode
  uint8_t m_mfdPanelIndexSecondaryPlayer; // See above
  int8_t m_suggestedGear;                 // Suggested gear for the player (1-8)
                                          // 0 if no gear suggested

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
        memcpy(&this->m_carTelemetryData[i], &buffer[offset], sizeof(this->m_carTelemetryData[i]));
        offset = offset + sizeof(this->m_carTelemetryData[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_mfdPanelIndex, &buffer[offset], sizeof(this->m_mfdPanelIndex));
      this->m_mfdPanelIndex = static_cast<uint8_t>(this->m_mfdPanelIndex);
      offset += sizeof(m_mfdPanelIndex);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_mfdPanelIndexSecondaryPlayer, &buffer[offset], sizeof(this->m_mfdPanelIndexSecondaryPlayer));
      this->m_mfdPanelIndexSecondaryPlayer = static_cast<uint8_t>(this->m_mfdPanelIndexSecondaryPlayer);
      offset += sizeof(m_mfdPanelIndexSecondaryPlayer);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_suggestedGear, &buffer[offset], sizeof(this->m_suggestedGear));
      this->m_suggestedGear = static_cast<int8_t>(this->m_suggestedGear);
      offset += sizeof(m_suggestedGear);
    }
    return offset;
  }

  void print()
  {
    std::cout << "PacketCarTelemetryData:" << std::endl;
    std::cout << "  m_header: " << std::endl;
    this->m_header.print();
    std::cout << "  m_carTelemetryData[22]: " << std::endl;
    for (int i = 0; i < 22; i++)
    {
      this->m_carTelemetryData[i].print();
    }
    std::cout << "  m_mfdPanelIndex: " << this->m_mfdPanelIndex << std::endl;
    std::cout << "  m_mfdPanelIndexSecondaryPlayer: " << this->m_mfdPanelIndexSecondaryPlayer << std::endl;
    std::cout << "  m_suggestedGear: " << this->m_suggestedGear << std::endl;
  }
};

#endif
