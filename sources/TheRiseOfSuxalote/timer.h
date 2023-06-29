#pragma once

#include <Render/text.h>

namespace magma_engine 
{
	class Text;
	class UI_Manager;
}

namespace magma_game
{
	class Timer : public magma_engine::Component
	{
	public:
		Timer();
		virtual ~Timer();

		virtual bool initComponent(std::map<std::string, std::string> args);
		virtual bool start();
		virtual void update(float deltaTime);

		virtual void onEnable(); // Activacion del componente
		virtual void onDisable(); // Desactivacion del componente

		void reset(); // Reestablece el timer a su valor inicial
		void pause(); // Pausa el timer
		void resume(); // Reanuda el timer

		void setTime(float time); // Establece el tiempo restante del timer
		int getTime(); // Obtener el tiempo restante del timer

	private:
		float remainingTime; // Tiempo restante
		float initialTime; // Tiempo inicial
		bool isPaused; // Indica si el timer se encuentra pausado

		magma_engine::Text* textTime; // Componente texto del timer
	};
}

