#pragma once

#include "playerstate.h"

#include <map>

class MusicPlayer
{
public:
  MusicPlayer();
  ~MusicPlayer();

  void run();
  void close();
  void changeState(const PlayerState::Type);

private:
  std::map<PlayerState::Type, PlayerState*> states_;
  PlayerState* currentState_;
};
