#pragma once
#include "stdafx.h"

enum class MessageType : uint8_t
{
	HandShake = 0,
	SaveState = 1,
	InputData = 2,
	MovieData = 3,
	GameInformation = 4,
};