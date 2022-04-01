#include "Character.hpp"

Character::Character( std::string sName, float highFSpeed, float lowFSpeed, int nFeverFrames_Bomb, ImageID image_id )
{
    this->sName = sName;
    this->highFSpeed = highFSpeed;
    this->lowFSpeed = lowFSpeed;
    this->nFeverFrames_Bomb = nFeverFrames_Bomb;
    this->image_id = image_id;
}

Character::~Character()
{

}