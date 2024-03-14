#include <SFML/Graphics.hpp>
#include "./window/Button.h"
#include "./window/textinput.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800,600,32), "Dacha", sf::Style::Default);


  sf::Event e;
  bool running = true;
  while(running)
  {
    while(window.pollEvent(e))
    {
      if(e.type == sf::Event::Closed)
      {
        window.close();
        return 0;
      }
    }
    window.clear(sf::Color::White);
    window.display();
  }
  return 0;
}