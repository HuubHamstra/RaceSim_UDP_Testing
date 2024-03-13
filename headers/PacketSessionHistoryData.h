#ifndef PACKETSESSIONHISTORYDATA_H
#define PACKETSESSIONHISTORYDATA_H

#include <cstdint>
#include <iostream>
#include "PacketHeader.h"
#include "LapHistoryData.h"
#include "TyreStintHistoryData.h"

struct PacketSessionHistoryData
{
  PacketHeader m_header; // Header

  uint8_t m_carIdx;        // Index of the car this lap data relates to
  uint8_t m_numLaps;       // Num laps in the data (including current partial lap)
  uint8_t m_numTyreStints; // Number of tyre stints in the data

  uint8_t m_bestLapTimeLapNum; // Lap the best lap time was achieved on
  uint8_t m_bestSector1LapNum; // Lap the best Sector 1 time was achieved on
  uint8_t m_bestSector2LapNum; // Lap the best Sector 2 time was achieved on
  uint8_t m_bestSector3LapNum; // Lap the best Sector 3 time was achieved on

  LapHistoryData m_lapHistoryData[100]; // 100 laps of data max
  TyreStintHistoryData m_tyreStintsHistoryData[8];

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
      memcpy(&this->m_carIdx, &buffer[offset], sizeof(this->m_carIdx));
      this->m_carIdx = static_cast<uint8_t>(this->m_carIdx);
      offset += sizeof(m_carIdx);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_numLaps, &buffer[offset], sizeof(this->m_numLaps));
      this->m_numLaps = static_cast<uint8_t>(this->m_numLaps);
      offset += sizeof(m_numLaps);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_numTyreStints, &buffer[offset], sizeof(this->m_numTyreStints));
      this->m_numTyreStints = static_cast<uint8_t>(this->m_numTyreStints);
      offset += sizeof(m_numTyreStints);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_bestLapTimeLapNum, &buffer[offset], sizeof(this->m_bestLapTimeLapNum));
      this->m_bestLapTimeLapNum = static_cast<uint8_t>(this->m_bestLapTimeLapNum);
      offset += sizeof(m_bestLapTimeLapNum);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_bestSector1LapNum, &buffer[offset], sizeof(this->m_bestSector1LapNum));
      this->m_bestSector1LapNum = static_cast<uint8_t>(this->m_bestSector1LapNum);
      offset += sizeof(m_bestSector1LapNum);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_bestSector2LapNum, &buffer[offset], sizeof(this->m_bestSector2LapNum));
      this->m_bestSector2LapNum = static_cast<uint8_t>(this->m_bestSector2LapNum);
      offset += sizeof(m_bestSector2LapNum);
    }
    if (offset < sizeof(buffer))
    {
      memcpy(&this->m_bestSector3LapNum, &buffer[offset], sizeof(this->m_bestSector3LapNum));
      this->m_bestSector3LapNum = static_cast<uint8_t>(this->m_bestSector3LapNum);
      offset += sizeof(m_bestSector3LapNum);
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 100; i++)
      {
        memcpy(&this->m_lapHistoryData[i], &buffer[offset], sizeof(this->m_lapHistoryData[i]));
        offset = offset + sizeof(this->m_lapHistoryData[i]);
      }
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 8; i++)
      {
        memcpy(&this->m_tyreStintsHistoryData[i], &buffer[offset], sizeof(this->m_tyreStintsHistoryData[i]));
        offset = offset + sizeof(this->m_tyreStintsHistoryData[i]);
      }
    }
    return offset;
  }

  void print()
  {
    std::cout << "PacketSessionHistoryData:" << std::endl;
    std::cout << "  m_header: " << std::endl;
    this->m_header.print();
    std::cout << "  m_carIdx: " << this->m_carIdx << std::endl;
    std::cout << "  m_numLaps: " << this->m_numLaps << std::endl;
    std::cout << "  m_numTyreStints: " << this->m_numTyreStints << std::endl;
    std::cout << "  m_bestLapTimeLapNum: " << this->m_bestLapTimeLapNum << std::endl;
    std::cout << "  m_bestSector1LapNum: " << this->m_bestSector1LapNum << std::endl;
    std::cout << "  m_bestSector2LapNum: " << this->m_bestSector2LapNum << std::endl;
    std::cout << "  m_bestSector3LapNum: " << this->m_bestSector3LapNum << std::endl;
    std::cout << "  m_lapHistoryData[100]: " << std::endl;
    for (int i = 0; i < 100; i++)
    {
      this->m_lapHistoryData[i].print();
    }
    std::cout << "  m_tyreStintsHistoryData[8]: " << std::endl;
    for (int i = 0; i < 8; i++)
    {
      std::cout << "  m_tyreStintsHistoryData[" << i << "]: " << std::endl;
      this->m_tyreStintsHistoryData[i].print();
    }
  }
};

#endif
