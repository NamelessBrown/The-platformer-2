#include "TitlescreenState.h"
#include <iostream>

TitlescreenState::TitlescreenState(Context& context)
	:State(context)
{
}

void TitlescreenState::HandleEvents(const sf::Event& events)
{

}

void TitlescreenState::Update(float dt)
{
	std::cout << "From the TitleScreen!!!!" << std::endl;
}

void TitlescreenState::Draw()
{
}
