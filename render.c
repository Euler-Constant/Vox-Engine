#include <SDL2/SDL.h>
#include "world.h"
#include "materials.h"

// Render voxels to the screen using chunked approach
void render_voxels(SDL_Renderer* renderer, World* world) {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 5, 255);  // Dark blue background
    SDL_RenderClear(renderer);

    // Calculate visible bounds in world coordinates
    int screen_width = 800;  // Should get from SDL_GetWindowSize
    int screen_height = 600;
    int world_left = (int)(world->cam_x - (screen_width / 2) / world->zoom);
    int world_top = (int)(world->cam_y - (screen_height / 2) / world->zoom);
    int world_right = (int)(world->cam_x + (screen_width / 2) / world->zoom);
    int world_bottom = (int)(world->cam_y + (screen_height / 2) / world->zoom);

    // Clamp to world bounds
    if (world_left < 0) world_left = 0;
    if (world_top < 0) world_top = 0;
    if (world_right >= world->width) world_right = world->width - 1;
    if (world_bottom >= world->height) world_bottom = world->height - 1;

    // Loop through visible area
    for (int wy = world_top; wy <= world_bottom; wy++) {
        for (int wx = world_left; wx <= world_right; wx++) {
            // Get material ID from world cells
            int cell_index = wy * world->width + wx;
            uint8_t material_id = (uint8_t)world->cells[cell_index];
            
            // Skip air/empty cells
            if (material_id == 0) continue;
            
            // Get material color
            Material mat = materials[material_id];
            
            // Convert world coords to screen coords
            int screen_x = (int)((wx - world->cam_x) * world->zoom + screen_width / 2);
            int screen_y = (int)((wy - world->cam_y) * world->zoom + screen_height / 2);
            
            // Draw pixel
            SDL_SetRenderDrawColor(renderer, mat.r, mat.g, mat.b, 255);
            SDL_RenderDrawPoint(renderer, screen_x, screen_y);
        }
    }
}