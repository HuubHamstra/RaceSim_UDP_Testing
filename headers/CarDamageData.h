#ifndef CARDAMAGEDATA_H
#define CARDAMAGEDATA_H

#include <cstdint>
#include <iostream>

struct CarDamageData
{
  float m_tyresWear[4];           // Tyre wear (percentage)
  uint8_t m_tyresDamage[4];       // Tyre damage (percentage)
  uint8_t m_brakesDamage[4];      // Brakes damage (percentage)
  uint8_t m_frontLeftWingDamage;  // Front left wing damage (percentage)
  uint8_t m_frontRightWingDamage; // Front right wing damage (percentage)
  uint8_t m_rearWingDamage;       // Rear wing damage (percentage)
  uint8_t m_floorDamage;          // Floor damage (percentage)
  uint8_t m_diffuserDamage;       // Diffuser damage (percentage)
  uint8_t m_sidepodDamage;        // Sidepod damage (percentage)
  uint8_t m_drsFault;             // Indicator for DRS fault, 0 = OK, 1 = fault
  uint8_t m_ersFault;             // Indicator for ERS fault, 0 = OK, 1 = fault
  uint8_t m_gearBoxDamage;        // Gear box damage (percentage)
  uint8_t m_engineDamage;         // Engine damage (percentage)
  uint8_t m_engineMGUHWear;       // Engine wear MGU-H (percentage)
  uint8_t m_engineESWear;         // Engine wear ES (percentage)
  uint8_t m_engineCEWear;         // Engine wear CE (percentage)
  uint8_t m_engineICEWear;        // Engine wear ICE (percentage)
  uint8_t m_engineMGUKWear;       // Engine wear MGU-K (percentage)
  uint8_t m_engineTCWear;         // Engine wear TC (percentage)
  uint8_t m_engineBlown;          // Engine blown, 0 = OK, 1 = fault
  uint8_t m_engineSeized;         // Engine seized, 0 = OK, 1 = fault

  unsigned long get(char *buffer)
  {
    unsigned long offset = 0;
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_tyresWear[i], &buffer[offset], sizeof(this->m_tyresWear[i]));
        offset = offset + sizeof(this->m_tyresWear[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_tyresDamage[i], &buffer[offset], sizeof(this->m_tyresDamage[i]));
        offset = offset + sizeof(this->m_tyresDamage[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 4; i++)
      {
        memcpy(&this->m_brakesDamage[i], &buffer[offset], sizeof(this->m_brakesDamage[i]));
        offset = offset + sizeof(this->m_brakesDamage[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_frontLeftWingDamage, &buffer[offset], sizeof(this->m_frontLeftWingDamage));
      this->m_frontLeftWingDamage = static_cast<uint8_t>(this->m_frontLeftWingDamage);
      offset += sizeof(m_frontLeftWingDamage);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_frontRightWingDamage, &buffer[offset], sizeof(this->m_frontRightWingDamage));
      this->m_frontRightWingDamage = static_cast<uint8_t>(this->m_frontRightWingDamage);
      offset += sizeof(m_frontRightWingDamage);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_rearWingDamage, &buffer[offset], sizeof(this->m_rearWingDamage));
      this->m_rearWingDamage = static_cast<uint8_t>(this->m_rearWingDamage);
      offset += sizeof(m_rearWingDamage);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_floorDamage, &buffer[offset], sizeof(this->m_floorDamage));
      this->m_floorDamage = static_cast<uint8_t>(this->m_floorDamage);
      offset += sizeof(m_floorDamage);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_diffuserDamage, &buffer[offset], sizeof(this->m_diffuserDamage));
      this->m_diffuserDamage = static_cast<uint8_t>(this->m_diffuserDamage);
      offset += sizeof(m_diffuserDamage);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_sidepodDamage, &buffer[offset], sizeof(this->m_sidepodDamage));
      this->m_sidepodDamage = static_cast<uint8_t>(this->m_sidepodDamage);
      offset += sizeof(m_sidepodDamage);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_drsFault, &buffer[offset], sizeof(this->m_drsFault));
      this->m_drsFault = static_cast<uint8_t>(this->m_drsFault);
      offset += sizeof(m_drsFault);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_ersFault, &buffer[offset], sizeof(this->m_ersFault));
      this->m_ersFault = static_cast<uint8_t>(this->m_ersFault);
      offset += sizeof(m_ersFault);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_gearBoxDamage, &buffer[offset], sizeof(this->m_gearBoxDamage));
      this->m_gearBoxDamage = static_cast<uint8_t>(this->m_gearBoxDamage);
      offset += sizeof(m_gearBoxDamage);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_engineDamage, &buffer[offset], sizeof(this->m_engineDamage));
      this->m_engineDamage = static_cast<uint8_t>(this->m_engineDamage);
      offset += sizeof(m_engineDamage);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_engineMGUHWear, &buffer[offset], sizeof(this->m_engineMGUHWear));
      this->m_engineMGUHWear = static_cast<uint8_t>(this->m_engineMGUHWear);
      offset += sizeof(m_engineMGUHWear);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_engineESWear, &buffer[offset], sizeof(this->m_engineESWear));
      this->m_engineESWear = static_cast<uint8_t>(this->m_engineESWear);
      offset += sizeof(m_engineESWear);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_engineCEWear, &buffer[offset], sizeof(this->m_engineCEWear));
      this->m_engineCEWear = static_cast<uint8_t>(this->m_engineCEWear);
      offset += sizeof(m_engineCEWear);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_engineICEWear, &buffer[offset], sizeof(this->m_engineICEWear));
      this->m_engineICEWear = static_cast<uint8_t>(this->m_engineICEWear);
      offset += sizeof(m_engineICEWear);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_engineMGUKWear, &buffer[offset], sizeof(this->m_engineMGUKWear));
      this->m_engineMGUKWear = static_cast<uint8_t>(this->m_engineMGUKWear);
      offset += sizeof(m_engineMGUKWear);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_engineTCWear, &buffer[offset], sizeof(this->m_engineTCWear));
      this->m_engineTCWear = static_cast<uint8_t>(this->m_engineTCWear);
      offset += sizeof(m_engineTCWear);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_engineBlown, &buffer[offset], sizeof(this->m_engineBlown));
      this->m_engineBlown = static_cast<uint8_t>(this->m_engineBlown);
      offset += sizeof(m_engineBlown);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_engineSeized, &buffer[offset], sizeof(this->m_engineSeized));
      this->m_engineSeized = static_cast<uint8_t>(this->m_engineSeized);
      offset += sizeof(m_engineSeized);
    }
    return offset;
  }

  void print()
  {
    std::cout << "CarDamageData:" << std::endl;
    std::cout << "  m_tyresWear[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_tyresWear[" << i << "]: " << this->m_tyresWear[i] << std::endl;
    }
    std::cout << "  m_tyresDamage[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_tyresDamage[" << i << "]: " << this->m_tyresDamage[i] << std::endl;
    }
    std::cout << "  m_brakesDamage[4]: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
      std::cout << "  m_brakesDamage[" << i << "]: " << this->m_brakesDamage[i] << std::endl;
    }
    std::cout << "  m_frontLeftWingDamage: " << this->m_frontLeftWingDamage << std::endl;
    std::cout << "  m_frontRightWingDamage: " << this->m_frontRightWingDamage << std::endl;
    std::cout << "  m_rearWingDamage: " << this->m_rearWingDamage << std::endl;
    std::cout << "  m_floorDamage: " << this->m_floorDamage << std::endl;
    std::cout << "  m_diffuserDamage: " << this->m_diffuserDamage << std::endl;
    std::cout << "  m_sidepodDamage: " << this->m_sidepodDamage << std::endl;
    std::cout << "  m_drsFault: " << this->m_drsFault << std::endl;
    std::cout << "  m_ersFault: " << this->m_ersFault << std::endl;
    std::cout << "  m_gearBoxDamage: " << this->m_gearBoxDamage << std::endl;
    std::cout << "  m_engineDamage: " << this->m_engineDamage << std::endl;
    std::cout << "  m_engineMGUHWear: " << this->m_engineMGUHWear << std::endl;
    std::cout << "  m_engineESWear: " << this->m_engineESWear << std::endl;
    std::cout << "  m_engineCEWear: " << this->m_engineCEWear << std::endl;
    std::cout << "  m_engineICEWear: " << this->m_engineICEWear << std::endl;
    std::cout << "  m_engineMGUKWear: " << this->m_engineMGUKWear << std::endl;
    std::cout << "  m_engineTCWear: " << this->m_engineTCWear << std::endl;
    std::cout << "  m_engineBlown: " << this->m_engineBlown << std::endl;
    std::cout << "  m_engineSeized: " << this->m_engineSeized << std::endl;
  }
};

#endif
