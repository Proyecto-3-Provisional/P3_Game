#include <TheRiseOfSuxalote/timer.h>

#include <string>
#include <iostream>
#include <SDL_timer.h>

#include <Render/text.h>
#include <Render/UI_Manager.h>
#include <TheRiseOfSuxalote/endgame.h>

namespace magma_game
{
	Timer::Timer() : textTime(), isPaused(), remainingTime(), initialTime() { }

	Timer::~Timer() { }

	bool Timer::initComponent(std::map<std::string, std::string> args)
	{ 
		try {
			remainingTime = std::stof(args["time"]);
		}
		catch (std::exception& e) {
			std::cout << "WARNING! - error en un componente timer:\n\n     " << e.what() << "\n\n";

			return false;
		}
		return true;
	}

	bool Timer::start()
	{
		initialTime = remainingTime;
		textTime = ent->getComponent<magma_engine::Text>();
		if (textTime == nullptr) return false;

		return true;
	}

	void Timer::onEnable() 
	{
		if (textTime != nullptr)
			textTime->onEnable();
	}

	void Timer::onDisable() 
	{
		if (textTime != nullptr)
			textTime->onDisable();
	}

	void Timer::setTime(float time) 
	{
		remainingTime = time;
	}

	int Timer::getTime()
	{
		return remainingTime; 
	}

	void Timer::update(float deltaTime) 
	{
		if (textTime != nullptr && !isPaused && remainingTime > 0)
		{
			remainingTime -= deltaTime;
			textTime->changeText(std::to_string(getTime()));

			if (remainingTime <= 0 && ent->hasComponent<Endgame>())
				ent->getComponent<Endgame>()->winOrLose(false);
		}
	}

	void Timer::reset()
	{
		isPaused = false;
		remainingTime = initialTime; 
	}

	void Timer::pause()
	{
		if (!isPaused)
			isPaused = true;
	}

	void Timer::resume()
	{
		if (isPaused)
			isPaused = false;
	}
}

