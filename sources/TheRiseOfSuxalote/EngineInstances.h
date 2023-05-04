#pragma once

// Este include no es necesario aquí, pero lo ponemos porque todas los archivos que hagan un include 
// de este van a necesitar también incluir MagmaEngine.h
#include "MagmaEngine/MagmaEngine.h"


namespace magma_game {
	static magma_engine::CMagmaEngine* instances;	
}