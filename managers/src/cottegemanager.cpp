#include "cottegemanager.h"

CottageManager::CottageManager(sf::RenderWindow &window) : window_(window) {}

void CottageManager::Command() {
  std::string command;
  std::cin >> command;
  if (command == "create tree") {

  } else if (command == "create house") {

  } else if (command == "help") {

  } else if (command == "show above") {

  } else if (command == "show front") {

  } else if (command == "exit") {

  }
}