#include"TestBarrage.hpp"
#include"../Enemy.hpp"

TestBarrage::TestBarrage( void )
{

}

TestBarrage::~TestBarrage()
{

}

void TestBarrage::apperBullet( int quantity )
{
    EnemyBullet * ebullet;
    for( int i = 0; i < quantity; i++ )
    {
        ebullet = new BigEnemyBullet( i, getEnemy()->getX() - 10, getEnemy()->getY(), 270 );
        setEBullet( ebullet );
    }
}

void TestBarrage::straightToPlayerBullet( void )
{
    for( int i; i < getEBulletSize(); i++ )
    {
        getEBullet( i )->updatePlaceWithVector( 20, 0 );
    }
}