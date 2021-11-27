#pragma once

static const float RAD2DEG = 180.f / M_PI;
static const float DEG2RAD = M_PI / 180.f;

const float vectorDistance(const float x1, const float y1, const float x2, const float y2);
const float vectorDistance(sf::Vector2f vec1, sf::Vector2f vec2);
const float vectorAngle(sf::Vector2f vec1, sf::Vector2f vec2);