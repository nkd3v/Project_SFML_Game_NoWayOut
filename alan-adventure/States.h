#pragma once

#include "State.h"
#include "GameState.h"
#include "MainMenuState.h"
#include "ScoreboardState.h"

using StateRef = std::unique_ptr<State>;