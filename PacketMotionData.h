#ifndef PACKETMOTIONDATA_H
#define PACKETMOTIONDATA_H

#include <cstdint> // Inclusie van cstdint voor het definiëren van uint16_t, uint8_t, uint32_t, uint64_t
#include "PacketHeader.h"
#include "CarMotionData.h"

struct PacketMotionData {
    PacketHeader    m_header;               	// Header

    CarMotionData   m_carMotionData[22];    	// Data for all cars on track

    // Extra player car ONLY data
    float         m_suspensionPosition[4];       // Note: All wheel arrays have the following order:
    float         m_suspensionVelocity[4];       // RL, RR, FL, FR
    float         m_suspensionAcceleration[4];	// RL, RR, FL, FR
    float         m_wheelSpeed[4];           	// Speed of each wheel
    float         m_wheelSlip[4];                // Slip ratio for each wheel
    float         m_localVelocityX;         	// Velocity in local space
    float         m_localVelocityY;         	// Velocity in local space
    float         m_localVelocityZ;         	// Velocity in local space
    float         m_angularVelocityX;		// Angular velocity x-component
    float         m_angularVelocityY;            // Angular velocity y-component
    float         m_angularVelocityZ;            // Angular velocity z-component
    float         m_angularAccelerationX;        // Angular velocity x-component
    float         m_angularAccelerationY;	// Angular velocity y-component
    float         m_angularAccelerationZ;        // Angular velocity z-component
    float         m_frontWheelsAngle;            // Current front wheels angle in radians

    void get(char* buffer) {
        // WorldPosition
        unsigned long offset = this->m_header.get(buffer);
        for (int i = 0; i < 22; i++) {
            offset = this->m_carMotionData[i].get(buffer, offset);
        }
        // Suspensions
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_suspensionPosition[i], &buffer[offset],
                   sizeof(this->m_suspensionPosition[i]));
            offset = offset + sizeof(this->m_suspensionPosition[i]);
        }
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_suspensionVelocity[i], &buffer[offset],
                   sizeof(this->m_suspensionVelocity[i]));
            offset = offset + sizeof(this->m_suspensionVelocity[i]);
        }
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_suspensionAcceleration[i], &buffer[offset],
                   sizeof(this->m_suspensionAcceleration[i]));
            offset = offset + sizeof(this->m_suspensionAcceleration[i]);
        }
        // Wheels
        for (int i = 0; i < 4; i++) {
            memcpy(&this->m_wheelSpeed[i], &buffer[offset],
                   sizeof(this->m_wheelSpeed[i]));
            offset = offset + sizeof(this->m_wheelSpeed[i]);
        }
        for (int i = 0; i < 4; i++) {
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
};

#endif