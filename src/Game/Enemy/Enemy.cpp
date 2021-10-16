#include"Enemy.hpp"
#include"Barrage/EnemyBarrage.hpp"

Enemy::Enemy( void )
{

}

Enemy::Enemy( int enemyID )
{
    setEnemyID( enemyID );
}

Enemy::Enemy( int enemyID, float x, float y )    //生成時にいきなりスクリーンに映らないように、画面外指定
{
    setEnemyID( enemyID );
    setX( -1 );
    setY( -1 );
}

Enemy::~Enemy()
{

}

void Enemy::damageHP( int damagedHP )
{
    setHP( getHP() - ( damagedHP * getDefense() ) );
}

void Enemy::restHP( int restedHP )
{
    if( ( getHP() + restedHP ) > getMaxHP() )
    {
        setHP( getMaxHP() );
    }
    else
    {
        setHP( getHP() + restedHP );
    }
}