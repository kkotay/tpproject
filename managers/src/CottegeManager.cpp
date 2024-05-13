#include "CottegeManager.h"

CottageManager::CottageManager(sf::RenderTexture& window) : window_(window) {}

void CottageManager::Command() {
  std::string command;
  std::cin >> command;
  if (command == "create") {
    CommandCreate();
  } else if (command == "help" or command == "-h") {
    std::cout << help_;
  } else if (command == "show") {
    CommandShow();
  } else if (command == "angle") {
    std::cin >> angle_;
  } else if (command == "exit") {
    return;
  } else if (command == "clear") {
    trees_.clear();
    houses_.clear();
  }
  Command();
}

void CottageManager::run() {
  Command();
}

void CottageManager::CommandCreate() {
  std::string command;
  std::cin >> command;
  if (command == "tree") {
    std::string type;
    std::cin >> type;
    float x = 0;
    float y = 0;
    std::cin >> x >> y;
    sf::Vector2f coord = sf::Vector2f(x, y);
    if (type == "appletree") {
      trees_.push_back(tree_factory_.MakeTree(appletree, coord));
    } else if (type == "fir") {
      trees_.push_back(tree_factory_.MakeTree(fir, coord));
    } else if (type == "cedar") {
      trees_.push_back(tree_factory_.MakeTree(cedar, coord));
    }
  } else if (command == "house") {
    float x = 0;
    float y = 0;
    std::cin >> x >> y;
    houses_.push_back(house_factory_.MakeHouse(sf::Vector2f(x, y)));
  } else if (command == "bush") {
    float x = 0;
    float y = 0;
    std::cin >> x >> y;
    bushes_.push_back(bush_factory_.MakeBush(sf::Vector2f(x, y)));
  }
}

void CottageManager::CommandShow() {
  std::string view;
  std::cin >> view;
  if (view == "top") {
    shadows_.SearchShadow(angle_, trees_);
    shadows_.SearchShadow(angle_, houses_);
    shadows_.SearchShadow(angle_, bushes_);
    drawer_.drawTopWindow(window_);
    drawer_.drawSimple(window_, shadows_.GetAllShadow());
    drawer_.drawObject(window_, houses_, top);
    drawer_.drawObject(window_, trees_, top);
    drawer_.drawObject(window_, bushes_, top);
  } else if (view == "front") {
    drawer_.drawFrontWindow(window_);
    drawer_.drawObject(window_, houses_, front);
    drawer_.drawObject(window_, trees_, front);
    drawer_.drawObject(window_, bushes_, front);
  }
  CommandSave(view);
}

void CottageManager::CommandSave(std::string& view) {
  sf::Image image{window_.getTexture().copyToImage()};
  if (view == "front") {
    std::string path = "dacha";
    path.append(std::to_string(std::time(nullptr)));
    path.append(".png");
    image.saveToFile(path);
  } else {
    std::string path = "shadow";
    path.append(std::to_string(std::time(nullptr)));
    path.append(".png");
    image.saveToFile(path);
  }
}