#include "Tree.h"

class TreeFactory {
 protected:
  Tree tree;
 public:
  Tree createTree (treetype::type type) {
    switch (type) {
      case treetype::cedar:
        break;
      case treetype::appletree:
        break;
      case treetype::fir:
        break;
    }
    return tree;
  }
};