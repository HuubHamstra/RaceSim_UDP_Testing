#ifndef CARSTATUSDATA_H
#define CARSTATUSDATA_H

#include <cstdint>
#include <iostream>

struct CarStatusData
{
  uint8_t m_tractionControl;        // Traction control - 0 = off, 1 = medium, 2 = full
  uint8_t m_antiLockBrakes;         // 0 (off) - 1 (on)
  uint8_t m_fuelMix;                // Fuel mix - 0 = lean, 1 = standard, 2 = rich, 3 = max
  uint8_t m_frontBrakeBias;         // Front brake bias (percentage)
  uint8_t m_pitLimiterStatus;       // Pit limiter status - 0 = off, 1 = on
  float m_fuelInTank;               // Current fuel mass
  float m_fuelCapacity;             // Fuel capacity
  float m_fuelRemainingLaps;        // Fuel remaining in terms of laps (value on MFD)
  uint16_t m_maxRPM;                // Cars max RPM, point of rev limiter
  uint16_t m_idleRPM;               // Cars idle RPM
  uint8_t m_maxGears;               // Maximum number of gears
  uint8_t m_drsAllowed;             // 0 = not allowed, 1 = allowed
  uint16_t m_drsActivationDistance; // 0 = DRS not available, non-zero - DRS will be available
                                    // in [X] metres
  uint8_t m_actualTyreCompound;     // F1 Modern - 16 = C5, 17 = C4, 18 = C3, 19 = C2, 20 = C1
                                    // 21 = C0, 7 = inter, 8 = wet
                                    // F1 Classic - 9 = dry, 10 = wet
                                    // F2 – 11 = super soft, 12 = soft, 13 = medium, 14 = hard
                                    // 15 = wet
  uint8_t m_visualTyreCompound;     // F1 visual (can be different from actual compound)
                                    // 16 = soft, 17 = medium, 18 = hard, 7 = inter, 8 = wet
                                    // F1 Classic – same as above
                                    // F2 ‘19, 15 = wet, 19 – super soft, 20 = soft
                                    // 21 = medium , 22 = hard
  uint8_t m_tyresAgeLaps;           // Age in laps of the current set of tyres
  int8_t m_vehicleFiaFlags;         // -1 = invalid/unknown, 0 = none, 1 = green
                                    // 2 = blue, 3 = yellow
  float m_enginePowerICE;           // Engine power output of ICE (W)
  float m_enginePowerMGUK;          // Engine power output of MGU-K (W)
  float m_ersStoreEnergy;           // ERS energy store in Joules
  uint8_t m_ersDeployMode;          // ERS deployment mode, 0 = none, 1 = medium
                                    // 2 = hotlap, 3 = overtake
  float m_ersHarvestedThisLapMGUK;  // ERS energy harvested this lap by MGU-K
  float m_ersHarvestedThisLapMGUH;  // ERS energy harvested this lap by MGU-H
  float m_ersDeployedThisLap;       // ERS energy deployed this lap
  uint8_t m_networkPaused;          // Whether the car is paused in a network game

  unsigned long get(char *buffer)
  {
    unsigned long offset = 0;
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_tractionControl, &buffer[offset], sizeof(this->m_tractionControl));
      this->m_tractionControl = static_cast<uint8_t>(this->m_tractionControl);
      offset += sizeof(m_tractionControl);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_antiLockBrakes, &buffer[offset], sizeof(this->m_antiLockBrakes));
      this->m_antiLockBrakes = static_cast<uint8_t>(this->m_antiLockBrakes);
      offset += sizeof(m_antiLockBrakes);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_fuelMix, &buffer[offset], sizeof(this->m_fuelMix));
      this->m_fuelMix = static_cast<uint8_t>(this->m_fuelMix);
      offset += sizeof(m_fuelMix);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_frontBrakeBias, &buffer[offset], sizeof(this->m_frontBrakeBias));
      this->m_frontBrakeBias = static_cast<uint8_t>(this->m_frontBrakeBias);
      offset += sizeof(m_frontBrakeBias);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_pitLimiterStatus, &buffer[offset], sizeof(this->m_pitLimiterStatus));
      this->m_pitLimiterStatus = static_cast<uint8_t>(this->m_pitLimiterStatus);
      offset += sizeof(m_pitLimiterStatus);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_fuelInTank, &buffer[offset], sizeof(this->m_fuelInTank));
      offset += sizeof(m_fuelInTank);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_fuelCapacity, &buffer[offset], sizeof(this->m_fuelCapacity));
      offset += sizeof(m_fuelCapacity);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_fuelRemainingLaps, &buffer[offset], sizeof(this->m_fuelRemainingLaps));
      offset += sizeof(m_fuelRemainingLaps);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_maxRPM, &buffer[offset], sizeof(this->m_maxRPM));
      this->m_maxRPM = static_cast<uint16_t>(this->m_maxRPM);
      offset += sizeof(m_maxRPM);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_idleRPM, &buffer[offset], sizeof(this->m_idleRPM));
      this->m_idleRPM = static_cast<uint16_t>(this->m_idleRPM);
      offset += sizeof(m_idleRPM);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_maxGears, &buffer[offset], sizeof(this->m_maxGears));
      this->m_maxGears = static_cast<uint8_t>(this->m_maxGears);
      offset += sizeof(m_maxGears);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_drsAllowed, &buffer[offset], sizeof(this->m_drsAllowed));
      this->m_drsAllowed = static_cast<uint8_t>(this->m_drsAllowed);
      offset += sizeof(m_drsAllowed);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_drsActivationDistance, &buffer[offset], sizeof(this->m_drsActivationDistance));
      this->m_drsActivationDistance = static_cast<uint16_t>(this->m_drsActivationDistance);
      offset += sizeof(m_drsActivationDistance);
    }
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
      memcpy(&this->m_tyresAgeLaps, &buffer[offset], sizeof(this->m_tyresAgeLaps));
      this->m_tyresAgeLaps = static_cast<uint8_t>(this->m_tyresAgeLaps);
      offset += sizeof(m_tyresAgeLaps);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_vehicleFiaFlags, &buffer[offset], sizeof(this->m_vehicleFiaFlags));
      this->m_vehicleFiaFlags = static_cast<int8_t>(this->m_vehicleFiaFlags);
      offset += sizeof(m_vehicleFiaFlags);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_enginePowerICE, &buffer[offset], sizeof(this->m_enginePowerICE));
      offset += sizeof(m_enginePowerICE);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_enginePowerMGUK, &buffer[offset], sizeof(this->m_enginePowerMGUK));
      offset += sizeof(m_enginePowerMGUK);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_ersStoreEnergy, &buffer[offset], sizeof(this->m_ersStoreEnergy));
      offset += sizeof(m_ersStoreEnergy);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_ersDeployMode, &buffer[offset], sizeof(this->m_ersDeployMode));
      this->m_ersDeployMode = static_cast<uint8_t>(this->m_ersDeployMode);
      offset += sizeof(m_ersDeployMode);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_ersHarvestedThisLapMGUK, &buffer[offset], sizeof(this->m_ersHarvestedThisLapMGUK));
      offset += sizeof(m_ersHarvestedThisLapMGUK);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_ersHarvestedThisLapMGUH, &buffer[offset], sizeof(this->m_ersHarvestedThisLapMGUH));
      offset += sizeof(m_ersHarvestedThisLapMGUH);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_ersDeployedThisLap, &buffer[offset], sizeof(this->m_ersDeployedThisLap));
      offset += sizeof(m_ersDeployedThisLap);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_networkPaused, &buffer[offset], sizeof(this->m_networkPaused));
      this->m_networkPaused = static_cast<uint8_t>(this->m_networkPaused);
      offset += sizeof(m_networkPaused);
    }
    return offset;
  }

  void print()
  {
    std::cout << "CarStatusData:" << std::endl;
    std::cout << "  m_tractionControl: " << this->m_tractionControl << std::endl;
    std::cout << "  m_antiLockBrakes: " << this->m_antiLockBrakes << std::endl;
    std::cout << "  m_fuelMix: " << this->m_fuelMix << std::endl;
    std::cout << "  m_frontBrakeBias: " << this->m_frontBrakeBias << std::endl;
    std::cout << "  m_pitLimiterStatus: " << this->m_pitLimiterStatus << std::endl;
    std::cout << "  m_fuelInTank: " << this->m_fuelInTank << std::endl;
    std::cout << "  m_fuelCapacity: " << this->m_fuelCapacity << std::endl;
    std::cout << "  m_fuelRemainingLaps: " << this->m_fuelRemainingLaps << std::endl;
    std::cout << "  m_maxRPM: " << this->m_maxRPM << std::endl;
    std::cout << "  m_idleRPM: " << this->m_idleRPM << std::endl;
    std::cout << "  m_maxGears: " << this->m_maxGears << std::endl;
    std::cout << "  m_drsAllowed: " << this->m_drsAllowed << std::endl;
    std::cout << "  m_drsActivationDistance: " << this->m_drsActivationDistance << std::endl;
    std::cout << "  m_actualTyreCompound: " << this->m_actualTyreCompound << std::endl;
    std::cout << "  m_visualTyreCompound: " << this->m_visualTyreCompound << std::endl;
    std::cout << "  m_tyresAgeLaps: " << this->m_tyresAgeLaps << std::endl;
    std::cout << "  m_vehicleFiaFlags: " << this->m_vehicleFiaFlags << std::endl;
    std::cout << "  m_enginePowerICE: " << this->m_enginePowerICE << std::endl;
    std::cout << "  m_enginePowerMGUK: " << this->m_enginePowerMGUK << std::endl;
    std::cout << "  m_ersStoreEnergy: " << this->m_ersStoreEnergy << std::endl;
    std::cout << "  m_ersDeployMode: " << this->m_ersDeployMode << std::endl;
    std::cout << "  m_ersHarvestedThisLapMGUK: " << this->m_ersHarvestedThisLapMGUK << std::endl;
    std::cout << "  m_ersHarvestedThisLapMGUH: " << this->m_ersHarvestedThisLapMGUH << std::endl;
    std::cout << "  m_ersDeployedThisLap: " << this->m_ersDeployedThisLap << std::endl;
    std::cout << "  m_networkPaused: " << this->m_networkPaused << std::endl;
  }
};

#endif
