#pragma once

#include "State.h"
#include "Entity.h"
#include "World.h"

class TitlescreenState : public State
{
public:
	explicit TitlescreenState(Context& context);
	~TitlescreenState() = default;
public:
	void HandleEvents(const sf::Event& events) override;
	void Update(float dt) override;
	void Draw() override;
private:
	Entity m_test;
	World m_world;
};

