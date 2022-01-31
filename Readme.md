# Touhou-Koumatou
東方紅魔塔とは、有志の``SNIT SOFT``による東方紅魔郷のリメイク作品です。

## 依存ライブラリ
* SDL 2.0.20
* SDL_image 2.0.5

## HowToBuild
### 環境構築
* Windows環境  
    + MinGW  
    + Git for Windows

    をインストールしてください。
    
    SDL関係については、

    * [SDL](https://www.libsdl.org/download-2.0.php)
    * [SDL_image](https://www.libsdl.org/projects/SDL_image/)

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
