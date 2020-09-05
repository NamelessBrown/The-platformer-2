#include "TitlescreenState.h"
#include "SpriteComponent.h"
#include "PositionComponent.h"

TitlescreenState::TitlescreenState(Context& context)
	:State(context), player(context.registry->create(), context), m_world(*context.window), m_tilemap(context.textureHolder->GetResource("tiles"))
{
	auto& sprite = player.AddComponent<SpriteComponent>(context.textureHolder->GetResource("player"), sf::IntRect(0, 0, 50, 50));
	sprite.AddAnimation("standing", Animation(7, 0, 0, 50, 50));
	sprite.ChangeAnimation("standing");

	m_tilemap.Load("test.tmx");
}

void TitlescreenState::HandleEvents(const sf::Event& events)
{

}

void TitlescreenState::Update(float dt)
{
	auto view = GetContext().registry->view<SpriteComponent>();

	for (const auto& entity : view)
	{
		auto& sprite = view.get<SpriteComponent>(entity);
		sprite.Update(dt);
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

	window.draw(m_tilemap);
}
