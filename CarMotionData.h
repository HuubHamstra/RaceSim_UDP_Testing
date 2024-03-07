#ifndef CARMOTIONDATA_H
#define CARMOTIONDATA_H

#include <cstdint> // Include cstdint for defining int16_t, uint16_t, etc.

struct CarMotionData
{
    float m_worldPositionX; // World space X position - metres
    float m_worldPositionY; // World space Y position
    float m_worldPositionZ; // World space Z position
    float m_worldVelocityX; // Velocity in world space X – metres/s
    float m_worldVelocityY; // Velocity in world space Y
    float m_worldVelocityZ; // Velocity in world space Z
    int16_t m_worldForwardDirX; // World space forward X direction (normalised)
    int16_t m_worldForwardDirY; // World space forward Y direction (normalised)
    int16_t m_worldForwardDirZ; // World space forward Z direction (normalised)
    int16_t m_worldRightDirX; // World space right X direction (normalised)
    int16_t m_worldRightDirY; // World space right Y direction (normalised)
    int16_t m_worldRightDirZ; // World space right Z direction (normalised)
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

    void print() {
        std::cout << " "
                   << "CarMotionData {" << std::endl;
        // WorldPosition
        std::cout << "   "
                   << "m_worldPositionX: " << this->m_worldPositionX
                   << std::endl;
        std::cout << "   "
                   << "m_worldPositionY: " << this->m_worldPositionY
                   << std::endl;
        std::cout << "   "
                   << "m_worldPositionZ: " << this->m_worldPositionZ
                   << std::endl;
        // WorldVelocity
        std::cout << "   "
                   << "m_worldVelocityX: " << this->m_worldVelocityX
                   << std::endl;
        std::cout << "   "
                   << "m_worldVelocityY: " << this->m_worldVelocityY
                   << std::endl;
        std::cout << "   "
                   << "m_worldVelocityZ: " << this->m_worldVelocityZ
                   << std::endl;
        // WorldForwardDir
        std::cout << "   "
                   << "m_worldForwardDirX: " << this->m_worldForwardDirX
                   << std::endl;
        std::cout << "   "
                   << "m_worldForwardDirY: " << this->m_worldForwardDirY
                   << std::endl;
        std::cout << "   "
                   << "m_worldForwardDirZ: " << this->m_worldForwardDirZ
                   << std::endl;
        // WorldRightDir
        std::cout << "   "
                   << "m_worldRightDirX: " << this->m_worldRightDirX
                   << std::endl;
        std::cout << "   "
                   << "m_worldRightDirY: " << this->m_worldRightDirY
                   << std::endl;
        std::cout << "   "
                   << "m_worldRightDirZ: " << this->m_worldRightDirZ
                   << std::endl;
        // gForce
        std::cout << "   "
                   << "m_gForceLateral: " << this->m_gForceLateral << std::endl;
        std::cout << "   "
                   << "m_gForceLongitudinal: " << this->m_gForceLongitudinal
                   << std::endl;
        std::cout << "   "
                   << "m_gForceVertical: " << this->m_gForceVertical
                   << std::endl;
        // Angles
        std::cout << "   "
                   << "m_yaw: " << this->m_yaw << std::endl;
        std::cout << "   "
                   << "m_pitch: " << this->m_pitch << std::endl;
        std::cout << "   "
                   << "m_roll: " << this->m_roll << std::endl;
        //
        std::cout << " "
                   << "}" << std::endl;
    }
};

#endif
