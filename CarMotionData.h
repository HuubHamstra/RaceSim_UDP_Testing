#ifndef CARMOTIONDATA_H
#define CARMOTIONDATA_H

typedef unsigned short uint16;
typedef unsigned short uint8;
typedef unsigned short uint32;
typedef unsigned short uint64;

#include <cstdint> // Include cstdint for defining int16, uint16, etc.

struct CarMotionData
{
    float m_worldPositionX; // World space X position - metres
    float m_worldPositionY; // World space Y position
    float m_worldPositionZ; // World space Z position
    float m_worldVelocityX; // Velocity in world space X – metres/s
    float m_worldVelocityY; // Velocity in world space Y
    float m_worldVelocityZ; // Velocity in world space Z
    uint16 m_worldForwardDirX; // World space forward X direction (normalised)
    uint16 m_worldForwardDirY; // World space forward Y direction (normalised)
    uint16 m_worldForwardDirZ; // World space forward Z direction (normalised)
    uint16 m_worldRightDirX; // World space right X direction (normalised)
    uint16 m_worldRightDirY; // World space right Y direction (normalised)
    uint16 m_worldRightDirZ; // World space right Z direction (normalised)
    float m_gForceLateral; // Lateral G-Force component
    float m_gForceLongitudinal; // Longitudinal G-Force component
    float m_gForceVertical; // Vertical G-Force component
    float m_yaw; // Yaw angle in radians
    float m_pitch; // Pitch angle in radians
    float m_roll; // Roll angle in radians

    unsigned long get(char* buffer, unsigned long offset) {
        // WorldPosition
        memcpy(&this->m_worldPositionX, &buffer[offset],
               sizeof(m_worldPositionX));
        offset = offset + sizeof(m_worldPositionX);
        memcpy(&this->m_worldPositionY, &buffer[offset],
               sizeof(m_worldPositionY));
        offset = offset + sizeof(m_worldPositionY);
        memcpy(&this->m_worldPositionZ, &buffer[offset],
               sizeof(m_worldPositionZ));
        offset = offset + sizeof(m_worldPositionZ);
        // WorldVelocity
        memcpy(&this->m_worldVelocityX, &buffer[offset],
               sizeof(m_worldVelocityX));
        offset = offset + sizeof(m_worldVelocityX);
        memcpy(&this->m_worldVelocityY, &buffer[offset],
               sizeof(m_worldVelocityY));
        offset = offset + sizeof(m_worldVelocityY);
        memcpy(&this->m_worldVelocityZ, &buffer[offset],
               sizeof(m_worldVelocityZ));
        offset = offset + sizeof(m_worldVelocityZ);
        // WorldForwardDir
        memcpy(&this->m_worldForwardDirX, &buffer[offset],
               sizeof(m_worldForwardDirX));
        offset = offset + sizeof(m_worldForwardDirX);
        memcpy(&this->m_worldForwardDirY, &buffer[offset],
               sizeof(m_worldForwardDirY));
        offset = offset + sizeof(m_worldForwardDirY);
        memcpy(&this->m_worldForwardDirZ, &buffer[offset],
               sizeof(m_worldForwardDirZ));
        offset = offset + sizeof(m_worldForwardDirZ);
        // WorldRightDir
        memcpy(&this->m_worldRightDirX, &buffer[offset],
               sizeof(m_worldRightDirX));
        offset = offset + sizeof(m_worldRightDirX);
        memcpy(&this->m_worldRightDirY, &buffer[offset],
               sizeof(m_worldRightDirY));
        offset = offset + sizeof(m_worldRightDirY);
        memcpy(&this->m_worldRightDirZ, &buffer[offset],
               sizeof(m_worldRightDirZ));
        offset = offset + sizeof(m_worldRightDirZ);
        // gForce
        memcpy(&this->m_gForceLateral, &buffer[offset],
               sizeof(m_gForceLateral));
        offset = offset + sizeof(m_gForceLateral);
        memcpy(&this->m_gForceLongitudinal, &buffer[offset],
               sizeof(m_gForceLongitudinal));
        offset = offset + sizeof(m_gForceLongitudinal);
        memcpy(&this->m_gForceVertical, &buffer[offset],
               sizeof(m_gForceVertical));
        offset = offset + sizeof(m_gForceVertical);
        // Angles
        memcpy(&this->m_yaw, &buffer[offset], sizeof(m_yaw));
        offset = offset + sizeof(m_yaw);
        memcpy(&this->m_pitch, &buffer[offset], sizeof(m_pitch));
        offset = offset + sizeof(m_pitch);
        memcpy(&this->m_roll, &buffer[offset], sizeof(m_roll));
        offset = offset + sizeof(m_roll);

        //d
        return offset;
    }
};

#endif
