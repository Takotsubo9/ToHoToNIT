#include"Ellipse1EnemyBullet.hpp"

Ellipse1EnemyBullet::Ellipse1EnemyBullet( void )
{

}

Ellipse1EnemyBullet::Ellipse1EnemyBullet( float x, float y, float angle ) : EnemyBullet( x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

Ellipse1EnemyBullet::Ellipse1EnemyBullet( int enemyBulletID, float x, float y, float angle ) : EnemyBullet( enemyBulletID, x, y, angle )
{
    setBulletHitBoxRadius( 5 );
}

Ellipse1EnemyBullet::~Ellipse1EnemyBullet()
{

}