#ifndef DACHA_DACHA_H
#define DACHA_DACHA_H
#include "TreeFactory.h"
#include "HouseFactory.h"
#include "BushFactory.h"
#include "ShadowManager.h"
#include "Drawer.h"
#include <iostream>
#include <ctime>

class CottageManager {
 private:
  std::string help_ = "you can use next commands: \n 'create house' with 1 parameter: position(float, float) of house \n"
                     "'create tree' with two parameters : type of tree (cedar, appletree, fir) and position(float, float) \n"
                     "'create bush' with parameter position(float, float) \n"
                     "'show' with parameter(top, front) to save image with view from top or front \n"
                     "'clear' to delete all added objects \n"
                     "'exit' to stop program \n"
                     "'sun angle' with single parameter angle(float): to set position of sun above place \n";

  std::vector<Tree> trees_;
  std::vector<House> houses_;
  std::vector<Bush> bushes_;
  sf::RenderTexture& window_;
  TreeFactory tree_factory_{};
  HouseFactory house_factory_{};
  BushFactory bush_factory_{};
  Drawer drawer_{};
  ShadowManager shadows_{};
  float angle_ = 0;
  void Command();
  void CommandCreate();
  void CommandShow();
  void CommandSave(std::string&);

 public:
  void run();
  explicit CottageManager(sf::RenderTexture&);
  ~CottageManager() = default;
};

#endif