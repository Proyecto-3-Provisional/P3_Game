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

