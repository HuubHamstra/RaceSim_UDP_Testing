#ifndef TYRESETDATA_H
#define TYRESETDATA_H

#include <cstdint>
#include <iostream>

struct TyreSetData
{
  uint8_t m_actualTyreCompound; // Actual tyre compound used
  uint8_t m_visualTyreCompound; // Visual tyre compound used
  uint8_t m_wear;               // Tyre wear (percentage)
  uint8_t m_available;          // Whether this set is currently available
  uint8_t m_recommendedSession; // Recommended session for tyre set
  uint8_t m_lifeSpan;           // Laps left in this tyre set
  uint8_t m_usableLife;         // Max number of laps recommended for this compound
  int16_t m_lapDeltaTime;       // Lap delta time in milliseconds compared to fitted set
  uint8_t m_fitted;             // Whether the set is fitted or not

  unsigned long get(char *buffer)
  {
    unsigned long offset = 0;
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_actualTyreCompound, &buffer[offset], sizeof(this->m_actualTyreCompound));
      this->m_actualTyreCompound = static_cast<uint8_t>(this->m_actualTyreCompound);
      offset += sizeof(m_actualTyreCompound);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_visualTyreCompound, &buffer[offset], sizeof(this->m_visualTyreCompound));
      this->m_visualTyreCompound = static_cast<uint8_t>(this->m_visualTyreCompound);
      offset += sizeof(m_visualTyreCompound);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_wear, &buffer[offset], sizeof(this->m_wear));
      this->m_wear = static_cast<uint8_t>(this->m_wear);
      offset += sizeof(m_wear);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_available, &buffer[offset], sizeof(this->m_available));
      this->m_available = static_cast<uint8_t>(this->m_available);
      offset += sizeof(m_available);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_recommendedSession, &buffer[offset], sizeof(this->m_recommendedSession));
      this->m_recommendedSession = static_cast<uint8_t>(this->m_recommendedSession);
      offset += sizeof(m_recommendedSession);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_lifeSpan, &buffer[offset], sizeof(this->m_lifeSpan));
      this->m_lifeSpan = static_cast<uint8_t>(this->m_lifeSpan);
      offset += sizeof(m_lifeSpan);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_usableLife, &buffer[offset], sizeof(this->m_usableLife));
      this->m_usableLife = static_cast<uint8_t>(this->m_usableLife);
      offset += sizeof(m_usableLife);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_lapDeltaTime, &buffer[offset], sizeof(this->m_lapDeltaTime));
      this->m_lapDeltaTime = static_cast<int16_t>(this->m_lapDeltaTime);
      offset += sizeof(m_lapDeltaTime);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_fitted, &buffer[offset], sizeof(this->m_fitted));
      this->m_fitted = static_cast<uint8_t>(this->m_fitted);
      offset += sizeof(m_fitted);
    }
    return offset;
  }

  void print()
  {
    std::cout << "TyreSetData:" << std::endl;
    std::cout << "  m_actualTyreCompound: " << this->m_actualTyreCompound << std::endl;
    std::cout << "  m_visualTyreCompound: " << this->m_visualTyreCompound << std::endl;
    std::cout << "  m_wear: " << this->m_wear << std::endl;
    std::cout << "  m_available: " << this->m_available << std::endl;
    std::cout << "  m_recommendedSession: " << this->m_recommendedSession << std::endl;
    std::cout << "  m_lifeSpan: " << this->m_lifeSpan << std::endl;
    std::cout << "  m_usableLife: " << this->m_usableLife << std::endl;
    std::cout << "  m_lapDeltaTime: " << this->m_lapDeltaTime << std::endl;
    std::cout << "  m_fitted: " << this->m_fitted << std::endl;
  }
};

#endif
