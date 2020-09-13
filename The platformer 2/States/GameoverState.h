#include "State.h"
#include "../GUI/Button.h"

class GameoverState : public State
{
public:
	GameoverState(Context& context);
	~GameoverState() = default;
public:
	void HandleEvents(const sf::Event& events) override;
	void Update(float dt) override;
	void Draw() override;
private:
	GUI::Button m_quit;
	GUI::Button m_play;
	sf::Sprite m_background;
};