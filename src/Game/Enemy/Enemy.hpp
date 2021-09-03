#ifndef _ENEMY_H_
#define _ENEMY_H_

class Enemy
{
private:
    int enemyID;
    int HP;
    int enemyHitBoxRadius;    //当たり判定半径
    float defense;    //敵の防御率(0-1の間)
protected:
    void setHP( int HP ){ this->HP = HP; }
    void setEnemyHitBoxRadius( int enemyHitBoxRadius ){ this->enemyHitBoxRadius = enemyHitBoxRadius; }
public:
    Enemy( void );
    Enemy( int enemyID );
    virtual ~Enemy();
    void setEnemyID( int enemyID ){ this->enemyID = enemyID; }
    int getEnemyID( void ){ return enemyID; }
    int getHP( void ){ return HP; }
    int getEnemyHitBoxRadius( void ){ return enemyHitBoxRadius; }
    void setDefense( float defense ){ this->defense = defense; }
    float getDefense( void ){ return defense; }

    virtual void movement( void ) = 0;
    virtual void shot( void ) = 0;
};

#endif /* _ENEMY_H_ */