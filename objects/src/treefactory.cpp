#include "../treefactory.h"

Tree& TreeFactory::CreateTree (treetype tree, sf::Vector2f& pos) {
  switch (tree) {
    case cedar:
      return cedarmaker.CedarMake(pos);
    case fir:
      return firmaker.FirMake(pos);
    case appletree:
      return applemaker.AppleMake(pos);
  }
}

template<class T>
std::vector<T>& TreeFactory::GetTrees(treetype type) {
  switch (type) {
    case cedar:
      return cedarmaker.GetTrees();
    case fir:
      return firmaker.GetTrees();
    case appletree:
      return applemaker.GetTrees();
  }
}
