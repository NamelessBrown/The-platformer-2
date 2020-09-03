#pragma once

#include "State.h"

class TitlescreenState : public State
{
public:
	TitlescreenState(Context& context);
	~TitlescreenState() = default;
public:
	void HandleEvents(const sf::Event& events) override;
	void Update(float dt) override;
	void Draw() override;
private:

};

