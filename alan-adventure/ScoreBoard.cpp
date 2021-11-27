#include "stdafx.h"
#include "Scoreboard.h"

void Scoreboard::addScore(const std::string& name, int score)
{
  auto scores = getScores();
  scores.emplace_back(score, name);
  sort(scores.begin(), scores.end(), std::greater<>());

  while (scores.size() > 5)
    scores.pop_back();

  std::fstream file("score.txt");

  if (!file.is_open()) std::cerr << "Opening file failed!";

  for (const auto& score_ : scores)
    file << score_.second << ' ' << score_.first << '\n';
  file.close();
}

std::vector<std::pair<int, std::string>> Scoreboard::getScores()
{
  std::vector<std::pair<int, std::string>> scores;

  std::string t_name;
  int t_score;

  std::fstream file("score.txt");

  if (!file.is_open())
    throw "Opening file failed!";

  while (file >> t_name >> t_score)
    scores.emplace_back(t_score, t_name);

  file.close();

  return scores;
}
