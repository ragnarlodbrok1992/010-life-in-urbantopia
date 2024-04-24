#ifndef _HPP_ISOTILE
#define _HPP_ISOTILE

// Isometric tiles
class IsoTile {
    private:
        int id; // Here is used TILE_ID as a static value to create unique id for each tile

    public:
        IsoTile(int x, int y);
        ~IsoTile();

        void draw();
};

#endif // _HPP_ISOTILE
