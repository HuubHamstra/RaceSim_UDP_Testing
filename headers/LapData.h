#ifndef LAPDATA_H
#define LAPDATA_H

#include <cstdint>
#include <iostream>

struct LapData
{
  uint32_t m_lastLapTimeInMS;       // Last lap time in milliseconds
  uint32_t m_currentLapTimeInMS;    // Current time around the lap in milliseconds
  uint16_t m_sector1TimeInMS;       // Sector 1 time in milliseconds
  uint8_t m_sector1TimeMinutes;     // Sector 1 whole minute part
  uint16_t m_sector2TimeInMS;       // Sector 2 time in milliseconds
  uint8_t m_sector2TimeMinutes;     // Sector 2 whole minute part
  uint16_t m_deltaToCarInFrontInMS; // Time delta to car in front in milliseconds
  uint16_t m_deltaToRaceLeaderInMS; // Time delta to race leader in milliseconds
  float m_lapDistance;              // Distance vehicle is around current lap in metres – could
                       // be negative if line hasn’t been crossed yet
  float m_totalDistance; // Total distance travelled in session in metres – could
                         // be negative if line hasn’t been crossed yet
  float m_safetyCarDelta;                // Delta in seconds for safety car
  uint8_t m_carPosition;                 // Car race position
  uint8_t m_currentLapNum;               // Current lap number
  uint8_t m_pitStatus;                   // 0 = none, 1 = pitting, 2 = in pit area
  uint8_t m_numPitStops;                 // Number of pit stops taken in this race
  uint8_t m_sector;                      // 0 = sector1, 1 = sector2, 2 = sector3
  uint8_t m_currentLapInvalid;           // Current lap invalid - 0 = valid, 1 = invalid
  uint8_t m_penalties;                   // Accumulated time penalties in seconds to be added
  uint8_t m_totalWarnings;               // Accumulated number of warnings issued
  uint8_t m_cornerCuttingWarnings;       // Accumulated number of corner cutting warnings issued
  uint8_t m_numUnservedDriveThroughPens; // Num drive through pens left to serve
  uint8_t m_numUnservedStopGoPens;       // Num stop go pens left to serve
  uint8_t m_gridPosition;                // Grid position the vehicle started the race in
  uint8_t m_driverStatus;                // Status of driver - 0 = in garage, 1 = flying lap
                                         // 2 = in lap, 3 = out lap, 4 = on track
  uint8_t m_resultStatus;                // Result status - 0 = invalid, 1 = inactive, 2 = active
                                         // 3 = finished, 4 = didnotfinish, 5 = disqualified
                                         // 6 = not classified, 7 = retired
  uint8_t m_pitLaneTimerActive;          // Pit lane timing, 0 = inactive, 1 = active
  uint16_t m_pitLaneTimeInLaneInMS;      // If active, the current time spent in the pit lane in ms
  uint16_t m_pitStopTimerInMS;           // Time of the actual pit stop in ms
  uint8_t m_pitStopShouldServePen;       // Whether the car should serve a penalty at this stop

  unsigned long get(char *buffer)
  {
    unsigned long offset = 0;
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_lastLapTimeInMS, &buffer[offset], sizeof(this->m_lastLapTimeInMS));
      this->m_lastLapTimeInMS = static_cast<uint32_t>(this->m_lastLapTimeInMS);
      offset += sizeof(m_lastLapTimeInMS);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_currentLapTimeInMS, &buffer[offset], sizeof(this->m_currentLapTimeInMS));
      this->m_currentLapTimeInMS = static_cast<uint32_t>(this->m_currentLapTimeInMS);
      offset += sizeof(m_currentLapTimeInMS);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_sector1TimeInMS, &buffer[offset], sizeof(this->m_sector1TimeInMS));
      this->m_sector1TimeInMS = static_cast<uint16_t>(this->m_sector1TimeInMS);
      offset += sizeof(m_sector1TimeInMS);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_sector1TimeMinutes, &buffer[offset], sizeof(this->m_sector1TimeMinutes));
      this->m_sector1TimeMinutes = static_cast<uint8_t>(this->m_sector1TimeMinutes);
      offset += sizeof(m_sector1TimeMinutes);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_sector2TimeInMS, &buffer[offset], sizeof(this->m_sector2TimeInMS));
      this->m_sector2TimeInMS = static_cast<uint16_t>(this->m_sector2TimeInMS);
      offset += sizeof(m_sector2TimeInMS);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_sector2TimeMinutes, &buffer[offset], sizeof(this->m_sector2TimeMinutes));
      this->m_sector2TimeMinutes = static_cast<uint8_t>(this->m_sector2TimeMinutes);
      offset += sizeof(m_sector2TimeMinutes);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_deltaToCarInFrontInMS, &buffer[offset], sizeof(this->m_deltaToCarInFrontInMS));
      this->m_deltaToCarInFrontInMS = static_cast<uint16_t>(this->m_deltaToCarInFrontInMS);
      offset += sizeof(m_deltaToCarInFrontInMS);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_deltaToRaceLeaderInMS, &buffer[offset], sizeof(this->m_deltaToRaceLeaderInMS));
      this->m_deltaToRaceLeaderInMS = static_cast<uint16_t>(this->m_deltaToRaceLeaderInMS);
      offset += sizeof(m_deltaToRaceLeaderInMS);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_lapDistance, &buffer[offset], sizeof(this->m_lapDistance));
      offset += sizeof(m_lapDistance);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_totalDistance, &buffer[offset], sizeof(this->m_totalDistance));
      offset += sizeof(m_totalDistance);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_safetyCarDelta, &buffer[offset], sizeof(this->m_safetyCarDelta));
      offset += sizeof(m_safetyCarDelta);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_carPosition, &buffer[offset], sizeof(this->m_carPosition));
      this->m_carPosition = static_cast<uint8_t>(this->m_carPosition);
      offset += sizeof(m_carPosition);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_currentLapNum, &buffer[offset], sizeof(this->m_currentLapNum));
      this->m_currentLapNum = static_cast<uint8_t>(this->m_currentLapNum);
      offset += sizeof(m_currentLapNum);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_pitStatus, &buffer[offset], sizeof(this->m_pitStatus));
      this->m_pitStatus = static_cast<uint8_t>(this->m_pitStatus);
      offset += sizeof(m_pitStatus);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_numPitStops, &buffer[offset], sizeof(this->m_numPitStops));
      this->m_numPitStops = static_cast<uint8_t>(this->m_numPitStops);
      offset += sizeof(m_numPitStops);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_sector, &buffer[offset], sizeof(this->m_sector));
      this->m_sector = static_cast<uint8_t>(this->m_sector);
      offset += sizeof(m_sector);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_currentLapInvalid, &buffer[offset], sizeof(this->m_currentLapInvalid));
      this->m_currentLapInvalid = static_cast<uint8_t>(this->m_currentLapInvalid);
      offset += sizeof(m_currentLapInvalid);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_penalties, &buffer[offset], sizeof(this->m_penalties));
      this->m_penalties = static_cast<uint8_t>(this->m_penalties);
      offset += sizeof(m_penalties);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_totalWarnings, &buffer[offset], sizeof(this->m_totalWarnings));
      this->m_totalWarnings = static_cast<uint8_t>(this->m_totalWarnings);
      offset += sizeof(m_totalWarnings);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_cornerCuttingWarnings, &buffer[offset], sizeof(this->m_cornerCuttingWarnings));
      this->m_cornerCuttingWarnings = static_cast<uint8_t>(this->m_cornerCuttingWarnings);
      offset += sizeof(m_cornerCuttingWarnings);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_numUnservedDriveThroughPens, &buffer[offset], sizeof(this->m_numUnservedDriveThroughPens));
      this->m_numUnservedDriveThroughPens = static_cast<uint8_t>(this->m_numUnservedDriveThroughPens);
      offset += sizeof(m_numUnservedDriveThroughPens);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_numUnservedStopGoPens, &buffer[offset], sizeof(this->m_numUnservedStopGoPens));
      this->m_numUnservedStopGoPens = static_cast<uint8_t>(this->m_numUnservedStopGoPens);
      offset += sizeof(m_numUnservedStopGoPens);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_gridPosition, &buffer[offset], sizeof(this->m_gridPosition));
      this->m_gridPosition = static_cast<uint8_t>(this->m_gridPosition);
      offset += sizeof(m_gridPosition);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_driverStatus, &buffer[offset], sizeof(this->m_driverStatus));
      this->m_driverStatus = static_cast<uint8_t>(this->m_driverStatus);
      offset += sizeof(m_driverStatus);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_resultStatus, &buffer[offset], sizeof(this->m_resultStatus));
      this->m_resultStatus = static_cast<uint8_t>(this->m_resultStatus);
      offset += sizeof(m_resultStatus);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_pitLaneTimerActive, &buffer[offset], sizeof(this->m_pitLaneTimerActive));
      this->m_pitLaneTimerActive = static_cast<uint8_t>(this->m_pitLaneTimerActive);
      offset += sizeof(m_pitLaneTimerActive);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_pitLaneTimeInLaneInMS, &buffer[offset], sizeof(this->m_pitLaneTimeInLaneInMS));
      this->m_pitLaneTimeInLaneInMS = static_cast<uint16_t>(this->m_pitLaneTimeInLaneInMS);
      offset += sizeof(m_pitLaneTimeInLaneInMS);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_pitStopTimerInMS, &buffer[offset], sizeof(this->m_pitStopTimerInMS));
      this->m_pitStopTimerInMS = static_cast<uint16_t>(this->m_pitStopTimerInMS);
      offset += sizeof(m_pitStopTimerInMS);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_pitStopShouldServePen, &buffer[offset], sizeof(this->m_pitStopShouldServePen));
      this->m_pitStopShouldServePen = static_cast<uint8_t>(this->m_pitStopShouldServePen);
      offset += sizeof(m_pitStopShouldServePen);
    }
    return offset;
  }

  void print()
  {
    std::cout << "LapData:" << std::endl;
    std::cout << "  m_lastLapTimeInMS: " << this->m_lastLapTimeInMS << std::endl;
    std::cout << "  m_currentLapTimeInMS: " << this->m_currentLapTimeInMS << std::endl;
    std::cout << "  m_sector1TimeInMS: " << this->m_sector1TimeInMS << std::endl;
    std::cout << "  m_sector1TimeMinutes: " << this->m_sector1TimeMinutes << std::endl;
    std::cout << "  m_sector2TimeInMS: " << this->m_sector2TimeInMS << std::endl;
    std::cout << "  m_sector2TimeMinutes: " << this->m_sector2TimeMinutes << std::endl;
    std::cout << "  m_deltaToCarInFrontInMS: " << this->m_deltaToCarInFrontInMS << std::endl;
    std::cout << "  m_deltaToRaceLeaderInMS: " << this->m_deltaToRaceLeaderInMS << std::endl;
    std::cout << "  m_lapDistance: " << this->m_lapDistance << std::endl;
    std::cout << "  m_totalDistance: " << this->m_totalDistance << std::endl;
    std::cout << "  m_safetyCarDelta: " << this->m_safetyCarDelta << std::endl;
    std::cout << "  m_carPosition: " << this->m_carPosition << std::endl;
    std::cout << "  m_currentLapNum: " << this->m_currentLapNum << std::endl;
    std::cout << "  m_pitStatus: " << this->m_pitStatus << std::endl;
    std::cout << "  m_numPitStops: " << this->m_numPitStops << std::endl;
    std::cout << "  m_sector: " << this->m_sector << std::endl;
    std::cout << "  m_currentLapInvalid: " << this->m_currentLapInvalid << std::endl;
    std::cout << "  m_penalties: " << this->m_penalties << std::endl;
    std::cout << "  m_totalWarnings: " << this->m_totalWarnings << std::endl;
    std::cout << "  m_cornerCuttingWarnings: " << this->m_cornerCuttingWarnings << std::endl;
    std::cout << "  m_numUnservedDriveThroughPens: " << this->m_numUnservedDriveThroughPens << std::endl;
    std::cout << "  m_numUnservedStopGoPens: " << this->m_numUnservedStopGoPens << std::endl;
    std::cout << "  m_gridPosition: " << this->m_gridPosition << std::endl;
    std::cout << "  m_driverStatus: " << this->m_driverStatus << std::endl;
    std::cout << "  m_resultStatus: " << this->m_resultStatus << std::endl;
    std::cout << "  m_pitLaneTimerActive: " << this->m_pitLaneTimerActive << std::endl;
    std::cout << "  m_pitLaneTimeInLaneInMS: " << this->m_pitLaneTimeInLaneInMS << std::endl;
    std::cout << "  m_pitStopTimerInMS: " << this->m_pitStopTimerInMS << std::endl;
    std::cout << "  m_pitStopShouldServePen: " << this->m_pitStopShouldServePen << std::endl;
  }
};

#endif
