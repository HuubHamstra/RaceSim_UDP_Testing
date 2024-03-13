#ifndef CARSETUPDATA_H
#define CARSETUPDATA_H

#include <cstdint>
#include <iostream>

struct CarSetupData
{
  uint8_t m_frontWing;             // Front wing aero
  uint8_t m_rearWing;              // Rear wing aero
  uint8_t m_onThrottle;            // Differential adjustment on throttle (percentage)
  uint8_t m_offThrottle;           // Differential adjustment off throttle (percentage)
  float m_frontCamber;             // Front camber angle (suspension geometry)
  float m_rearCamber;              // Rear camber angle (suspension geometry)
  float m_frontToe;                // Front toe angle (suspension geometry)
  float m_rearToe;                 // Rear toe angle (suspension geometry)
  uint8_t m_frontSuspension;       // Front suspension
  uint8_t m_rearSuspension;        // Rear suspension
  uint8_t m_frontAntiRollBar;      // Front anti-roll bar
  uint8_t m_rearAntiRollBar;       // Front anti-roll bar
  uint8_t m_frontSuspensionHeight; // Front ride height
  uint8_t m_rearSuspensionHeight;  // Rear ride height
  uint8_t m_brakePressure;         // Brake pressure (percentage)
  uint8_t m_brakeBias;             // Brake bias (percentage)
  float m_rearLeftTyrePressure;    // Rear left tyre pressure (PSI)
  float m_rearRightTyrePressure;   // Rear right tyre pressure (PSI)
  float m_frontLeftTyrePressure;   // Front left tyre pressure (PSI)
  float m_frontRightTyrePressure;  // Front right tyre pressure (PSI)
  uint8_t m_ballast;               // Ballast
  float m_fuelLoad;                // Fuel load

  unsigned long get(char *buffer)
  {
    unsigned long offset = 0;
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_frontWing, &buffer[offset], sizeof(this->m_frontWing));
      this->m_frontWing = static_cast<uint8_t>(this->m_frontWing);
      offset += sizeof(m_frontWing);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_rearWing, &buffer[offset], sizeof(this->m_rearWing));
      this->m_rearWing = static_cast<uint8_t>(this->m_rearWing);
      offset += sizeof(m_rearWing);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_onThrottle, &buffer[offset], sizeof(this->m_onThrottle));
      this->m_onThrottle = static_cast<uint8_t>(this->m_onThrottle);
      offset += sizeof(m_onThrottle);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_offThrottle, &buffer[offset], sizeof(this->m_offThrottle));
      this->m_offThrottle = static_cast<uint8_t>(this->m_offThrottle);
      offset += sizeof(m_offThrottle);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_frontCamber, &buffer[offset], sizeof(this->m_frontCamber));
      offset += sizeof(m_frontCamber);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_rearCamber, &buffer[offset], sizeof(this->m_rearCamber));
      offset += sizeof(m_rearCamber);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_frontToe, &buffer[offset], sizeof(this->m_frontToe));
      offset += sizeof(m_frontToe);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_rearToe, &buffer[offset], sizeof(this->m_rearToe));
      offset += sizeof(m_rearToe);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_frontSuspension, &buffer[offset], sizeof(this->m_frontSuspension));
      this->m_frontSuspension = static_cast<uint8_t>(this->m_frontSuspension);
      offset += sizeof(m_frontSuspension);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_rearSuspension, &buffer[offset], sizeof(this->m_rearSuspension));
      this->m_rearSuspension = static_cast<uint8_t>(this->m_rearSuspension);
      offset += sizeof(m_rearSuspension);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_frontAntiRollBar, &buffer[offset], sizeof(this->m_frontAntiRollBar));
      this->m_frontAntiRollBar = static_cast<uint8_t>(this->m_frontAntiRollBar);
      offset += sizeof(m_frontAntiRollBar);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_rearAntiRollBar, &buffer[offset], sizeof(this->m_rearAntiRollBar));
      this->m_rearAntiRollBar = static_cast<uint8_t>(this->m_rearAntiRollBar);
      offset += sizeof(m_rearAntiRollBar);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_frontSuspensionHeight, &buffer[offset], sizeof(this->m_frontSuspensionHeight));
      this->m_frontSuspensionHeight = static_cast<uint8_t>(this->m_frontSuspensionHeight);
      offset += sizeof(m_frontSuspensionHeight);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_rearSuspensionHeight, &buffer[offset], sizeof(this->m_rearSuspensionHeight));
      this->m_rearSuspensionHeight = static_cast<uint8_t>(this->m_rearSuspensionHeight);
      offset += sizeof(m_rearSuspensionHeight);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_brakePressure, &buffer[offset], sizeof(this->m_brakePressure));
      this->m_brakePressure = static_cast<uint8_t>(this->m_brakePressure);
      offset += sizeof(m_brakePressure);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_brakeBias, &buffer[offset], sizeof(this->m_brakeBias));
      this->m_brakeBias = static_cast<uint8_t>(this->m_brakeBias);
      offset += sizeof(m_brakeBias);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_rearLeftTyrePressure, &buffer[offset], sizeof(this->m_rearLeftTyrePressure));
      offset += sizeof(m_rearLeftTyrePressure);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_rearRightTyrePressure, &buffer[offset], sizeof(this->m_rearRightTyrePressure));
      offset += sizeof(m_rearRightTyrePressure);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_frontLeftTyrePressure, &buffer[offset], sizeof(this->m_frontLeftTyrePressure));
      offset += sizeof(m_frontLeftTyrePressure);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_frontRightTyrePressure, &buffer[offset], sizeof(this->m_frontRightTyrePressure));
      offset += sizeof(m_frontRightTyrePressure);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_ballast, &buffer[offset], sizeof(this->m_ballast));
      this->m_ballast = static_cast<uint8_t>(this->m_ballast);
      offset += sizeof(m_ballast);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_fuelLoad, &buffer[offset], sizeof(this->m_fuelLoad));
      offset += sizeof(m_fuelLoad);
    }
    return offset;
  }

  void print()
  {
    std::cout << "CarSetupData:" << std::endl;
    std::cout << "  m_frontWing: " << this->m_frontWing << std::endl;
    std::cout << "  m_rearWing: " << this->m_rearWing << std::endl;
    std::cout << "  m_onThrottle: " << this->m_onThrottle << std::endl;
    std::cout << "  m_offThrottle: " << this->m_offThrottle << std::endl;
    std::cout << "  m_frontCamber: " << this->m_frontCamber << std::endl;
    std::cout << "  m_rearCamber: " << this->m_rearCamber << std::endl;
    std::cout << "  m_frontToe: " << this->m_frontToe << std::endl;
    std::cout << "  m_rearToe: " << this->m_rearToe << std::endl;
    std::cout << "  m_frontSuspension: " << this->m_frontSuspension << std::endl;
    std::cout << "  m_rearSuspension: " << this->m_rearSuspension << std::endl;
    std::cout << "  m_frontAntiRollBar: " << this->m_frontAntiRollBar << std::endl;
    std::cout << "  m_rearAntiRollBar: " << this->m_rearAntiRollBar << std::endl;
    std::cout << "  m_frontSuspensionHeight: " << this->m_frontSuspensionHeight << std::endl;
    std::cout << "  m_rearSuspensionHeight: " << this->m_rearSuspensionHeight << std::endl;
    std::cout << "  m_brakePressure: " << this->m_brakePressure << std::endl;
    std::cout << "  m_brakeBias: " << this->m_brakeBias << std::endl;
    std::cout << "  m_rearLeftTyrePressure: " << this->m_rearLeftTyrePressure << std::endl;
    std::cout << "  m_rearRightTyrePressure: " << this->m_rearRightTyrePressure << std::endl;
    std::cout << "  m_frontLeftTyrePressure: " << this->m_frontLeftTyrePressure << std::endl;
    std::cout << "  m_frontRightTyrePressure: " << this->m_frontRightTyrePressure << std::endl;
    std::cout << "  m_ballast: " << this->m_ballast << std::endl;
    std::cout << "  m_fuelLoad: " << this->m_fuelLoad << std::endl;
  }
};

#endif
