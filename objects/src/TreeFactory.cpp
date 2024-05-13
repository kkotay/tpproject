#include "../TreeFactory.h"

Tree TreeFactory::MakeTree(TreeType tree, sf::Vector2f& position) {
  switch (tree) {
    case cedar:
      return cedarmaker.MakeCedarTree(position);
    case fir:
      return firmaker.MakeFirTree(position);
    case appletree:
      return applemaker.MakeAppleTree(position);
  }
}