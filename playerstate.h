#pragma once

#include <string>

class MusicPlayer;

/** Abstract class for music player state
 */
class PlayerState
{
public:
  enum class Type
  {
    STOPPED,
    PLAYING,
    PAUSED
  };

  PlayerState(MusicPlayer* p)
    : player_{ p }
  {}
  virtual ~PlayerState() = default;

  virtual void process() = 0;
  virtual std::string name() const = 0;

protected:
  MusicPlayer* player_;
};
