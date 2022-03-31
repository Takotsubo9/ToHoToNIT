#include"EnemyBarrage.hpp"
#include"../Enemy.hpp"

EnemyBarrage::EnemyBarrage( void )
{

}

EnemyBarrage::EnemyBarrage( Enemy * enemy, int barrageID )
{
    setEnemy( enemy );
    setBarrageID( barrageID );
    getEnemy()->setEnemyBarrage( this );
}

EnemyBarrage::~EnemyBarrage()
{
    for( size_t i = 0; i < this->ebullets.size(); i++ )
    {
        if( ebullets[i] != nullptr )
        {
            delete ebullets[i];
            ebullets[i] = nullptr;
        }
    }
}