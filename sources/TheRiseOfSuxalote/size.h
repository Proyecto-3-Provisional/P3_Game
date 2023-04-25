//esta clase es el tamaño del jugador que aumenta de tamaño al colisionar con otros peces que sean mas pequeños que el
//poner que cuando llegue a cierto tamaño que cambie de escena/termine la partida 
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

	//el tamaño no esta definido por el tamaño del modelo visualmente 
	float tam = 1; //el tamaño se indica aqui para saber si es mas grande o no cuado se compare con el otro y se usara para escalar cuando cambie de tamaño

private:
	magma_engine::Rigidbody* rb;
	bool isPlayer;
};
