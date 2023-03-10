#include "Engine.h"

using namespace std;
using namespace sf;

void Engine::populateEmitters(vector<Vector2f>& vSoundEmitters, int** arrayLevel) {
	// Make sure the vector is empty
	vSoundEmitters.empty();
	
	// Keep track of the previous emitter
	// so we don't make too many
	FloatRect previousEmitter;
	
	// Search for fire in the level
	for (int x = 0; x < (int)m_LM.getLevelSize().x; x++) {
		for (int y = 0; y < (int)m_LM.getLevelSize().y; y++){
			// Skip over any tiles too 
			// Near a previous emiter
			if (!FloatRect(x * TILE_SIZE,
				y * TILE_SIZE,
				TILE_SIZE,
				TILE_SIZE).intersects(previousEmitter)) {
				// Add the coordinates of this water block
				vSoundEmitters.push_back(Vector2f(x * TILE_SIZE, y * TILE_SIZE));

				// Make a rectangle 6 blocks x 6 blocks
				// so we don't make any more emitters
			}
		}
	}
}