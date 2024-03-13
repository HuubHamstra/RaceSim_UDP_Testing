#ifndef PARTICIPANTDATA_H
#define PARTICIPANTDATA_H

#include <cstdint>
#include <iostream>

struct ParticipantData
{
  uint8_t m_aiControlled; // Whether the vehicle is AI (1) or Human (0) controlled
  uint8_t m_driverId;     // Driver id - see appendix, 255 if network human
  uint8_t m_networkId;    // Network id – unique identifier for network players
  uint8_t m_teamId;       // Team id - see appendix
  uint8_t m_myTeam;       // My team flag – 1 = My Team, 0 = otherwise
  uint8_t m_raceNumber;   // Race number of the car
  uint8_t m_nationality;  // Nationality of the driver
  char m_name[48];        // Name of participant in UTF-8 format – null terminated
                   // Will be truncated with … (U+2026) if too long
  uint8_t m_yourTelemetry;   // The player's UDP setting, 0 = restricted, 1 = public
  uint8_t m_showOnlineNames; // The player's show online names setting, 0 = off, 1 = on
  uint8_t m_platform;        // 1 = Steam, 3 = PlayStation, 4 = Xbox, 6 = Origin, 255 = unknown

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
      memcpy(&this->m_driverId, &buffer[offset], sizeof(this->m_driverId));
      this->m_driverId = static_cast<uint8_t>(this->m_driverId);
      offset += sizeof(m_driverId);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_networkId, &buffer[offset], sizeof(this->m_networkId));
      this->m_networkId = static_cast<uint8_t>(this->m_networkId);
      offset += sizeof(m_networkId);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_teamId, &buffer[offset], sizeof(this->m_teamId));
      this->m_teamId = static_cast<uint8_t>(this->m_teamId);
      offset += sizeof(m_teamId);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_myTeam, &buffer[offset], sizeof(this->m_myTeam));
      this->m_myTeam = static_cast<uint8_t>(this->m_myTeam);
      offset += sizeof(m_myTeam);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_raceNumber, &buffer[offset], sizeof(this->m_raceNumber));
      this->m_raceNumber = static_cast<uint8_t>(this->m_raceNumber);
      offset += sizeof(m_raceNumber);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_nationality, &buffer[offset], sizeof(this->m_nationality));
      this->m_nationality = static_cast<uint8_t>(this->m_nationality);
      offset += sizeof(m_nationality);
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
      memcpy(&this->m_yourTelemetry, &buffer[offset], sizeof(this->m_yourTelemetry));
      this->m_yourTelemetry = static_cast<uint8_t>(this->m_yourTelemetry);
      offset += sizeof(m_yourTelemetry);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_showOnlineNames, &buffer[offset], sizeof(this->m_showOnlineNames));
      this->m_showOnlineNames = static_cast<uint8_t>(this->m_showOnlineNames);
      offset += sizeof(m_showOnlineNames);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_platform, &buffer[offset], sizeof(this->m_platform));
      this->m_platform = static_cast<uint8_t>(this->m_platform);
      offset += sizeof(m_platform);
    }
    return offset;
  }

  void print()
  {
    std::cout << "ParticipantData:" << std::endl;
    std::cout << "  m_aiControlled: " << this->m_aiControlled << std::endl;
    std::cout << "  m_driverId: " << this->m_driverId << std::endl;
    std::cout << "  m_networkId: " << this->m_networkId << std::endl;
    std::cout << "  m_teamId: " << this->m_teamId << std::endl;
    std::cout << "  m_myTeam: " << this->m_myTeam << std::endl;
    std::cout << "  m_raceNumber: " << this->m_raceNumber << std::endl;
    std::cout << "  m_nationality: " << this->m_nationality << std::endl;
    std::cout << "  m_name[48]: " << std::endl;
    for (int i = 0; i < 48; i++)
    {
      std::cout << "  m_name[" << i << "]: " << this->m_name[i] << std::endl;
    }
    std::cout << "  m_yourTelemetry: " << this->m_yourTelemetry << std::endl;
    std::cout << "  m_showOnlineNames: " << this->m_showOnlineNames << std::endl;
    std::cout << "  m_platform: " << this->m_platform << std::endl;
  }
};

#endif
