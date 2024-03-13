#ifndef PACKETLOBBYINFODATA_H
#define PACKETLOBBYINFODATA_H

#include <cstdint>
#include <iostream>
#include "PacketHeader.h"
#include "LobbyInfoData.h"

struct PacketLobbyInfoData
{
  PacketHeader m_header; // Header

  // Packet specific data
  uint8_t m_numPlayers; // Number of players in the lobby data
  LobbyInfoData m_lobbyPlayers[22];

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
      memcpy(&this->m_numPlayers, &buffer[offset], sizeof(this->m_numPlayers));
      this->m_numPlayers = static_cast<uint8_t>(this->m_numPlayers);
      offset += sizeof(m_numPlayers);
    }
    if (offset < sizeof(buffer))
    {
      for (int i = 0; i < 22; i++)
      {
        memcpy(&this->m_lobbyPlayers[i], &buffer[offset], sizeof(this->m_lobbyPlayers[i]));
        offset = offset + sizeof(this->m_lobbyPlayers[i]);
      }
    }
    return offset;
  }

  void print()
  {
    std::cout << "PacketLobbyInfoData:" << std::endl;
    std::cout << "  m_header: " << std::endl;
    this->m_header.print();
    std::cout << "  m_numPlayers: " << this->m_numPlayers << std::endl;
    std::cout << "  m_lobbyPlayers[22]: " << std::endl;
    for (int i = 0; i < 22; i++)
    {
      this->m_lobbyPlayers[i].print();
    }
  }
};

#endif
