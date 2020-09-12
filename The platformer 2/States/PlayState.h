
#include "State.h"
#include "../World/World.h"

class PlayState : public State
{
public:
	explicit PlayState(State::Context& context);
	~PlayState() = default;
public:
	void HandleEvents(const sf::Event& events) override;
	void Update(float dt) override;
	void Draw() override;
private:
	World m_world;
};

