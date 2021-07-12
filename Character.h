#include <iostream>
#include <string>

class Character
{
private:
  std::string sName;          //キャラ名
  float highFSpeed;          //高速モード時速度
  float lowFSpeed;           //低速モード時速度
  int nFeverFrames_Bomb; //無敵時間(ボム) (フレーム数)
  int nFeverFrames_Dmgd = 5; //無敵時間(被弾) 全キャラで不変
  int nMaxLife = 8;          //最大残機数 全キャラで不変
  int nMaxBomb = 8;          //最大ボム数 全キャラで不変
  int anMainShotsList[4] = {1, 2, 3, 5};  //メインショットのレベルごとの本数
  //int anSubShotsList[?] = {?, ?, ?, ?};   //サブショットのレベルごとの太さ(px)　解析に時間かかるらしい　後で追記
protected:
  void setSName( std::string sName ){ this->sName = sName; }
  void setHighFSpeed( float highFSpeed ){ this->highFSpeed = highFSpeed; }
  void setLowFSpeed( float lowFSpeed ){ this->lowFSpeed = lowFSpeed; }
  void setNFeverFrames_Bomb( int nFeverFrames_Bomb ){ this->nFeverFrames_Bomb = nFeverFrames_Bomb; }
public:
  Character( void );
  ~Character();
  virtual std::string getSName( void ){ return sName; }
  virtual float getHighFSpeed( void ){ return highFSpeed; }
  virtual float getLowFSpeed( void ){ return lowFSpeed; }
  virtual int getNFeverFrames_Bomb( void ){ return nFeverFrames_Bomb; }
  virtual int getNFeverFrames_Dmgd( void ){ return nFeverFrames_Dmgd; }
  virtual int getNMaxLife( void ){ return nMaxLife; }
  virtual int getNMaxBomb( void ){ return nMaxBomb; }
  virtual int getAnMainShotsList( int num ){ return anMainShotsList[num]; }
  //virtual int getAnSubShotsList( int num ){ return anSubShotsList[num]; }
  //あとアクセサを使ったInclX,InclYとかあるといいかも(使いやすそう)
  void UniqueSkill( void );
};