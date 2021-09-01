#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <iostream>
#include <string>

class Character
{
private:
  std::string sName;          //キャラ名
  float highFSpeed;          //高速モード時速度
  float lowFSpeed;           //低速モード時速度
  int hitBoxRadius = 5;    //キャラの当たり判定半径(pxl) 全キャラで不変
  int mainShotPower;    //メインショット火力
  int subShotPower;     //サブショット火力
  float mainShotFSpeed = 8.0;    //メインショットスピード(pxl/frame) 全キャラで不変
  float subShotFSpeed;     //サブショットスピード(pxl/frame)
  int mainShotInterval = 5;  //メインショットを撃つ間隔(frame) 全キャラで不変
  int subShotInterval;   //サブショットを撃つ間隔(frame)
  //??? mainShotFormat;  //メインショットの形式(どう定義する？？)
  //??? subShotFormat;   //サブショットの形式(これもどう定義する？？)
  int nFeverFrames_Bomb; //無敵時間(ボム) (フレーム数)
  int nFeverFrames_Dmgd = 300; //無敵時間(被弾) 全キャラで不変
  int nMaxLife = 8;          //最大残機数 全キャラで不変
  int nMaxBomb = 8;          //最大ボム数 全キャラで不変
  int anMainShotsList[4] = {1, 2, 3, 5};  //メインショットのレベルごとの本数
  //int anSubShotsList[?] = {?, ?, ?, ?};   //サブショットのレベルごとの太さ(px)　解析に時間かかるらしい　後で追記
  bool godMode;    //無敵か否か　デバッグコマンドでオンにできるようにするのもあり
protected:
  void setSName( std::string sName ){ this->sName = sName; }
  void setHighFSpeed( float highFSpeed ){ this->highFSpeed = highFSpeed; }
  void setLowFSpeed( float lowFSpeed ){ this->lowFSpeed = lowFSpeed; }
  void setHitBoxRadius( int hitBoxRadius ){ this->hitBoxRadius = hitBoxRadius; }
  void setMainShotPower( int mainShotPower ){ this->mainShotPower = mainShotPower; }
  void setSubShotPower( int subShotPower ){ this->subShotPower = subShotPower; }
  void setSubShotFSpeed( float subShotFSpeed ){ this->subShotFSpeed = subShotFSpeed; }
  void setSubShotInterval( int subShotInterval ){ this->subShotInterval = subShotInterval; }
  void setNFeverFrames_Bomb( int nFeverFrames_Bomb ){ this->nFeverFrames_Bomb = nFeverFrames_Bomb; }
  void setGodMode( bool godMode ){ this->godMode = godMode; }
public:
  Character( void );
  virtual ~Character();
  std::string getSName( void ){ return sName; }
  float getHighFSpeed( void ){ return highFSpeed; }
  float getLowFSpeed( void ){ return lowFSpeed; }
  int getHitBoxRadius( void ){ return hitBoxRadius; }
  int getMainShotPower( void ){ return mainShotPower; }
  int getSubShotPower( void ){ return subShotPower; }
  float getMainShotFSpeed( void ){ return mainShotFSpeed; }
  float getSubShotFSpeed( void ){ return subShotFSpeed; }
  int getMainShotInterval( void ){ return mainShotInterval; }
  int getSubShotInterval( void ){ return subShotInterval; }
  int getNFeverFrames_Bomb( void ){ return nFeverFrames_Bomb; }
  int getNFeverFrames_Dmgd( void ){ return nFeverFrames_Dmgd; }
  int getNMaxLife( void ){ return nMaxLife; }
  int getNMaxBomb( void ){ return nMaxBomb; }
  int getAnMainShotsList( int num ){ return anMainShotsList[num]; }
  //int getAnSubShotsList( int num ){ return anSubShotsList[num]; }
  //あとアクセサを使ったInclX,InclYとかあるといいかも(使いやすそう)
  bool getGodMode( void ){ return godMode; }

  virtual void spellCard( void ) = 0;
};

#endif /* _CHARACTER_H_ */