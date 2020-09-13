#pragma once

#include "State.h"
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
private:
	GUI::Button m_play;
	GUI::Button m_quit;
	sf::Sprite m_background;
};

