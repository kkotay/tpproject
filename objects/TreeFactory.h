#ifndef DACHA_TREEFACTORY_H
#define DACHA_TREEFACTORY_H
#include "CedarFactory.h"
#include "AppleFactory.h"
#include "FirFactory.h"

enum TreeType {
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
  Tree MakeTree(TreeType, sf::Vector2f&);
  ~TreeFactory() = default;
};

#endif