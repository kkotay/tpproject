#ifndef MYDESMOS_BUTTON_H
#define MYDESMOS_BUTTON_H
#include <iostream>
#include <SFML/Graphics.hpp>

namespace style {
  enum
  {
    none = 0,
    save = 1,
    cancel = 2,
    clean = 3,
  };
};

namespace state
{
  enum
  {
    normal = 0,
    hovered = 1,
    clicked = 2
  };
};

class Button : public sf::Drawable
{
public:
  Button();
  Button(const std::string& s, sf::Font& font, sf::Vector2f position, sf::Uint32 style);

  ~Button() override;

  void setColorTextNormal(sf::Color text){m_textNormal = text;};
  void setColorTextHover(sf::Color text){m_textHover = text;};
  void setColorTextClicked(sf::Color text){m_textClicked = text;};
  void setColorNormal(sf::Color bgNormal){m_bgNormal = bgNormal;};
  void setColorHover(sf::Color bgHover){m_bgHover = bgHover;};
  void setColorClicked(sf::Color bgClicked){m_bgClicked = bgClicked;};
  void setBorderColor(sf::Color border){m_border = border;};
  void setBorderThickness(float t){m_borderThickness = t;};
  void setPosition(sf::Vector2f position){m_position = position;};
  void setSize(unsigned int size);
  void setText(const std::string& s) {
    m_text.setString(s);
    m_shadow = m_text;
  };
  virtual void setStyle(sf::Uint32 style);
  void setFont(sf::Font& font);

  sf::Vector2f getPosition(){return m_position;};
  sf::Vector2f getDimensions(){return {m_button.getGlobalBounds().width, m_button.getGlobalBounds().height};};
  sf::Uint32 getState() const{return m_btnstate;};

  virtual void update(sf::Event& e, sf::RenderWindow& window);

protected:
  void draw(sf::RenderTarget& target,sf::RenderStates states) const override;

  sf::Color m_bgNormal;
  sf::Color m_bgHover;
  sf::Color m_bgClicked;
  sf::Color m_textNormal;
  sf::Color m_textHover;
  sf::Color m_textClicked;
  sf::Color m_border;

  float m_borderThickness;
  sf::Vector2f m_size;
  sf::Vector2f m_position;
  sf::Uint32 m_style;
  sf::Uint32 m_btnstate;

  sf::RectangleShape m_button;
  sf::Font m_font;
  unsigned int m_fontSize;
  sf::Text m_text;
  sf::Text m_shadow;
};
#endif
