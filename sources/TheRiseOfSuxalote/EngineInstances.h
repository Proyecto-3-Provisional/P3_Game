#pragma once

// Este include no es necesario aqu�, pero lo ponemos porque todas los archivos que hagan un include 
// de este van a necesitar tambi�n incluir MagmaEngine.h
#include "MagmaEngine/MagmaEngine.h"


namespace magma_game {
	static magma_engine::CMagmaEngine* instances;	
}