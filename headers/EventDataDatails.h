#ifndef EVENTDATADETAILS_H
#define EVENTDATADETAILS_H

#include <cstdint>
#include <iostream>

union EventDataDetails
{
  struct
  {
    uint32_t buttonStatus; // Bit flags specifying which buttons are being pressed
                           // currently - see appendices

    unsigned long get(char *buffer)
    {
      unsigned long offset = 0;
      if (offset < sizeof(buffer))
      {
        memcpy(&this->buttonStatus, &buffer[offset], sizeof(this->buttonStatus));
        this->buttonStatus = static_cast<uint32_t>(this->buttonStatus);
        offset += sizeof(buttonStatus);
      }
      return offset;
    }

    void print()
    {
      std::cout << "Buttons:" << std::endl;
      std::cout << "  buttonStatus: " << this->buttonStatus << std::endl;
    }
  } Buttons;

  struct
  {
    uint8_t vehicleIdx; // Vehicle index of the vehicle serving drive through

    unsigned long get(char *buffer)
    {
      unsigned long offset = 0;
      if (offset < sizeof(buffer))
      {
        memcpy(&this->vehicleIdx, &buffer[offset], sizeof(this->vehicleIdx));
        this->vehicleIdx = static_cast<uint8_t>(this->vehicleIdx);
        offset += sizeof(vehicleIdx);
      }
      return offset;
    }

    void print()
    {
      std::cout << "DriveThroughPenaltyServed:" << std::endl;
      std::cout << "  vehicleIdx: " << this->vehicleIdx << std::endl;
    }
  } DriveThroughPenaltyServed;

  struct
  {
    uint8_t vehicleIdx; // Vehicle index of car achieving fastest lap
    float lapTime;      // Lap time is in seconds

    unsigned long get(char *buffer)
    {
      unsigned long offset = 0;
      if (offset < sizeof(buffer))
      {
        memcpy(&this->vehicleIdx, &buffer[offset], sizeof(this->vehicleIdx));
        this->vehicleIdx = static_cast<uint8_t>(this->vehicleIdx);
        offset += sizeof(vehicleIdx);
      }
      if (offset < sizeof(buffer))
      {
        memcpy(&this->lapTime, &buffer[offset], sizeof(this->lapTime));
        offset += sizeof(lapTime);
      }
      return offset;
    }

    void print()
    {
      std::cout << "FastestLap:" << std::endl;
      std::cout << "  vehicleIdx: " << this->vehicleIdx << std::endl;
      std::cout << "  lapTime: " << this->lapTime << std::endl;
    }
  } FastestLap;

  struct
  {
    uint32_t flashbackFrameIdentifier; // Frame identifier flashed back to
    float flashbackSessionTime;        // Session time flashed back to

    unsigned long get(char *buffer)
    {
      unsigned long offset = 0;
      if (offset < sizeof(buffer))
      {
        memcpy(&this->flashbackFrameIdentifier, &buffer[offset], sizeof(this->flashbackFrameIdentifier));
        this->flashbackFrameIdentifier = static_cast<uint32_t>(this->flashbackFrameIdentifier);
        offset += sizeof(flashbackFrameIdentifier);
      }
      if (offset < sizeof(buffer))
      {
        memcpy(&this->flashbackSessionTime, &buffer[offset], sizeof(this->flashbackSessionTime));
        offset += sizeof(flashbackSessionTime);
      }
      return offset;
    }

    void print()
    {
      std::cout << "Flashback:" << std::endl;
      std::cout << "  flashbackFrameIdentifier: " << this->flashbackFrameIdentifier << std::endl;
      std::cout << "  flashbackSessionTime: " << this->flashbackSessionTime << std::endl;
    }
  } Flashback;

  struct
  {
    uint8_t overtakingVehicleIdx;     // Vehicle index of the vehicle overtaking
    uint8_t beingOvertakenVehicleIdx; // Vehicle index of the vehicle being overtaken

    unsigned long get(char *buffer)
    {
      unsigned long offset = 0;
      if (offset < sizeof(buffer))
      {
        memcpy(&this->overtakingVehicleIdx, &buffer[offset], sizeof(this->overtakingVehicleIdx));
        this->overtakingVehicleIdx = static_cast<uint8_t>(this->overtakingVehicleIdx);
        offset += sizeof(overtakingVehicleIdx);
      }
      if (offset < sizeof(buffer))
      {
        memcpy(&this->beingOvertakenVehicleIdx, &buffer[offset], sizeof(this->beingOvertakenVehicleIdx));
        this->beingOvertakenVehicleIdx = static_cast<uint8_t>(this->beingOvertakenVehicleIdx);
        offset += sizeof(beingOvertakenVehicleIdx);
      }
      return offset;
    }

    void print()
    {
      std::cout << "Overtake:" << std::endl;
      std::cout << "  overtakingVehicleIdx: " << this->overtakingVehicleIdx << std::endl;
      std::cout << "  beingOvertakenVehicleIdx: " << this->beingOvertakenVehicleIdx << std::endl;
    }
  } Overtake;

  struct
  {
    uint8_t penaltyType;      // Penalty type – see Appendices
    uint8_t infringementType; // Infringement type – see Appendices
    uint8_t vehicleIdx;       // Vehicle index of the car the penalty is applied to
    uint8_t otherVehicleIdx;  // Vehicle index of the other car involved
    uint8_t time;             // Time gained, or time spent doing action in seconds
    uint8_t lapNum;           // Lap the penalty occurred on
    uint8_t placesGained;     // Number of places gained by this

    unsigned long get(char *buffer)
    {
      unsigned long offset = 0;
      if (offset < sizeof(buffer))
      {
        memcpy(&this->penaltyType, &buffer[offset], sizeof(this->penaltyType));
        this->penaltyType = static_cast<uint8_t>(this->penaltyType);
        offset += sizeof(penaltyType);
      }
      if (offset < sizeof(buffer))
      {
        memcpy(&this->infringementType, &buffer[offset], sizeof(this->infringementType));
        this->infringementType = static_cast<uint8_t>(this->infringementType);
        offset += sizeof(infringementType);
      }
      if (offset < sizeof(buffer))
      {
        memcpy(&this->vehicleIdx, &buffer[offset], sizeof(this->vehicleIdx));
        this->vehicleIdx = static_cast<uint8_t>(this->vehicleIdx);
        offset += sizeof(vehicleIdx);
      }
      if (offset < sizeof(buffer))
      {
        memcpy(&this->otherVehicleIdx, &buffer[offset], sizeof(this->otherVehicleIdx));
        this->otherVehicleIdx = static_cast<uint8_t>(this->otherVehicleIdx);
        offset += sizeof(otherVehicleIdx);
      }
      if (offset < sizeof(buffer))
      {
        memcpy(&this->time, &buffer[offset], sizeof(this->time));
        this->time = static_cast<uint8_t>(this->time);
        offset += sizeof(time);
      }
      if (offset < sizeof(buffer))
      {
        memcpy(&this->lapNum, &buffer[offset], sizeof(this->lapNum));
        this->lapNum = static_cast<uint8_t>(this->lapNum);
        offset += sizeof(lapNum);
      }
      if (offset < sizeof(buffer))
      {
        memcpy(&this->placesGained, &buffer[offset], sizeof(this->placesGained));
        this->placesGained = static_cast<uint8_t>(this->placesGained);
        offset += sizeof(placesGained);
      }
      return offset;
    }

    void print()
    {
      std::cout << "Penalty:" << std::endl;
      std::cout << "  penaltyType: " << this->penaltyType << std::endl;
      std::cout << "  infringementType: " << this->infringementType << std::endl;
      std::cout << "  vehicleIdx: " << this->vehicleIdx << std::endl;
      std::cout << "  otherVehicleIdx: " << this->otherVehicleIdx << std::endl;
      std::cout << "  time: " << this->time << std::endl;
      std::cout << "  lapNum: " << this->lapNum << std::endl;
      std::cout << "  placesGained: " << this->placesGained << std::endl;
    }
  } Penalty;

  struct
  {
    uint8_t vehicleIdx; // Vehicle index of the race winner

    unsigned long get(char *buffer)
    {
      unsigned long offset = 0;
      if (offset < sizeof(buffer))
      {
        memcpy(&this->vehicleIdx, &buffer[offset], sizeof(this->vehicleIdx));
        this->vehicleIdx = static_cast<uint8_t>(this->vehicleIdx);
        offset += sizeof(vehicleIdx);
      }
      return offset;
    }

    void print()
    {
      std::cout << "RaceWinner:" << std::endl;
      std::cout << "  vehicleIdx: " << this->vehicleIdx << std::endl;
    }
  } RaceWinner;

  struct
  {
    uint8_t vehicleIdx; // Vehicle index of car retiring

    unsigned long get(char *buffer)
    {
      unsigned long offset = 0;
      if (offset < sizeof(buffer))
      {
        memcpy(&this->vehicleIdx, &buffer[offset], sizeof(this->vehicleIdx));
        this->vehicleIdx = static_cast<uint8_t>(this->vehicleIdx);
        offset += sizeof(vehicleIdx);
      }
      return offset;
    }

    void print()
    {
      std::cout << "Retirement:" << std::endl;
      std::cout << "  vehicleIdx: " << this->vehicleIdx << std::endl;
    }
  } Retirement;

  struct
  {
    uint8_t vehicleIdx;                 // Vehicle index of the vehicle triggering speed trap
    float speed;                        // Top speed achieved in kilometres per hour
    uint8_t isOverallFastestInSession;  // Overall fastest speed in session = 1, otherwise 0
    uint8_t isDriverFastestInSession;   // Fastest speed for driver in session = 1, otherwise 0
    uint8_t fastestVehicleIdxInSession; // Vehicle index of the vehicle that is the fastest
                                        // in this session
    float fastestSpeedInSession;        // Speed of the vehicle that is the fastest
                                        // in this session

    unsigned long get(char *buffer)
    {
      unsigned long offset = 0;
      if (offset < sizeof(buffer))
      {
        memcpy(&this->vehicleIdx, &buffer[offset], sizeof(this->vehicleIdx));
        this->vehicleIdx = static_cast<uint8_t>(this->vehicleIdx);
        offset += sizeof(vehicleIdx);
      }
      if (offset < sizeof(buffer))
      {
        memcpy(&this->speed, &buffer[offset], sizeof(this->speed));
        offset += sizeof(speed);
      }
      if (offset < sizeof(buffer))
      {
        memcpy(&this->isOverallFastestInSession, &buffer[offset], sizeof(this->isOverallFastestInSession));
        this->isOverallFastestInSession = static_cast<uint8_t>(this->isOverallFastestInSession);
        offset += sizeof(isOverallFastestInSession);
      }
      if (offset < sizeof(buffer))
      {
        memcpy(&this->isDriverFastestInSession, &buffer[offset], sizeof(this->isDriverFastestInSession));
        this->isDriverFastestInSession = static_cast<uint8_t>(this->isDriverFastestInSession);
        offset += sizeof(isDriverFastestInSession);
      }
      if (offset < sizeof(buffer))
      {
        memcpy(&this->fastestVehicleIdxInSession, &buffer[offset], sizeof(this->fastestVehicleIdxInSession));
        this->fastestVehicleIdxInSession = static_cast<uint8_t>(this->fastestVehicleIdxInSession);
        offset += sizeof(fastestVehicleIdxInSession);
      }
      if (offset < sizeof(buffer))
      {
        memcpy(&this->fastestSpeedInSession, &buffer[offset], sizeof(this->fastestSpeedInSession));
        offset += sizeof(fastestSpeedInSession);
      }
      return offset;
    }

    void print()
    {
      std::cout << "SpeedTrap:" << std::endl;
      std::cout << "  vehicleIdx: " << this->vehicleIdx << std::endl;
      std::cout << "  speed: " << this->speed << std::endl;
      std::cout << "  isOverallFastestInSession: " << this->isOverallFastestInSession << std::endl;
      std::cout << "  isDriverFastestInSession: " << this->isDriverFastestInSession << std::endl;
      std::cout << "  fastestVehicleIdxInSession: " << this->fastestVehicleIdxInSession << std::endl;
      std::cout << "  fastestSpeedInSession: " << this->fastestSpeedInSession << std::endl;
    }
  } SpeedTrap;

  struct
  {
    uint8_t numLights; // Number of lights showing

    unsigned long get(char *buffer)
    {
      unsigned long offset = 0;
      if (offset < sizeof(buffer))
      {
        memcpy(&this->numLights, &buffer[offset], sizeof(this->numLights));
        this->numLights = static_cast<uint8_t>(this->numLights);
        offset += sizeof(numLights);
      }
      return offset;
    }

    void print()
    {
      std::cout << "StartLIghts:" << std::endl;
      std::cout << "  numLights: " << this->numLights << std::endl;
    }
  } StartLIghts;

  struct
  {
    uint8_t vehicleIdx; // Vehicle index of the vehicle serving stop go

    unsigned long get(char *buffer)
    {
      unsigned long offset = 0;
      if (offset < sizeof(buffer))
      {
        memcpy(&this->vehicleIdx, &buffer[offset], sizeof(this->vehicleIdx));
        this->vehicleIdx = static_cast<uint8_t>(this->vehicleIdx);
        offset += sizeof(vehicleIdx);
      }
      return offset;
    }

    void print()
    {
      std::cout << "StopGoPenaltyServed:" << std::endl;
      std::cout << "  vehicleIdx: " << this->vehicleIdx << std::endl;
    }
  } StopGoPenaltyServed;

  struct
  {
    uint8_t vehicleIdx; // Vehicle index of team mate

    unsigned long get(char *buffer)
    {
      unsigned long offset = 0;
      if (offset < sizeof(buffer))
      {
        memcpy(&this->vehicleIdx, &buffer[offset], sizeof(this->vehicleIdx));
        this->vehicleIdx = static_cast<uint8_t>(this->vehicleIdx);
        offset += sizeof(vehicleIdx);
      }
      return offset;
    }

    void print()
    {
      std::cout << "TeamMateInPits:" << std::endl;
      std::cout << "  vehicleIdx: " << this->vehicleIdx << std::endl;
    }
  } TeamMateInPits;
};

#endif