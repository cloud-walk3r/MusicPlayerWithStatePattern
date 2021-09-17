#pragma once

#include "playerstate.h"

class PausedState : public PlayerState
{
public:
  PausedState(MusicPlayer* p);

  void process() override;
  std::string name() const override;
};
