#include "TestChara.hpp"

TestChara::TestChara( void )
{
    setSName( "saikyo" );
    setHighFSpeed( 4.0 );
    setLowFSpeed( 2.0 );
    setNFeverFrames_Bomb( 0 );
    setImageID(ImageID::game_chara_test);
}

TestChara::~TestChara()
{

}

void TestChara::spellCard( void )
{

}