#ifndef DACHA_TREEFACTORY_H
#define DACHA_TREEFACTORY_H
#include "cedarfactory.cpp"
#include "applefactory.cpp"
#include "firfactory.cpp"

enum treetype {
  cedar,
  fir,
  appletree
};

class TreeFactory {
 protected:
  CedarFactory cedarmaker;
  AppleFactory applemaker;
  FirFactory firmaker;
 public:
  Tree &CreateTree(treetype, sf::Vector2f &);

  template<class T>
  std::vector <T> &GetTrees(treetype = fir);
};
#endif