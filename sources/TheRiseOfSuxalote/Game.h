#ifdef SUXALOTE_EXPORTS
#define SUXALOTE_API __declspec(dllexport)
#else
#define SUXALOTE_API __declspec(dllimport)
#endif

class SUXALOTE_API Game {
public:
	Game();
	void prueba();
};