#ifndef S_TILE
#define S_TILE

struct Tile {
    char Symbol = '.';
    TCODColor foreColor = TCODColor.white;
    TCODColor backColor = new TCODColor(15,15,15);
};

#endif
