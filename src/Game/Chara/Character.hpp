#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "../../Const/ImageID.hpp"
#include <string>

class Character
{
private:
  std::string sName;          //キャラ名
  float highFSpeed;          //高速モード時速度
  float lowFSpeed;           //低速モード時速度
  int nFeverFrames_Bomb; //無敵時間(ボム) (フレーム数)
  int nFeverFrames_Dmgd = 300; //無敵時間(被弾) 全キャラで不変
  ImageID image_id; //キャラクターのImage
protected:
  void setSName( std::string sName ){ this->sName = sName; }
  void setHighFSpeed( float highFSpeed ){ this->highFSpeed = highFSpeed; }
  void setLowFSpeed( float lowFSpeed ){ this->lowFSpeed = lowFSpeed; }
  void setNFeverFrames_Bomb( int nFeverFrames_Bomb ){ this->nFeverFrames_Bomb = nFeverFrames_Bomb; }
  void setImageID(ImageID image_id){ this->image_id = image_id; }
public:
  Character( void );
  virtual ~Character();
  std::string getSName( void ){ return sName; }
  float getHighFSpeed( void ){ return highFSpeed; }
  float getLowFSpeed( void ){ return lowFSpeed; }
  
  int getNFeverFrames_Bomb( void ){ return nFeverFrames_Bomb; }
  int getNFeverFrames_Dmgd( void ){ return nFeverFrames_Dmgd; }
  ImageID getImageID( void ){ return image_id; }
};

#endif /* _CHARACTER_H_ */