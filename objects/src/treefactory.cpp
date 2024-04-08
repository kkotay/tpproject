#include "../treefactory.h"

void TreeFactory::CreateTree (treetype tree, sf::Vector2f& pos) {
  switch (tree) {
    case cedar:
      trees_.push_back(&(cedarmaker.CedarMake(pos)));
      break;
    case fir:
      trees_.push_back(&(firmaker.FirMake(pos)));
      break;
    case appletree:
      trees_.push_back(&(applemaker.AppleMake(pos)));
      break;
  }
}

std::vector<Object*>& TreeFactory::GetTrees() {
  return trees_;
}

void TreeFactory::Clear() {
  trees_.clear();
}
