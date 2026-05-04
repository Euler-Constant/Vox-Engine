#include <stdint.h>
#include "world.h"

// Material definitions
Material materials[256] = {
    {0, "Air", 0, 0, 0},        // Transparent/empty
    {1, "Stone", 128, 128, 128}, // Gray
    {2, "Dirt", 139, 69, 19},   // Brown
    {3, "Water", 0, 0, 255},    // Blue
    {4, "Sand", 238, 203, 173}, // Sandy
};

// Initialize materials
void materials_init() {
    // load from file or generate procedurally
}
