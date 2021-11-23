#pragma once

class Scoreboard
{
private:

public:
  void addScore(const std::string& name, int score);
  std::vector<std::pair<int, std::string>> getScores();
};

