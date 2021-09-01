#include "TestChara.hpp"

TestChara::TestChara( void )
{
    setSName( "saikyo" );
    setHighFSpeed( 3.0 );
    setLowFSpeed( 1.5 );
    setMainShotPower( 3200 );
    setSubShotPower( 3200 );
    setSubShotFSpeed( 8 );
    setSubShotInterval( 5 );
    setNFeverFrames_Bomb( 0 );
    setGodMode( true );
}

TestChara::~TestChara()
{

}

void TestChara::spellCard( void )
{

}