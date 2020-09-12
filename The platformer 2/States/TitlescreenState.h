#pragma once

#include "State.h"
#include "../World/World.h"
#include "../World/TileMap.h"
#include "../GUI/Button.h"

class TitlescreenState : public State
{
public:
	explicit TitlescreenState(Context& context);
	~TitlescreenState() = default;
public:
	void HandleEvents(const sf::Event& events) override;
	void Update(float dt) override;
	void Draw() override;
	void HandleCollision();
private:
	World m_world;
	GUI::Button m_button;
};

