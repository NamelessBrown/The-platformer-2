#include "TitlescreenState.h"
#include "SpriteComponent.h"
#include "PositionComponent.h"

TitlescreenState::TitlescreenState(Context& context)
	:State(context), m_test(context), m_world(*context.window)
{
	m_test.AddComponent<SpriteComponent>(context.textureHolder->GetResource("boobs"));
	m_test.AddComponent<PositionComponent>(5.f, 5.f);

}

void TitlescreenState::HandleEvents(const sf::Event& events)
{

}

void TitlescreenState::Update(float dt)
{
	auto view = GetContext().registry->view<PositionComponent, SpriteComponent>();

	for (auto& entity : view)
	{
		auto& position = view.get<PositionComponent>(entity);
		auto& sprite = view.get<SpriteComponent>(entity);
		
		position.x += 50.f * dt;
		position.y += 50.f * dt;

		sprite.GetSprite().setPosition(position.x, position.y);

	}

}

void TitlescreenState::Draw()
{
	auto& window = *GetContext().window;
	auto view = GetContext().registry->view<SpriteComponent>();

	for (auto& entity : view)
	{
		auto& sprite = view.get<SpriteComponent>(entity);
		sprite.Draw(window);
	}

}
