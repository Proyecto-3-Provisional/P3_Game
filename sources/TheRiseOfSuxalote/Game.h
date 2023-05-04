#ifdef SUXALOTE_EXPORTS
#define SUXALOTE_API __declspec(dllexport)
#else
#define SUXALOTE_API __declspec(dllimport)
#endif

#include <string>

namespace magma_engine {
	class CMagmaEngine;
}

namespace magma_game {
	extern "C" SUXALOTE_API std::string gameNameScene();
	extern "C" SUXALOTE_API void getEngineInstances(magma_engine::CMagmaEngine * engine);
}