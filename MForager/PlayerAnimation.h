#pragma once
#include "AnimationBase.h"

class PlayerAnimation: public AnimationBase {
public:
	enum class AniState {
		walk_right,
		walk_left,
		action_right,
		action_left,
		stop_right,
		stop_left,
		END
	};

	PlayerAnimation() : AnimationBase((int)AniState::END) {
		mapping((int)AniState::stop_right,		RES_KEY::PLAYER_STOP_R);
		mapping((int)AniState::stop_left,		RES_KEY::PLAYER_STOP_L);
		mapping((int)AniState::action_right,	RES_KEY::PLAYER_ACTION_R);
		mapping((int)AniState::action_left,		RES_KEY::PLAYER_ACTION_L);
		mapping((int)AniState::walk_right,		RES_KEY::PLAYER_WALK_R);
		mapping((int)AniState::walk_left,		RES_KEY::PLAYER_WALK_L);
	};
};

