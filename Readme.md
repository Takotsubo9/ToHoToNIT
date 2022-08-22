# Touhou-Koumatou
東方紅魔塔とは、有志の``SNIT SOFT``による東方紅魔郷のリメイク作品です。

## 依存ライブラリ
* SDL 2.24.0
* SDL_image 2.6.2
* SDL_mixer 2.6.2

## HowToBuild
### 環境構築
* Windows環境  
    + MinGW  
    + Git for Windows

    をインストールしてください。
    
    SDL関係については、

    * [SDL](https://github.com/libsdl-org/SDL)
    * [SDL_image](https://github.com/libsdl-org/SDL_image)
    * [SDL_mixer](https://github.com/libsdl-org/SDL_mixer)

    からインストールしてください。

* Linux環境  
    + gcc
    + g++
    + git

    をインストールしてください。

    SDL関係については、各ディストリビューションのインストール方法に従ってください。


### ビルド
```sh
git clone https://github.com/Takotsubo9/ToHoToNIT.git
cd ToHoToNIT
./create-makefile.sh
make
```
上記のことを実行した場合、binフォルダに実行ファイルが作成されているはずです。

Windows環境で
```sh
make
```
が失敗した場合
```sh
mingw32-make
```
を代わりに実行すると、成功するかもしれません。
