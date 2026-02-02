#define CHUNK_SIZE 64

typedef struct {
    int x, y;          // grid position (top-left)
    int dirty_min_x, dirty_min_y, dirty_max_x, dirty_max_y;  // Local coords, init to 0,CHUNK_SIZE-1 if full
    bool is_dirty;     // flag
} Chunk;

typedef struct {
    // ... existing: char *cells; int width, height;
    Chunk *chunks;     // Array of (width/CHUNK_SIZE) * (height/CHUNK_SIZE)
    int chunks_wide, chunks_tall;
    int num_chunks;
    pthread_t *threads;  // One/core
    int num_threads;
} World;
