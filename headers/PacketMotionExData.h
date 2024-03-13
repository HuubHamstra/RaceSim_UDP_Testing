#ifndef PACKETMOTIONEXDATA_H
#define PACKETMOTIONEXDATA_H

#include <cstdint>
#include <iostream>
#include "PacketHeader.h"

struct PacketMotionExData
{
  PacketHeader m_header; // Header

  // Extra player car ONLY data
  float m_suspensionPosition[4];     // Note: All wheel arrays have the following order:
  float m_suspensionVelocity[4];     // RL, RR, FL, FR
  float m_suspensionAcceleration[4]; // RL, RR, FL, FR
  float m_wheelSpeed[4];             // Speed of each wheel
  float m_wheelSlipRatio[4];         // Slip ratio for each wheel
  float m_wheelSlipAngle[4];         // Slip angles for each wheel
  float m_wheelLatForce[4];          // Lateral forces for each wheel
  float m_wheelLongForce[4];         // Longitudinal forces for each wheel
  float m_heightOfCOGAboveGround;    // Height of centre of gravity above ground
  float m_localVelocityX;            // Velocity in local space – metres/s
  float m_localVelocityY;            // Velocity in local space
  float m_localVelocityZ;            // Velocity in local space
  float m_angularVelocityX;          // Angular velocity x-component – radians/s
  float m_angularVelocityY;          // Angular velocity y-component
  float m_angularVelocityZ;          // Angular velocity z-component
  float m_angularAccelerationX;      // Angular acceleration x-component – radians/s/s
  float m_angularAccelerationY;      // Angular acceleration y-component
  float m_angularAccelerationZ;      // Angular acceleration z-component
  float m_frontWheelsAngle;          // Current front wheels angle in radians
  float m_wheelVertForce[4];         // Vertical forces for each wheel

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
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_suspensionPosition[i], &buffer[offset], sizeof(this->m_suspensionPosition[i]));
        offset = offset + sizeof(this->m_suspensionPosition[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_suspensionVelocity[i], &buffer[offset], sizeof(this->m_suspensionVelocity[i]));
        offset = offset + sizeof(this->m_suspensionVelocity[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_suspensionAcceleration[i], &buffer[offset], sizeof(this->m_suspensionAcceleration[i]));
        offset = offset + sizeof(this->m_suspensionAcceleration[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_wheelSpeed[i], &buffer[offset], sizeof(this->m_wheelSpeed[i]));
        offset = offset + sizeof(this->m_wheelSpeed[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_wheelSlipRatio[i], &buffer[offset], sizeof(this->m_wheelSlipRatio[i]));
        offset = offset + sizeof(this->m_wheelSlipRatio[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_wheelSlipAngle[i], &buffer[offset], sizeof(this->m_wheelSlipAngle[i]));
        offset = offset + sizeof(this->m_wheelSlipAngle[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_wheelLatForce[i], &buffer[offset], sizeof(this->m_wheelLatForce[i]));
        offset = offset + sizeof(this->m_wheelLatForce[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_wheelLongForce[i], &buffer[offset], sizeof(this->m_wheelLongForce[i]));
        offset = offset + sizeof(this->m_wheelLongForce[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_heightOfCOGAboveGround, &buffer[offset], sizeof(this->m_heightOfCOGAboveGround));
      offset += sizeof(m_heightOfCOGAboveGround);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_localVelocityX, &buffer[offset], sizeof(this->m_localVelocityX));
      offset += sizeof(m_localVelocityX);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_localVelocityY, &buffer[offset], sizeof(this->m_localVelocityY));
      offset += sizeof(m_localVelocityY);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_localVelocityZ, &buffer[offset], sizeof(this->m_localVelocityZ));
      offset += sizeof(m_localVelocityZ);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_angularVelocityX, &buffer[offset], sizeof(this->m_angularVelocityX));
      offset += sizeof(m_angularVelocityX);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_angularVelocityY, &buffer[offset], sizeof(this->m_angularVelocityY));
      offset += sizeof(m_angularVelocityY);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_angularVelocityZ, &buffer[offset], sizeof(this->m_angularVelocityZ));
      offset += sizeof(m_angularVelocityZ);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_angularAccelerationX, &buffer[offset], sizeof(this->m_angularAccelerationX));
      offset += sizeof(m_angularAccelerationX);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_angularAccelerationY, &buffer[offset], sizeof(this->m_angularAccelerationY));
      offset += sizeof(m_angularAccelerationY);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_angularAccelerationZ, &buffer[offset], sizeof(this->m_angularAccelerationZ));
      offset += sizeof(m_angularAccelerationZ);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_frontWheelsAngle, &buffer[offset], sizeof(this->m_frontWheelsAngle));
      offset += sizeof(m_frontWheelsAngle);
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_wheelVertForce[i], &buffer[offset], sizeof(this->m_wheelVertForce[i]));
        offset = offset + sizeof(this->m_wheelVertForce[i]);
      }
    }
    return offset;
  }

  void print()
  {
    std::cout << "PacketMotionExData:" << std::endl;
    std::cout << "  m_header: " << std::endl;
    this->m_header.print();
    std::cout << "  m_suspensionPosition[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_suspensionPosition[" << i << "]: " << this->m_suspensionPosition[i] << std::endl;
    }
    std::cout << "  m_suspensionVelocity[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_suspensionVelocity[" << i << "]: " << this->m_suspensionVelocity[i] << std::endl;
    }
    std::cout << "  m_suspensionAcceleration[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_suspensionAcceleration[" << i << "]: " << this->m_suspensionAcceleration[i] << std::endl;
    }
    std::cout << "  m_wheelSpeed[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_wheelSpeed[" << i << "]: " << this->m_wheelSpeed[i] << std::endl;
    }
    std::cout << "  m_wheelSlipRatio[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_wheelSlipRatio[" << i << "]: " << this->m_wheelSlipRatio[i] << std::endl;
    }
    std::cout << "  m_wheelSlipAngle[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_wheelSlipAngle[" << i << "]: " << this->m_wheelSlipAngle[i] << std::endl;
    }
    std::cout << "  m_wheelLatForce[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_wheelLatForce[" << i << "]: " << this->m_wheelLatForce[i] << std::endl;
    }
    std::cout << "  m_wheelLongForce[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_wheelLongForce[" << i << "]: " << this->m_wheelLongForce[i] << std::endl;
    }
    std::cout << "  m_heightOfCOGAboveGround: " << this->m_heightOfCOGAboveGround << std::endl;
    std::cout << "  m_localVelocityX: " << this->m_localVelocityX << std::endl;
    std::cout << "  m_localVelocityY: " << this->m_localVelocityY << std::endl;
    std::cout << "  m_localVelocityZ: " << this->m_localVelocityZ << std::endl;
    std::cout << "  m_angularVelocityX: " << this->m_angularVelocityX << std::endl;
    std::cout << "  m_angularVelocityY: " << this->m_angularVelocityY << std::endl;
    std::cout << "  m_angularVelocityZ: " << this->m_angularVelocityZ << std::endl;
    std::cout << "  m_angularAccelerationX: " << this->m_angularAccelerationX << std::endl;
    std::cout << "  m_angularAccelerationY: " << this->m_angularAccelerationY << std::endl;
    std::cout << "  m_angularAccelerationZ: " << this->m_angularAccelerationZ << std::endl;
    std::cout << "  m_frontWheelsAngle: " << this->m_frontWheelsAngle << std::endl;
    std::cout << "  m_wheelVertForce[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_wheelVertForce[" << i << "]: " << this->m_wheelVertForce[i] << std::endl;
    }
  }
};

#endif
