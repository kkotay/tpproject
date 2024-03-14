#include "Tree.h"

#include <utility>

Tree::Tree() {
  figure = new sf::CircleShape();
}

Tree::Tree(sf::Vector2<int64_t> pon, sf::CircleShape& circ, treetype::type type) {
  figure = &circ;
  pos_ = pon;
  type_ = type;
}

void Tree::setSize(int64_t) {

}

void Tree::setPosition(sf::Vector2<int64_t>) {

}

Tree::~Tree() {

}

void Tree::update() {

}

void Tree::setColor(sf::Color) {

}


