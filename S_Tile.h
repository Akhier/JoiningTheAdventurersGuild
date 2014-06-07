#ifndef S_TILE
#define S_TILE

struct Tile {
    char Symbol = ' ';
    TCODColor foreColor = TCODColor::lightestGrey;
    TCODColor backColor = TCODColor(15,15,15);
};

#endif
