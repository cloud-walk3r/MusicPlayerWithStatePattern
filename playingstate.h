#pragma once

#include "playerstate.h"

class PlayingState : public PlayerState
{
public:
  PlayingState(MusicPlayer* p);

  void process() override;
  std::string name() const override;
};
