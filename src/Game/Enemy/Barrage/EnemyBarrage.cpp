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
    
}