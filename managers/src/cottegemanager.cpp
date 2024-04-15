#include "cottegemanager.h"

CottageManager::CottageManager(sf::RenderTexture &window) : window_(window) {}

void CottageManager::Command() {
  std::string command;
  std::cin >> command;
  if (command == "create") {
    std::cin >> command;
    if (command == "tree") {
      std::string type;
      std::cin >> type;
      float x = 0;
      float y = 0;
      std::cin >> x >> y;
      sf::Vector2f coord = sf::Vector2f(x, y);
      if (type == "appletree") {
        trFactory_.CreateTree(appletree, coord);
      } else if (type == "fir") {
        trFactory_.CreateTree(fir, coord);
      } else if (type == "cedar") {
        trFactory_.CreateTree(cedar, coord);
      }
    } else if (command == "house") {
      float x = 0;
      float y = 0;
      std::cin >> x >> y;
      hFactory_.HouseMake(sf::Vector2f(x, y));
    }
  } else if (command == "help" or command == "-h") {
    std::cout << "you can use next commands: \n 'create house' with 1 parameter: position(float, float) of house \n"
                 "'create tree' with two parameters : type of tree (cedar, appletree, fir) and position(float, float) \n"
                 "'show' with parameter(top, front) to save image with view from top or front \n"
                 "'clear' to delete all added objects \n"
                 "'exit' to stop program \n"
                 "'sun angle' with single parameter angle(float): to set position of sun above place \n";
  } else if (command == "show") {
    std::string view;
    std::cin >> view;
    if (view == "top") {
      drawer_.DrawObject(window_, hFactory_.GetHouses(), up);
      drawer_.DrawObject(window_, trFactory_.GetTrees(), up);
      shadows_.SetObj((hFactory_.GetHouses()));
      shadows_.SetObj((trFactory_.GetTrees()));
      shadows_.SearchShadow(angle_);
      drawer_.SimpleDraw(window_, shadows_.GetAllSeSh());
      drawer_.SimpleDraw(window_, shadows_.GetAllSh());
      window_.display();
    } else if (view == "front") {
      drawer_.DrawObject(window_, (hFactory_.GetHouses()), front);
      drawer_.DrawObject(window_, (trFactory_.GetTrees()), front);
    }
    sf::Image im{window_.getTexture().copyToImage()};
    static int num{};
    im.saveToFile(std::to_string(num) + ".png");
    ++num;
  } else if (command == "exit") {
    return;
  } else if (command == "sun angle") {
    std::cin >> angle_;
  }
  Command();
}

void CottageManager::Run() {
  Command();
}
