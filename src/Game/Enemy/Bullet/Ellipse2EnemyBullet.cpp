#include"Ellipse2EnemyBullet.hpp"

Ellipse2EnemyBullet::Ellipse2EnemyBullet( void )
{

}

Ellipse2EnemyBullet::Ellipse2EnemyBullet( float x, float y, float angle ) : EnemyBullet( x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

Ellipse2EnemyBullet::Ellipse2EnemyBullet( int enemyBulletID, float x, float y, float angle ) : EnemyBullet( enemyBulletID, x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

Ellipse2EnemyBullet::~Ellipse2EnemyBullet()
{

}