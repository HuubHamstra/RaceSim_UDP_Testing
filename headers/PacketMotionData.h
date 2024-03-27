#ifndef PACKETMOTIONDATA_H
#define PACKETMOTIONDATA_H

#include <cstdint> // Inclusie van cstdint voor het definiëren van uint16_t, uint8_t, uint32_t, uint64_t
#include "PacketHeader.h"
#include "CarMotionData.h"

struct PacketMotionData
{
  PacketHeader m_header; // Header

  CarMotionData m_carMotionData[22]; // Data for all cars on track

  // Extra player car ONLY data
  float m_suspensionPosition[4];     // Note: All wheel arrays have the following order:
  float m_suspensionVelocity[4];     // RL, RR, FL, FR
  float m_suspensionAcceleration[4]; // RL, RR, FL, FR
  float m_wheelSpeed[4];             // Speed of each wheel
  float m_wheelSlip[4];              // Slip ratio for each wheel
  float m_localVelocityX;            // Velocity in local space
  float m_localVelocityY;            // Velocity in local space
  float m_localVelocityZ;            // Velocity in local space
  float m_angularVelocityX;          // Angular velocity x-component
  float m_angularVelocityY;          // Angular velocity y-component
  float m_angularVelocityZ;          // Angular velocity z-component
  float m_angularAccelerationX;      // Angular velocity x-component
  float m_angularAccelerationY;      // Angular velocity y-component
  float m_angularAccelerationZ;      // Angular velocity z-component
  float m_frontWheelsAngle;          // Current front wheels angle in radians

  void get(char *buffer)
  {
    // WorldPosition
    unsigned long offset = this->m_header.get(buffer);
    for (int i = 0; i < 22; i++)
    {
      offset = this->m_carMotionData[i].get(buffer, offset);
    }
    // Suspensions
    for (int i = 0; i < 4; i++)
    {
      memcpy(&this->m_suspensionPosition[i], &buffer[offset],
             sizeof(this->m_suspensionPosition[i]));
      offset = offset + sizeof(this->m_suspensionPosition[i]);
    }
    for (int i = 0; i < 4; i++)
    {
      memcpy(&this->m_suspensionVelocity[i], &buffer[offset],
             sizeof(this->m_suspensionVelocity[i]));
      offset = offset + sizeof(this->m_suspensionVelocity[i]);
    }
    for (int i = 0; i < 4; i++)
    {
      memcpy(&this->m_suspensionAcceleration[i], &buffer[offset],
             sizeof(this->m_suspensionAcceleration[i]));
      offset = offset + sizeof(this->m_suspensionAcceleration[i]);
    }
    // Wheels
    for (int i = 0; i < 4; i++)
    {
      memcpy(&this->m_wheelSpeed[i], &buffer[offset],
             sizeof(this->m_wheelSpeed[i]));
      offset = offset + sizeof(this->m_wheelSpeed[i]);
    }
    for (int i = 0; i < 4; i++)
    {
      memcpy(&this->m_wheelSlip[i], &buffer[offset],
             sizeof(this->m_wheelSlip[i]));
      offset = offset + sizeof(this->m_wheelSlip[i]);
    }
    // localVelocity
    memcpy(&this->m_localVelocityX, &buffer[offset],
           sizeof(m_localVelocityX));
    offset = offset + sizeof(m_localVelocityX);
    memcpy(&this->m_localVelocityY, &buffer[offset],
           sizeof(m_localVelocityY));
    offset = offset + sizeof(m_localVelocityY);
    memcpy(&this->m_localVelocityZ, &buffer[offset],
           sizeof(m_localVelocityZ));
    offset = offset + sizeof(m_localVelocityZ);
    // angularVelocity
    memcpy(&this->m_angularVelocityX, &buffer[offset],
           sizeof(m_angularVelocityX));
    offset = offset + sizeof(m_angularVelocityX);
    memcpy(&this->m_angularVelocityY, &buffer[offset],
           sizeof(m_angularVelocityY));
    offset = offset + sizeof(m_angularVelocityY);
    memcpy(&this->m_angularVelocityZ, &buffer[offset],
           sizeof(m_angularVelocityZ));
    offset = offset + sizeof(m_angularVelocityZ);
    // angularAcceleration
    memcpy(&this->m_angularAccelerationX, &buffer[offset],
           sizeof(m_angularAccelerationX));
    offset = offset + sizeof(m_angularAccelerationX);
    memcpy(&this->m_angularAccelerationY, &buffer[offset],
           sizeof(m_angularAccelerationY));
    offset = offset + sizeof(m_angularAccelerationY);
    memcpy(&this->m_angularAccelerationZ, &buffer[offset],
           sizeof(m_angularAccelerationZ));
    offset = offset + sizeof(m_angularAccelerationZ);

    memcpy(&this->m_frontWheelsAngle, &buffer[offset],
           sizeof(m_frontWheelsAngle));
    offset = offset + sizeof(m_frontWheelsAngle);
  }

  void print()
  {
    std::cout << " "
              << "PacketMotionData {" << std::endl;
    for (int i = 0; i < 22; i++) // 22 = this->m_carMotionData.size()
    {
      std::cout << "   "
                << "m_carMotionData[" << i << "]: " << std::endl;
      this->m_carMotionData[i].print(); // Changed from this->m_carMotionData->print();
    }

    // Suspensions
    for (int i = 0; i < 4; i++)
    {
      switch (i)
      {
      case 0:
        std::cout << "  Wheel Rear Left" << std::endl;
        break;
      case 1:
        std::cout << "  Wheel Rear Right" << std::endl;
        break;
      case 2:
        std::cout << "  Wheel Front Left" << std::endl;
        break;
      case 3:
        std::cout << "  Wheel Front Right" << std::endl;
        break;
      default:
        std::cout << "  Wheel None" << std::endl;
        break;
      }
      std::cout << "   m_suspensionPosition[" << i
                << "]: " << std::endl; // Added missing semicolon here
      std::cout << "   m_suspensionVelocity[" << i
                << "]: " << std::endl; // Added missing semicolon here
      std::cout << "   m_suspensionAcceleration[" << i
                << "]: " << this->m_suspensionAcceleration[i]
                << std::endl;
    }
    // Wheels
    for (int i = 0; i < 4; i++)
    {
      switch (i)
      {
      case 0:
        std::cout << "  Wheel Rear Left" << std::endl;
        break;
      case 1:
        std::cout << "  Wheel Rear Right" << std::endl;
        break;
      case 2:
        std::cout << "  Wheel Front Left" << std::endl;
        break;
      case 3:
        std::cout << "  Wheel Front Right" << std::endl;
        break;
      default:
        std::cout << "  Wheel None" << std::endl;
        break;
      }
      std::cout << "   m_wheelSpeed[" << i
                << "]: " << std::endl; // Added missing semicolon here
      std::cout << "   m_wheelSlip[" << i
                << "]: " << std::endl; // Added missing semicolon here
    }
    // localVelocity
    std::cout << "   m_localVelocityX: " << this->m_localVelocityX
              << std::endl;
    std::cout << "   m_localVelocityY: " << this->m_localVelocityY
              << std::endl;
    std::cout << "   m_localVelocityZ: " << this->m_localVelocityZ
              << std::endl;
    // angularVelocity
    std::cout << "   m_angularVelocityX: " << this->m_angularVelocityX
              << std::endl;
    std::cout << "   m_angularVelocityY: " << this->m_angularVelocityY
              << std::endl;
    std::cout << "   m_angularVelocityZ: " << this->m_angularVelocityZ
              << std::endl;
    // angularAcceleration
    std::cout << "   m_angularAccelerationX: "
              << this->m_angularAccelerationX << std::endl;
    std::cout << "   m_angularAccelerationY: "
              << this->m_angularAccelerationY << std::endl;
    std::cout << "   m_angularAccelerationZ: "
              << this->m_angularAccelerationZ << std::endl;

    std::cout << "   m_frontWheelsAngle: " << this->m_frontWheelsAngle
              << std::endl;

    std::cout << " "
              << "}" << std::endl;
  }
};

#endif