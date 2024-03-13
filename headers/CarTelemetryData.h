#ifndef CARTELEMETRYDATA_H
#define CARTELEMETRYDATA_H

#include <cstdint>
#include <iostream>

struct CarTelemetryData
{
  uint16_t m_speed;                     // Speed of car in kilometres per hour
  float m_throttle;                     // Amount of throttle applied (0.0 to 1.0)
  float m_steer;                        // Steering (-1.0 (full lock left) to 1.0 (full lock right))
  float m_brake;                        // Amount of brake applied (0.0 to 1.0)
  uint8_t m_clutch;                     // Amount of clutch applied (0 to 100)
  int8_t m_gear;                        // Gear selected (1-8, N=0, R=-1)
  uint16_t m_engineRPM;                 // Engine RPM
  uint8_t m_drs;                        // 0 = off, 1 = on
  uint8_t m_revLightsPercent;           // Rev lights indicator (percentage)
  uint16_t m_revLightsBitValue;         // Rev lights (bit 0 = leftmost LED, bit 14 = rightmost LED)
  uint16_t m_brakesTemperature[4];      // Brakes temperature (celsius)
  uint8_t m_tyresSurfaceTemperature[4]; // Tyres surface temperature (celsius)
  uint8_t m_tyresInnerTemperature[4];   // Tyres inner temperature (celsius)
  uint16_t m_engineTemperature;         // Engine temperature (celsius)
  float m_tyresPressure[4];             // Tyres pressure (PSI)
  uint8_t m_surfaceType[4];             // Driving surface, see appendices

  unsigned long get(char *buffer)
  {
    unsigned long offset = 0;
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_speed, &buffer[offset], sizeof(this->m_speed));
      this->m_speed = static_cast<uint16_t>(this->m_speed);
      offset += sizeof(m_speed);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_throttle, &buffer[offset], sizeof(this->m_throttle));
      offset += sizeof(m_throttle);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_steer, &buffer[offset], sizeof(this->m_steer));
      offset += sizeof(m_steer);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_brake, &buffer[offset], sizeof(this->m_brake));
      offset += sizeof(m_brake);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_clutch, &buffer[offset], sizeof(this->m_clutch));
      this->m_clutch = static_cast<uint8_t>(this->m_clutch);
      offset += sizeof(m_clutch);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_gear, &buffer[offset], sizeof(this->m_gear));
      this->m_gear = static_cast<int8_t>(this->m_gear);
      offset += sizeof(m_gear);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_engineRPM, &buffer[offset], sizeof(this->m_engineRPM));
      this->m_engineRPM = static_cast<uint16_t>(this->m_engineRPM);
      offset += sizeof(m_engineRPM);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_drs, &buffer[offset], sizeof(this->m_drs));
      this->m_drs = static_cast<uint8_t>(this->m_drs);
      offset += sizeof(m_drs);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_revLightsPercent, &buffer[offset], sizeof(this->m_revLightsPercent));
      this->m_revLightsPercent = static_cast<uint8_t>(this->m_revLightsPercent);
      offset += sizeof(m_revLightsPercent);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_revLightsBitValue, &buffer[offset], sizeof(this->m_revLightsBitValue));
      this->m_revLightsBitValue = static_cast<uint16_t>(this->m_revLightsBitValue);
      offset += sizeof(m_revLightsBitValue);
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_brakesTemperature[i], &buffer[offset], sizeof(this->m_brakesTemperature[i]));
        offset = offset + sizeof(this->m_brakesTemperature[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_tyresSurfaceTemperature[i], &buffer[offset], sizeof(this->m_tyresSurfaceTemperature[i]));
        offset = offset + sizeof(this->m_tyresSurfaceTemperature[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_tyresInnerTemperature[i], &buffer[offset], sizeof(this->m_tyresInnerTemperature[i]));
        offset = offset + sizeof(this->m_tyresInnerTemperature[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_engineTemperature, &buffer[offset], sizeof(this->m_engineTemperature));
      this->m_engineTemperature = static_cast<uint16_t>(this->m_engineTemperature);
      offset += sizeof(m_engineTemperature);
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_tyresPressure[i], &buffer[offset], sizeof(this->m_tyresPressure[i]));
        offset = offset + sizeof(this->m_tyresPressure[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_surfaceType[i], &buffer[offset], sizeof(this->m_surfaceType[i]));
        offset = offset + sizeof(this->m_surfaceType[i]);
      }
    }
    return offset;
  }

  void print()
  {
    std::cout << "CarTelemetryData:" << std::endl;
    std::cout << "  m_speed: " << this->m_speed << std::endl;
    std::cout << "  m_throttle: " << this->m_throttle << std::endl;
    std::cout << "  m_steer: " << this->m_steer << std::endl;
    std::cout << "  m_brake: " << this->m_brake << std::endl;
    std::cout << "  m_clutch: " << this->m_clutch << std::endl;
    std::cout << "  m_gear: " << this->m_gear << std::endl;
    std::cout << "  m_engineRPM: " << this->m_engineRPM << std::endl;
    std::cout << "  m_drs: " << this->m_drs << std::endl;
    std::cout << "  m_revLightsPercent: " << this->m_revLightsPercent << std::endl;
    std::cout << "  m_revLightsBitValue: " << this->m_revLightsBitValue << std::endl;
    std::cout << "  m_brakesTemperature[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_brakesTemperature[" << i << "]: " << this->m_brakesTemperature[i] << std::endl;
    }
    std::cout << "  m_tyresSurfaceTemperature[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_tyresSurfaceTemperature[" << i << "]: " << this->m_tyresSurfaceTemperature[i] << std::endl;
    }
    std::cout << "  m_tyresInnerTemperature[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_tyresInnerTemperature[" << i << "]: " << this->m_tyresInnerTemperature[i] << std::endl;
    }
    std::cout << "  m_engineTemperature: " << this->m_engineTemperature << std::endl;
    std::cout << "  m_tyresPressure[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_tyresPressure[" << i << "]: " << this->m_tyresPressure[i] << std::endl;
    }
    std::cout << "  m_surfaceType[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_surfaceType[" << i << "]: " << this->m_surfaceType[i] << std::endl;
    }
  }
};

#endif
