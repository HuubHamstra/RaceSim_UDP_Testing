#ifndef FINALCLASSIFICATIONDATA_H
#define FINALCLASSIFICATIONDATA_H

#include <cstdint>
#include <iostream>

struct FinalClassificationData
{
  uint8_t m_position;             // Finishing position
  uint8_t m_numLaps;              // Number of laps completed
  uint8_t m_gridPosition;         // Grid position of the car
  uint8_t m_points;               // Number of points scored
  uint8_t m_numPitStops;          // Number of pit stops made
  uint8_t m_resultStatus;         // Result status - 0 = invalid, 1 = inactive, 2 = active
                                  // 3 = finished, 4 = didnotfinish, 5 = disqualified
                                  // 6 = not classified, 7 = retired
  uint32_t m_bestLapTimeInMS;     // Best lap time of the session in milliseconds
  double m_totalRaceTime;         // Total race time in seconds without penalties
  uint8_t m_penaltiesTime;        // Total penalties accumulated in seconds
  uint8_t m_numPenalties;         // Number of penalties applied to this driver
  uint8_t m_numTyreStints;        // Number of tyres stints up to maximum
  uint8_t m_tyreStintsActual[8];  // Actual tyres used by this driver
  uint8_t m_tyreStintsVisual[8];  // Visual tyres used by this driver
  uint8_t m_tyreStintsEndLaps[8]; // The lap number stints end on

  unsigned long get(char *buffer)
  {
    unsigned long offset = 0;
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_position, &buffer[offset], sizeof(this->m_position));
      this->m_position = static_cast<uint8_t>(this->m_position);
      offset += sizeof(m_position);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_numLaps, &buffer[offset], sizeof(this->m_numLaps));
      this->m_numLaps = static_cast<uint8_t>(this->m_numLaps);
      offset += sizeof(m_numLaps);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_gridPosition, &buffer[offset], sizeof(this->m_gridPosition));
      this->m_gridPosition = static_cast<uint8_t>(this->m_gridPosition);
      offset += sizeof(m_gridPosition);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_points, &buffer[offset], sizeof(this->m_points));
      this->m_points = static_cast<uint8_t>(this->m_points);
      offset += sizeof(m_points);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_numPitStops, &buffer[offset], sizeof(this->m_numPitStops));
      this->m_numPitStops = static_cast<uint8_t>(this->m_numPitStops);
      offset += sizeof(m_numPitStops);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_resultStatus, &buffer[offset], sizeof(this->m_resultStatus));
      this->m_resultStatus = static_cast<uint8_t>(this->m_resultStatus);
      offset += sizeof(m_resultStatus);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_bestLapTimeInMS, &buffer[offset], sizeof(this->m_bestLapTimeInMS));
      this->m_bestLapTimeInMS = static_cast<uint32_t>(this->m_bestLapTimeInMS);
      offset += sizeof(m_bestLapTimeInMS);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_totalRaceTime, &buffer[offset], sizeof(this->m_totalRaceTime));
      offset += sizeof(m_totalRaceTime);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_penaltiesTime, &buffer[offset], sizeof(this->m_penaltiesTime));
      this->m_penaltiesTime = static_cast<uint8_t>(this->m_penaltiesTime);
      offset += sizeof(m_penaltiesTime);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_numPenalties, &buffer[offset], sizeof(this->m_numPenalties));
      this->m_numPenalties = static_cast<uint8_t>(this->m_numPenalties);
      offset += sizeof(m_numPenalties);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_numTyreStints, &buffer[offset], sizeof(this->m_numTyreStints));
      this->m_numTyreStints = static_cast<uint8_t>(this->m_numTyreStints);
      offset += sizeof(m_numTyreStints);
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 8; i++)
      {
        memcpy(&this->m_tyreStintsActual[i], &buffer[offset], sizeof(this->m_tyreStintsActual[i]));
        offset = offset + sizeof(this->m_tyreStintsActual[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 8; i++)
      {
        memcpy(&this->m_tyreStintsVisual[i], &buffer[offset], sizeof(this->m_tyreStintsVisual[i]));
        offset = offset + sizeof(this->m_tyreStintsVisual[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 8; i++)
      {
        memcpy(&this->m_tyreStintsEndLaps[i], &buffer[offset], sizeof(this->m_tyreStintsEndLaps[i]));
        offset = offset + sizeof(this->m_tyreStintsEndLaps[i]);
      }
    }
    return offset;
  }

  void print()
  {
    std::cout << "FinalClassificationData:" << std::endl;
    std::cout << "  m_position: " << this->m_position << std::endl;
    std::cout << "  m_numLaps: " << this->m_numLaps << std::endl;
    std::cout << "  m_gridPosition: " << this->m_gridPosition << std::endl;
    std::cout << "  m_points: " << this->m_points << std::endl;
    std::cout << "  m_numPitStops: " << this->m_numPitStops << std::endl;
    std::cout << "  m_resultStatus: " << this->m_resultStatus << std::endl;
    std::cout << "  m_bestLapTimeInMS: " << this->m_bestLapTimeInMS << std::endl;
    std::cout << "  m_totalRaceTime: " << this->m_totalRaceTime << std::endl;
    std::cout << "  m_penaltiesTime: " << this->m_penaltiesTime << std::endl;
    std::cout << "  m_numPenalties: " << this->m_numPenalties << std::endl;
    std::cout << "  m_numTyreStints: " << this->m_numTyreStints << std::endl;
    std::cout << "  m_tyreStintsActual[8]: " << std::endl;
    for (int i = 0; i < 8; i++)
    {
      std::cout << "  m_tyreStintsActual[" << i << "]: " << this->m_tyreStintsActual[i] << std::endl;
    }
    std::cout << "  m_tyreStintsVisual[8]: " << std::endl;
    for (int i = 0; i < 8; i++)
    {
      std::cout << "  m_tyreStintsVisual[" << i << "]: " << this->m_tyreStintsVisual[i] << std::endl;
    }
    std::cout << "  m_tyreStintsEndLaps[8]: " << std::endl;
    for (int i = 0; i < 8; i++)
    {
      std::cout << "  m_tyreStintsEndLaps[" << i << "]: " << this->m_tyreStintsEndLaps[i] << std::endl;
    }
  }
};

#endif
