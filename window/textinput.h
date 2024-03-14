#ifndef MYDESMOS_TEXTINPUT_H
#define MYDESMOS_TEXTINPUT_H
#include "Button.h"

class Textinput : public Button {
  using Button::Button;
  const sf::Uint32 m_style = style::none;
  bool textinputing = false;

public:
  void update(sf::Event& e, sf::RenderWindow& window) override;
};


#endif //MYDESMOS_TEXTINPUT_H
