#pragma once

#include "playerstate.h"

class StoppedState : public PlayerState
{
public:
  StoppedState(MusicPlayer* p);

  void process() override;
  std::string name() const override;
};
