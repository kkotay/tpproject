#ifndef DACHA_TREEFACTORY_H
#define DACHA_TREEFACTORY_H
#include "cedarfactory.h"
#include "applefactory.h"
#include "firfactory.h"

enum treetype {
  cedar,
  fir,
  appletree
};

class TreeFactory {
 protected:
  std::vector<Object*> trees_;
  CedarFactory cedarmaker;
  AppleFactory applemaker;
  FirFactory firmaker;
 public:
  void CreateTree(treetype, sf::Vector2f&);
  std::vector<Object*>& GetTrees();
  void Clear();
};
#endif