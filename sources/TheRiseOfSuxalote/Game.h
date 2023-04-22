#ifdef SUXALOTE_EXPORTS
#define SUXALOTE_API __declspec(dllexport)
#else
#define SUXALOTE_API __declspec(dllimport)
#endif

#include <EC/component.h>

class Rigidbody;

class SUXALOTE_API Game {
public:
	Game();
};
extern "C" SUXALOTE_API void prueba();

namespace magma_game
{
	class PlayerController : public magma_engine::ec::Component
	{
	public:
		PlayerController();
		~PlayerController();

		bool initComponent() override;
		void update(float deltaTime) override;


	private:
		magma_engine::Rigidbody* rb;
		
	};
}

