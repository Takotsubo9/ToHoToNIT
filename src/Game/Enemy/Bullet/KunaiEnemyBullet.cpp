#include"KunaiEnemyBullet.hpp"

KunaiEnemyBullet::KunaiEnemyBullet( void )
{

}

KunaiEnemyBullet::KunaiEnemyBullet( float x, float y, float angle ) : EnemyBullet( x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

KunaiEnemyBullet::KunaiEnemyBullet( int enemyBulletID, float x, float y, float angle ) : EnemyBullet( enemyBulletID, x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

KunaiEnemyBullet::~KunaiEnemyBullet()
{

}