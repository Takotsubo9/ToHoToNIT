#include"KnifeEnemyBullet.hpp"

KnifeEnemyBullet::KnifeEnemyBullet( void )
{

}

KnifeEnemyBullet::KnifeEnemyBullet( float x, float y, float angle ) : EnemyBullet( x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

KnifeEnemyBullet::KnifeEnemyBullet( int enemyBulletID, float x, float y, float angle ) : EnemyBullet( enemyBulletID, x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

KnifeEnemyBullet::~KnifeEnemyBullet()
{

}