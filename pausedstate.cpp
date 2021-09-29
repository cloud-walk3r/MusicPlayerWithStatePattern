#include "pausedstate.h"
#include "musicplayer.h"

#include <iostream>

PausedState::PausedState(MusicPlayer* p)
  : PlayerState{ p }
{}

void PausedState::process()
{
  std::cout << "Player is " << name() << "...\n";
  std::cout << "-----------------------------\n";

  char c = ' ';
  while ( c == ' ' ) {
    std::cout << "  Play [P]  Stop [S]  Quit [Q]\n";
    std::cout << "  Choice: ";
    std::cin >> c;

    switch ( toupper(c) ) {
      case 'P':
        player_->changeState(PlayerState::Type::PLAYING);
        break;
      case 'S':
        player_->changeState(PlayerState::Type::STOPPED);
        break;
      case 'Q':
        player_->close();
        break;
      default:
        c = ' ';
        break;
    }
  }
  std::cout << "\n\n";
}

std::string PausedState::name() const
{
  return std::string{ "PAUSED" };
}
