#ifndef MOUNTAIN_HPP
#define MOUNTAIN_HPP

#include "Piece.hpp"


class Mountain : virtual public Piece
{
    public:
        Mountain(BITMAP* img);
        ~Mountain();
    protected:
    private:
};

#endif // MOUNTAIN_HPP
