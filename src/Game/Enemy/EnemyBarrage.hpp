#ifndef _ENEMYBARRAGE_H_
#define _ENEMYBARRAGE_H_

#include<vector>
#include"EnemyBullet.hpp"

class EnemyBarrage
{
private:
    std::vector<EnemyBullet *> ebullets;
public:
    EnemyBarrage( void );
    virtual ~EnemyBarrage();
    //弾クラスをインスタンス化する方法がまだ定まらないので後に追記
};

#endif /* _ENEMYBARRAGE_H_ */