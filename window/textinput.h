#ifndef MYDESMOS_TEXTINPUT_H
#define MYDESMOS_TEXTINPUT_H
#include "Button.h"

class Textinput : public Button {
  using Button::Button;
  const sf::Uint32 m_style = style::none;
  bool textinputing = false;
  sf::Color m_textNormal = sf::Color(0,0,0);
  sf::Color m_textHover = sf::Color(0,0,0);
  sf::Color m_textClicked = sf::Color(0,0,0);
  sf::Color m_bgNormal = sf::Color(0,0,0,100);
  sf::Color m_bgHover = sf::Color(100,100,100,100);
  sf::Color m_bgClicked = sf::Color(150,150,150);
  sf::Color m_border = sf::Color(255,255,255,100);

public:
  void update(sf::Event& e, sf::RenderWindow& window) override;
};


#endif //MYDESMOS_TEXTINPUT_H
