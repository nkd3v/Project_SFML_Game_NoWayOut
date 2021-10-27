#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

class ScoreBoard
{
private:

public:
  void addScore(const std::string& name, int score);
  std::vector<std::pair<int, std::string>> getScores();
};

