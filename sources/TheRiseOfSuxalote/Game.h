#ifdef SUXALOTE_EXPORTS
#define SUXALOTE_API __declspec(dllexport)
#else
#define SUXALOTE_API __declspec(dllimport)
#endif

#include <string>
#include <vector>

namespace magma_engine {
	class CMagmaEngine;
}

namespace magma_game {
	extern "C" SUXALOTE_API void __cdecl gameNameScene(std::vector<std::string>& strings);
}