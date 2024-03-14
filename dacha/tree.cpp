#include "Tree.h"

#include <utility>

Tree::Tree() {
  figure = new geometry::Circle();
}

Tree::Tree(geometry::Point& pon, geometry::Circle& circ, treetype::type type) {
  figure = &circ;
  pos_ = pon;
  type_ = type;
}

void Tree::setSize(int64_t) {

}

void Tree::setPosition(geometry::Point) {

}

Tree::~Tree() {

}

void Tree::update() {

}

void Tree::setColor(sf::Color) {

}


