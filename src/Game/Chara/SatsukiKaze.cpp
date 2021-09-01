#include "SatsukiKaze.hpp"

SatsukiKaze::SatsukiKaze( void )
{
    setSName( "冴月麟(花)" );
    setHighFSpeed( 3.0 );
    setLowFSpeed( 1.5 );
    setMainShotPower( 25 );
    setSubShotPower( 30 );
    setSubShotFSpeed( 8 );
    setSubShotInterval( 5 );
    setNFeverFrames_Bomb( 315 );
    setGodMode( false );
}

SatsukiKaze::~SatsukiKaze()
{

}

void SatsukiKaze::spellCard( void )
{

}