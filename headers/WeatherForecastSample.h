#ifndef WEATHERFORECASTSAMPLE_H
#define WEATHERFORECASTSAMPLE_H

#include <cstdint>
#include <iostream>

struct WeatherForecastSample
{
  uint8_t m_sessionType;           // 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P, 5 = Q1
                                   // 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ, 10 = R, 11 = R2
                                   // 12 = R3, 13 = Time Trial
  uint8_t m_timeOffset;            // Time in minutes the forecast is for
  uint8_t m_weather;               // Weather - 0 = clear, 1 = light cloud, 2 = overcast
                                   // 3 = light rain, 4 = heavy rain, 5 = storm
  int8_t m_trackTemperature;       // Track temp. in degrees Celsius
  int8_t m_trackTemperatureChange; // Track temp. change – 0 = up, 1 = down, 2 = no change
  int8_t m_airTemperature;         // Air temp. in degrees celsius
  int8_t m_airTemperatureChange;   // Air temp. change – 0 = up, 1 = down, 2 = no change
  uint8_t m_rainPercentage;        // Rain percentage (0-100)

  unsigned long get(char *buffer)
  {
    unsigned long offset = 0;
    memcpy(&this->m_sessionType, &buffer[offset], sizeof(this->m_sessionType));
    offset += sizeof(this->m_sessionType);
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_timeOffset, &buffer[offset], sizeof(this->m_timeOffset));
      offset += sizeof(this->m_timeOffset);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_weather, &buffer[offset], sizeof(this->m_weather));
      offset += sizeof(this->m_weather);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_trackTemperature, &buffer[offset], sizeof(this->m_trackTemperature));
      this->m_trackTemperature = static_cast<int8_t>(this->m_trackTemperature);
      offset += sizeof(this->m_trackTemperature);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_trackTemperatureChange, &buffer[offset], sizeof(this->m_trackTemperatureChange));
      this->m_trackTemperatureChange = static_cast<int8_t>(this->m_trackTemperatureChange);
      offset += sizeof(this->m_trackTemperatureChange);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_airTemperature, &buffer[offset], sizeof(this->m_airTemperature));
      this->m_airTemperature = static_cast<int8_t>(this->m_airTemperature);
      offset += sizeof(this->m_airTemperature);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_airTemperatureChange, &buffer[offset], sizeof(this->m_airTemperatureChange));
      this->m_airTemperatureChange = static_cast<int8_t>(this->m_airTemperatureChange);
      offset += sizeof(this->m_airTemperatureChange);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_rainPercentage, &buffer[offset], sizeof(this->m_rainPercentage));
      offset += sizeof(this->m_rainPercentage);
    }
    return offset;
  }

  void print()
  {
    std::cout << "WeatherForecastSample:" << std::endl;
    std::cout << "  m_sessionType: " << this->m_sessionType << std::endl;
    std::cout << "  m_timeOffset: " << this->m_timeOffset << std::endl;
    std::cout << "  m_weather: " << this->m_weather << std::endl;
    std::cout << "  m_trackTemperature: " << this->m_trackTemperature << std::endl;
    std::cout << "  m_trackTemperatureChange: " << this->m_trackTemperatureChange << std::endl;
    std::cout << "  m_airTemperature: " << this->m_airTemperature << std::endl;
    std::cout << "  m_airTemperatureChange: " << this->m_airTemperatureChange << std::endl;
    std::cout << "  m_rainPercentage: " << this->m_rainPercentage << std::endl;
  }
};

#endif