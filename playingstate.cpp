#include "playingstate.h"
#include "musicplayer.h"

#include <iostream>

PlayingState::PlayingState(MusicPlayer* p)
  : PlayerState{ p }
{}

void PlayingState::process()
{
  std::cout << "Player is " << name() << "...\n";
  std::cout << "-----------------------------\n";

  char c = ' ';
  while ( c == ' ' ) {
    std::cout << "  Pause [P]  Stop [S]  Quit [Q]\n";
    std::cout << "  Choice: ";
    std::cin >> c;

    switch ( toupper(c) ) {
      case 'P':
        player_->changeState(PlayerState::Type::PAUSED);
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

std::string PlayingState::name() const
{
  return std::string{ "PLAYING" };
}
