//esta clase es el tama�o del jugador que aumenta de tama�o al colisionar con otros peces que sean mas peque�os que el
//poner que cuando llegue a cierto tama�o que cambie de escena/termine la partida 
//si el jugador colisiona con un pez mas grande que el entonces hay que cambiar la escena

#include <EC/component.h>

class Rigidbody;

class Size : public magma_engine::ec::Component
{
public:
	Size();
	~Size();

	bool initComponent() override;
	void update(float deltaTime) override;

	//el tama�o no esta definido por el tama�o del modelo visualmente 
	float tam = 1; //el tama�o se indica aqui para saber si es mas grande o no cuado se compare con el otro y se usara para escalar cuando cambie de tama�o

private:
	magma_engine::Rigidbody* rb;
	bool isPlayer;
};
