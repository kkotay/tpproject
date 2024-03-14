#include "../textinput.h"


void Textinput::update(sf::Event& e, sf::RenderWindow& window) {
  m_size = sf::Vector2f(m_text.getGlobalBounds().width * 1.5f, m_text.getGlobalBounds().height * 1.75f);
  m_button = sf::RectangleShape(m_size);
  m_button.setFillColor(m_bgNormal);
  m_button.setOutlineColor(m_border);
  m_button.setOutlineThickness(m_borderThickness);
  m_button.setOrigin(m_button.getGlobalBounds().width/2, m_button.getGlobalBounds().height/2);
  m_button.setPosition(m_position);
  m_text.setOrigin(m_text.getGlobalBounds().width/2, m_text.getGlobalBounds().height/2);
  sf::Vector2f textPosition = sf::Vector2f(m_button.getPosition().x, m_button.getPosition().y - m_button.getGlobalBounds().height/4);
  m_text.setPosition(textPosition);
  m_text.setColor(m_textNormal);
  m_shadow.setOrigin(m_shadow.getGlobalBounds().width/2, m_shadow.getGlobalBounds().height/2);
  m_shadow.setPosition(m_text.getPosition().x + 3.f, m_text.getPosition().y + 3.f);
  m_shadow.setColor(sf::Color(0,0,0));

  //perform updates for user mouse interactions
  sf::Vector2i m_mousePosition = sf::Mouse::getPosition(window);

  bool mouseInButton = m_mousePosition.x >= m_button.getPosition().x - m_button.getGlobalBounds().width/2 &&
                       m_mousePosition.x <= m_button.getPosition().x + m_button.getGlobalBounds().width/2 &&
                       m_mousePosition.y >= m_button.getPosition().y - m_button.getGlobalBounds().height/2 &&
                       m_mousePosition.y <= m_button.getPosition().y + m_button.getGlobalBounds().height/2;

  if (e.type == sf::Event::KeyPressed && textinputing) {
    sf::String str = m_text.getString();
    str += sf::Keyboard::getDescription(e.key.scancode);
    setText(str);
  }

  if (e.type == sf::Event::MouseButtonPressed)
  {
    switch(e.mouseButton.button)
    {
      case sf::Mouse::Left:
      {
        if(mouseInButton)
        {
          m_btnstate = state::clicked;
        }

        else
        {
          m_btnstate = state::normal;
        }
      }
        break;
    }
  }

  if (e.type == sf::Event::MouseButtonReleased)
  {
    switch(e.mouseButton.button)
    {
      case sf::Mouse::Left:
      {
        if(mouseInButton)
        {
          m_btnstate = state::hovered;
        }

        else
        {
          m_btnstate = state::normal;
        }
      }
    }
  }

  switch(m_btnstate)
  {
    case state::normal:
    {
      m_button.setFillColor(m_bgNormal);
      m_text.setColor(m_textNormal);
    }
      break;

    case state::hovered:
    {
      m_button.setFillColor(m_bgHover);
      m_text.setColor(m_textHover);
    }
      break;

    case state::clicked:
    {
      m_button.setFillColor(m_bgClicked);
      m_text.setColor(m_textClicked);
      textinputing = true;
    }
      break;
  }
}