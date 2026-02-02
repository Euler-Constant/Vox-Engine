void world_init(World *w, int wid, int hgt) {
    w->width = wid; w->height = hgt;
    w->cells = calloc(wid * hgt, sizeof(char));

    w->chunks_wide = (wid + CHUNK_SIZE - 1) / CHUNK_SIZE;  // Top border
    w->chunks_tall = (hgt + CHUNK_SIZE - 1) / CHUNK_SIZE;
    w->num_chunks = w->chunks_wide * w->chunks_tall;
    w->chunks = malloc(w->num_chunks * sizeof(Chunk));

    for (int cy = 0; cy < w->chunks_tall; cy++) {
        for (int cx = 0; cx < w->chunks_wide; cx++) {
            //logic error afoot.

            // int idx = cy * w->chunks_wide + cx;
            // w->chunks[idx].x = cx * CHUNK_SIZE;
            // w->chunks[idx].y = cy * CHUNK_SIZE;
            // w->chunks[idx].is_dirty = true;
            // Resets rect to full chunk
            // w->chunks[idx].dirty_min_x = 0; w->chunks[idx].dirty_min_y = 0;
            // w->chunks[idx].dirty_max_x = CHUNK_SIZE - 1; w->chunks[idx].dirty_max_y = CHUNK_SIZE - 1;
        }
    }

    w->num_threads = 4;  // sysconf(ig) for core handling, apparently (T_T)
    w->threads = malloc(w->num_threads * sizeof(pthread_t));
}
