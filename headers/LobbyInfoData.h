#ifndef LOBBYINFODATA_H
#define LOBBYINFODATA_H

#include <cstdint>
#include <iostream>

struct LobbyInfoData
{
  uint8_t m_aiControlled; // Whether the vehicle is AI (1) or Human (0) controlled
  uint8_t m_teamId;       // Team id - see appendix (255 if no team currently selected)
  uint8_t m_nationality;  // Nationality of the driver
  uint8_t m_platform;     // 1 = Steam, 3 = PlayStation, 4 = Xbox, 6 = Origin, 255 = unknown
  char m_name[48];        // Name of participant in UTF-8 format – null terminated
                          // Will be truncated with ... (U+2026) if too long
  uint8_t m_carNumber;    // Car number of the player
  uint8_t m_readyStatus;  // 0 = not ready, 1 = ready, 2 = spectating

  unsigned long get(char *buffer)
  {
    unsigned long offset = 0;
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_aiControlled, &buffer[offset], sizeof(this->m_aiControlled));
      this->m_aiControlled = static_cast<uint8_t>(this->m_aiControlled);
      offset += sizeof(m_aiControlled);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_teamId, &buffer[offset], sizeof(this->m_teamId));
      this->m_teamId = static_cast<uint8_t>(this->m_teamId);
      offset += sizeof(m_teamId);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_nationality, &buffer[offset], sizeof(this->m_nationality));
      this->m_nationality = static_cast<uint8_t>(this->m_nationality);
      offset += sizeof(m_nationality);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_platform, &buffer[offset], sizeof(this->m_platform));
      this->m_platform = static_cast<uint8_t>(this->m_platform);
      offset += sizeof(m_platform);
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 48; i++)
      {
        memcpy(&this->m_name[i], &buffer[offset], sizeof(this->m_name[i]));
        offset = offset + sizeof(this->m_name[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_carNumber, &buffer[offset], sizeof(this->m_carNumber));
      this->m_carNumber = static_cast<uint8_t>(this->m_carNumber);
      offset += sizeof(m_carNumber);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_readyStatus, &buffer[offset], sizeof(this->m_readyStatus));
      this->m_readyStatus = static_cast<uint8_t>(this->m_readyStatus);
      offset += sizeof(m_readyStatus);
    }
    return offset;
  }

  void print()
  {
    std::cout << "LobbyInfoData:" << std::endl;
    std::cout << "  m_aiControlled: " << this->m_aiControlled << std::endl;
    std::cout << "  m_teamId: " << this->m_teamId << std::endl;
    std::cout << "  m_nationality: " << this->m_nationality << std::endl;
    std::cout << "  m_platform: " << this->m_platform << std::endl;
    std::cout << "  m_name[48]: " << std::endl;
    for (int i = 0; i < 48; i++)
    {
      std::cout << "  m_name[" << i << "]: " << this->m_name[i] << std::endl;
    }
    std::cout << "  m_carNumber: " << this->m_carNumber << std::endl;
    std::cout << "  m_readyStatus: " << this->m_readyStatus << std::endl;
  }
};

#endif
