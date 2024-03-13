#ifndef PACKETSESSIONDATA_H
#define PACKETSESSIONDATA_H

#include <cstdint>
#include <iostream>
#include "PacketHeader.h"
#include "MarshalZone.h"
#include "WeatherForecastSample.h"

struct PacketSessionData
{
  PacketHeader m_header; // Header

  uint8_t m_weather;                                  // Weather - 0 = clear, 1 = light cloud, 2 = overcast
                                                      // 3 = light rain, 4 = heavy rain, 5 = storm
  int8_t m_trackTemperature;                          // Track temp. in degrees celsius
  int8_t m_airTemperature;                            // Air temp. in degrees celsius
  uint8_t m_totalLaps;                                // Total number of laps in this race
  uint16_t m_trackLength;                             // Track length in metres
  uint8_t m_sessionType;                              // 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P
                                                      // 5 = Q1, 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ
                                                      // 10 = R, 11 = R2, 12 = R3, 13 = Time Trial
  int8_t m_trackId;                                   // -1 for unknown, see appendix
  uint8_t m_formula;                                  // Formula, 0 = F1 Modern, 1 = F1 Classic, 2 = F2,
                                                      // 3 = F1 Generic, 4 = Beta, 5 = Supercars
                                                      // 6 = Esports, 7 = F2 2021
  uint16_t m_sessionTimeLeft;                         // Time left in session in seconds
  uint16_t m_sessionDuration;                         // Session duration in seconds
  uint8_t m_pitSpeedLimit;                            // Pit speed limit in kilometres per hour
  uint8_t m_gamePaused;                               // Whether the game is paused – network game only
  uint8_t m_isSpectating;                             // Whether the player is spectating
  uint8_t m_spectatorCarIndex;                        // Index of the car being spectated
  uint8_t m_sliProNativeSupport;                      // SLI Pro support, 0 = inactive, 1 = active
  uint8_t m_numMarshalZones;                          // Number of marshal zones to follow
  MarshalZone m_marshalZones[21];                     // List of marshal zones – max 21
  uint8_t m_safetyCarStatus;                          // 0 = no safety car, 1 = full
                                                      // 2 = virtual, 3 = formation lap
  uint8_t m_networkGame;                              // 0 = offline, 1 = online
  uint8_t m_numWeatherForecastSamples;                // Number of weather samples to follow
  WeatherForecastSample m_weatherForecastSamples[56]; // Array of weather forecast samples
  uint8_t m_forecastAccuracy;                         // 0 = Perfect, 1 = Approximate
  uint8_t m_aiDifficulty;                             // AI Difficulty rating – 0-110
  uint32_t m_seasonLinkIdentifier;                    // Identifier for season - persists across saves
  uint32_t m_weekendLinkIdentifier;                   // Identifier for weekend - persists across saves
  uint32_t m_sessionLinkIdentifier;                   // Identifier for session - persists across saves
  uint8_t m_pitStopWindowIdealLap;                    // Ideal lap to pit on for current strategy (player)
  uint8_t m_pitStopWindowLatestLap;                   // Latest lap to pit on for current strategy (player)
  uint8_t m_pitStopRejoinPosition;                    // Predicted position to rejoin at (player)
  uint8_t m_steeringAssist;                           // 0 = off, 1 = on
  uint8_t m_brakingAssist;                            // 0 = off, 1 = low, 2 = medium, 3 = high
  uint8_t m_gearboxAssist;                            // 1 = manual, 2 = manual & suggested gear, 3 = auto
  uint8_t m_pitAssist;                                // 0 = off, 1 = on
  uint8_t m_pitReleaseAssist;                         // 0 = off, 1 = on
  uint8_t m_ERSAssist;                                // 0 = off, 1 = on
  uint8_t m_DRSAssist;                                // 0 = off, 1 = on
  uint8_t m_dynamicRacingLine;                        // 0 = off, 1 = corners only, 2 = full
  uint8_t m_dynamicRacingLineType;                    // 0 = 2D, 1 = 3D
  uint8_t m_gameMode;                                 // Game mode id - see appendix
  uint8_t m_ruleSet;                                  // Ruleset - see appendix
  uint32_t m_timeOfDay;                               // Local time of day - minutes since midnight
  uint8_t m_sessionLength;                            // 0 = None, 2 = Very Short, 3 = Short, 4 = Medium
                                                      // 5 = Medium Long, 6 = Long, 7 = Full
  uint8_t m_speedUnitsLeadPlayer;                     // 0 = MPH, 1 = KPH
  uint8_t m_temperatureUnitsLeadPlayer;               // 0 = Celsius, 1 = Fahrenheit
  uint8_t m_speedUnitsSecondaryPlayer;                // 0 = MPH, 1 = KPH
  uint8_t m_temperatureUnitsSecondaryPlayer;          // 0 = Celsius, 1 = Fahrenheit
  uint8_t m_numSafetyCarPeriods;                      // Number of safety cars called during session
  uint8_t m_numVirtualSafetyCarPeriods;               // Number of virtual safety cars called
  uint8_t m_numRedFlagPeriods;                        // Number of red flags called during session

  unsigned long get(char *buffer)
  {
    unsigned long offset = this->m_header.get(buffer);
    memcpy(&this->m_weather, &buffer[offset], sizeof(this->m_weather));
    offset += sizeof(this->m_weather);
    memcpy(&this->m_trackTemperature, &buffer[offset], sizeof(this->m_trackTemperature));
    this->m_trackTemperature = static_cast<int8_t>(this->m_trackTemperature);
    offset += sizeof(this->m_trackTemperature);
    memcpy(&this->m_airTemperature, &buffer[offset], sizeof(this->m_airTemperature));
    this->m_airTemperature = static_cast<int8_t>(this->m_airTemperature);
    offset += sizeof(this->m_airTemperature);
    memcpy(&this->m_totalLaps, &buffer[offset], sizeof(this->m_totalLaps));
    offset += sizeof(this->m_totalLaps);
    memcpy(&this->m_trackLength, &buffer[offset], sizeof(this->m_trackLength));
    offset += sizeof(this->m_trackLength);
    memcpy(&this->m_sessionType, &buffer[offset], sizeof(this->m_sessionType));
    offset += sizeof(this->m_sessionType);
    memcpy(&this->m_trackId, &buffer[offset], sizeof(this->m_trackId));
    this->m_trackId = static_cast<int8_t>(this->m_trackId);
    offset += sizeof(this->m_trackId);
    memcpy(&this->m_formula, &buffer[offset], sizeof(this->m_formula));
    offset += sizeof(this->m_formula);
    memcpy(&this->m_sessionTimeLeft, &buffer[offset], sizeof(this->m_sessionTimeLeft));
    offset += sizeof(this->m_sessionTimeLeft);
    memcpy(&this->m_sessionDuration, &buffer[offset], sizeof(this->m_sessionDuration));
    offset += sizeof(this->m_sessionDuration);
    memcpy(&this->m_pitSpeedLimit, &buffer[offset], sizeof(this->m_pitSpeedLimit));
    offset += sizeof(this->m_pitSpeedLimit);
    memcpy(&this->m_gamePaused, &buffer[offset], sizeof(this->m_gamePaused));
    offset += sizeof(this->m_gamePaused);
    memcpy(&this->m_isSpectating, &buffer[offset], sizeof(this->m_isSpectating));
    offset += sizeof(this->m_isSpectating);
    memcpy(&this->m_spectatorCarIndex, &buffer[offset], sizeof(this->m_spectatorCarIndex));
    offset += sizeof(this->m_spectatorCarIndex);
    memcpy(&this->m_sliProNativeSupport, &buffer[offset], sizeof(this->m_sliProNativeSupport));
    offset += sizeof(this->m_sliProNativeSupport);
    memcpy(&this->m_numMarshalZones, &buffer[offset], sizeof(this->m_numMarshalZones));
    offset += sizeof(this->m_numMarshalZones);
    for (int i = 0; i < 21; i++)
    {
      offset = offset + sizeof(this->m_marshalZones[i].get(buffer));
    }
    memcpy(&this->m_safetyCarStatus, &buffer[offset], sizeof(this->m_safetyCarStatus));
    offset += sizeof(this->m_safetyCarStatus);
    memcpy(&this->m_networkGame, &buffer[offset], sizeof(this->m_networkGame));
    offset += sizeof(this->m_networkGame);
    memcpy(&this->m_numWeatherForecastSamples, &buffer[offset], sizeof(this->m_numWeatherForecastSamples));
    offset += sizeof(this->m_numWeatherForecastSamples);
    for (int i = 0; i < 56; i++)
    {
      offset = offset + sizeof(this->m_weatherForecastSamples[i].get(buffer));
    }
    memcpy(&this->m_forecastAccuracy, &buffer[offset], sizeof(this->m_forecastAccuracy));
    offset += sizeof(this->m_forecastAccuracy);
    memcpy(&this->m_aiDifficulty, &buffer[offset], sizeof(this->m_aiDifficulty));
    offset += sizeof(this->m_aiDifficulty);
    memcpy(&this->m_seasonLinkIdentifier, &buffer[offset], sizeof(this->m_seasonLinkIdentifier));
    offset += sizeof(this->m_seasonLinkIdentifier);
    memcpy(&this->m_weekendLinkIdentifier, &buffer[offset], sizeof(this->m_weekendLinkIdentifier));
    offset += sizeof(this->m_weekendLinkIdentifier);
    memcpy(&this->m_sessionLinkIdentifier, &buffer[offset], sizeof(this->m_sessionLinkIdentifier));
    offset += sizeof(this->m_sessionLinkIdentifier);
    memcpy(&this->m_pitStopWindowIdealLap, &buffer[offset], sizeof(this->m_pitStopWindowIdealLap));
    offset += sizeof(this->m_pitStopWindowIdealLap);
    memcpy(&this->m_pitStopWindowLatestLap, &buffer[offset], sizeof(this->m_pitStopWindowLatestLap));
    offset += sizeof(this->m_pitStopWindowLatestLap);
    memcpy(&this->m_pitStopRejoinPosition, &buffer[offset], sizeof(this->m_pitStopRejoinPosition));
    offset += sizeof(this->m_pitStopRejoinPosition);
    memcpy(&this->m_steeringAssist, &buffer[offset], sizeof(this->m_steeringAssist));
    offset += sizeof(this->m_steeringAssist);
    memcpy(&this->m_brakingAssist, &buffer[offset], sizeof(this->m_brakingAssist));
    offset += sizeof(this->m_brakingAssist);
    memcpy(&this->m_gearboxAssist, &buffer[offset], sizeof(this->m_gearboxAssist));
    offset += sizeof(this->m_gearboxAssist);
    memcpy(&this->m_pitAssist, &buffer[offset], sizeof(this->m_pitAssist));
    offset += sizeof(this->m_pitAssist);
    memcpy(&this->m_pitReleaseAssist, &buffer[offset], sizeof(this->m_pitReleaseAssist));
    offset += sizeof(this->m_pitReleaseAssist);
    memcpy(&this->m_ERSAssist, &buffer[offset], sizeof(this->m_ERSAssist));
    offset += sizeof(this->m_ERSAssist);
    memcpy(&this->m_DRSAssist, &buffer[offset], sizeof(this->m_DRSAssist));
    offset += sizeof(this->m_DRSAssist);
    memcpy(&this->m_dynamicRacingLine, &buffer[offset], sizeof(this->m_dynamicRacingLine));
    offset += sizeof(this->m_dynamicRacingLine);
    memcpy(&this->m_dynamicRacingLineType, &buffer[offset], sizeof(this->m_dynamicRacingLineType));
    offset += sizeof(this->m_dynamicRacingLineType);
    memcpy(&this->m_gameMode, &buffer[offset], sizeof(this->m_gameMode));
    offset += sizeof(this->m_gameMode);
    memcpy(&this->m_ruleSet, &buffer[offset], sizeof(this->m_ruleSet));
    offset += sizeof(this->m_ruleSet);
    memcpy(&this->m_timeOfDay, &buffer[offset], sizeof(this->m_timeOfDay));
    offset += sizeof(this->m_timeOfDay);
    memcpy(&this->m_sessionLength, &buffer[offset], sizeof(this->m_sessionLength));
    offset += sizeof(this->m_sessionLength);
    memcpy(&this->m_speedUnitsLeadPlayer, &buffer[offset], sizeof(this->m_speedUnitsLeadPlayer));
    offset += sizeof(this->m_speedUnitsLeadPlayer);
    memcpy(&this->m_temperatureUnitsLeadPlayer, &buffer[offset], sizeof(this->m_temperatureUnitsLeadPlayer));
    offset += sizeof(this->m_temperatureUnitsLeadPlayer);
    memcpy(&this->m_speedUnitsSecondaryPlayer, &buffer[offset], sizeof(this->m_speedUnitsSecondaryPlayer));
    offset += sizeof(this->m_speedUnitsSecondaryPlayer);
    memcpy(&this->m_temperatureUnitsSecondaryPlayer, &buffer[offset], sizeof(this->m_temperatureUnitsSecondaryPlayer));
    offset += sizeof(this->m_temperatureUnitsSecondaryPlayer);
    memcpy(&this->m_numSafetyCarPeriods, &buffer[offset], sizeof(this->m_numSafetyCarPeriods));
    offset += sizeof(this->m_numSafetyCarPeriods);
    memcpy(&this->m_numVirtualSafetyCarPeriods, &buffer[offset], sizeof(this->m_numVirtualSafetyCarPeriods));
    offset += sizeof(this->m_numVirtualSafetyCarPeriods);
    memcpy(&this->m_numRedFlagPeriods, &buffer[offset], sizeof(this->m_numRedFlagPeriods));
    offset += sizeof(this->m_numRedFlagPeriods);
    return offset;
  }

  void print()
  {
    std::cout << "PacketSessionData:" << std::endl;
    this->m_header.print();
    std::cout << "  m_weather: " << this->m_weather << std::endl;
    std::cout << "  m_trackTemperature: " << this->m_trackTemperature << std::endl;
    std::cout << "  m_airTemperature: " << this->m_airTemperature << std::endl;
    std::cout << "  m_totalLaps: " << this->m_totalLaps << std::endl;
    std::cout << "  m_trackLength: " << this->m_trackLength << std::endl;
    std::cout << "  m_sessionType: " << this->m_sessionType << std::endl;
    std::cout << "  m_trackId: " << this->m_trackId << std::endl;
    std::cout << "  m_formula: " << this->m_formula << std::endl;
    std::cout << "  m_sessionTimeLeft: " << this->m_sessionTimeLeft << std::endl;
    std::cout << "  m_sessionDuration: " << this->m_sessionDuration << std::endl;
    std::cout << "  m_pitSpeedLimit: " << this->m_pitSpeedLimit << std::endl;
    std::cout << "  m_gamePaused: " << this->m_gamePaused << std::endl;
    std::cout << "  m_isSpectating: " << this->m_isSpectating << std::endl;
    std::cout << "  m_spectatorCarIndex: " << this->m_spectatorCarIndex << std::endl;
    std::cout << "  m_sliProNativeSupport: " << this->m_sliProNativeSupport << std::endl;
    std::cout << "  m_numMarshalZones: " << this->m_numMarshalZones << std::endl;
    for (int i = 0; i < 21; i++)
    {
      std::cout << "  m_marshalZones[" << i << "]:" << std::endl;
      this->m_marshalZones[i].print();
    }
    std::cout << "  m_safetyCarStatus: " << this->m_safetyCarStatus << std::endl;
    std::cout << "  m_networkGame: " << this->m_networkGame << std::endl;
    std::cout << "  m_numWeatherForecastSamples: " << this->m_numWeatherForecastSamples << std::endl;
    for (int i = 0; i < 56; i++)
    {
      std::cout << "  m_weatherForecastSamples[" << i << "]:" << std::endl;
      this->m_weatherForecastSamples[i].print();
    }
    std::cout << "  m_forecastAccuracy: " << this->m_forecastAccuracy << std::endl;
    std::cout << "  m_aiDifficulty: " << this->m_aiDifficulty << std::endl;
    std::cout << "  m_seasonLinkIdentifier: " << this->m_seasonLinkIdentifier << std::endl;
    std::cout << "  m_weekendLinkIdentifier: " << this->m_weekendLinkIdentifier << std::endl;
    std::cout << "  m_sessionLinkIdentifier: " << this->m_sessionLinkIdentifier << std::endl;
    std::cout << "  m_pitStopWindowIdealLap: " << this->m_pitStopWindowIdealLap << std::endl;
    std::cout << "  m_pitStopWindowLatestLap: " << this->m_pitStopWindowLatestLap << std::endl;
    std::cout << "  m_pitStopRejoinPosition: " << this->m_pitStopRejoinPosition << std::endl;
    std::cout << "  m_steeringAssist: " << this->m_steeringAssist << std::endl;
    std::cout << "  m_brakingAssist: " << this->m_brakingAssist << std::endl;
    std::cout << "  m_gearboxAssist: " << this->m_gearboxAssist << std::endl;
    std::cout << "  m_pitAssist: " << this->m_pitAssist << std::endl;
    std::cout << "  m_pitReleaseAssist: " << this->m_pitReleaseAssist << std::endl;
    std::cout << "  m_ERSAssist: " << this->m_ERSAssist << std::endl;
    std::cout << "  m_DRSAssist: " << this->m_DRSAssist << std::endl;
    std::cout << "  m_dynamicRacingLine: " << this->m_dynamicRacingLine << std::endl;
    std::cout << "  m_dynamicRacingLineType: " << this->m_dynamicRacingLineType << std::endl;
    std::cout << "  m_gameMode: " << this->m_gameMode << std::endl;
    std::cout << "  m_ruleSet: " << this->m_ruleSet << std::endl;
    std::cout << "  m_timeOfDay: " << this->m_timeOfDay << std::endl;
    std::cout << "  m_sessionLength: " << this->m_sessionLength << std::endl;
    std::cout << "  m_speedUnitsLeadPlayer: " << this->m_speedUnitsLeadPlayer << std::endl;
    std::cout << "  m_temperatureUnitsLeadPlayer: " << this->m_temperatureUnitsLeadPlayer << std::endl;
    std::cout << "  m_speedUnitsSecondaryPlayer: " << this->m_speedUnitsSecondaryPlayer << std::endl;
    std::cout << "  m_temperatureUnitsSecondaryPlayer: " << this->m_temperatureUnitsSecondaryPlayer << std::endl;
    std::cout << "  m_numSafetyCarPeriods: " << this->m_numSafetyCarPeriods << std::endl;
    std::cout << "  m_numVirtualSafetyCarPeriods: " << this->m_numVirtualSafetyCarPeriods << std::endl;
    std::cout << "  m_numRedFlagPeriods: " << this->m_numRedFlagPeriods << std::endl;
  }
};

#endif