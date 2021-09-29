#include "stoppedstate.h"
#include "musicplayer.h"

#include <iostream>

StoppedState::StoppedState(MusicPlayer* p)
  : PlayerState{ p }
{}

void StoppedState::process()
{
  std::cout << "Player is " << name() << "...\n";
  std::cout << "-----------------------------\n";

  char c = ' ';
  while ( c == ' ' ) {
    std::cout << "  Play [P]  Quit [Q]\n";
    std::cout << "  Choice: ";
    std::cin >> c;

    switch ( toupper(c) ) {
      case 'P':
        player_->changeState(PlayerState::Type::PLAYING);
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

std::string StoppedState::name() const
{
  return std::string{ "STOPPED" };
}
