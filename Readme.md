# Touhou-Koumatou
東方紅魔塔とは、有志の``SNIT SOFT``による東方紅魔郷のリメイク作品です。

## HowToBuild
### 環境構築
+ C++20に対応したコンパイラ群
+ Git
+ CMake
+ SDL2 2.26.3
+ SDL2_image 2.6.3
+ SDL2_mixer 2.6.3
をインストールしてください。

### ビルド
```sh
git clone https://github.com/Takotsubo9/ToHoToNIT.git
cd ToHoToNIT
cmake -B build -DSDL2_INCLUDE_DIR=<SDL2のヘッダのディレクトリ> -DSDL2_LIBRARY_DIR=<SDL2のライブラリのディレクトリ> .
cmake --build build
```
上記を実行した場合、build/binフォルダに実行ファイルが作成されているはずです。
<>内は適切なパスに置き換えてください。
