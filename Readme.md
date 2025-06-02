# Touhou-Koumatou
東方紅魔塔とは、有志の``SNIT SOFT``による東方紅魔郷のリメイク作品です。

## HowToBuild
### 環境構築
+ C++20に対応したコンパイラ群
+ Git
+ CMake
+ SDL2 2.32.6
+ SDL2_image 2.8.8
+ SDL2_mixer 2.8.1

をインストールしてください。

### ビルド
#### デスクトップ
```sh
git clone https://github.com/Takotsubo9/ToHoToNIT.git
cd ToHoToNIT
cmake -B build -DSDL2_INCLUDE_DIR=<SDL2のヘッダのディレクトリ> -DSDL2_LIBRARY_DIR=<SDL2のライブラリのディレクトリ> .
cmake --build build
```
上記を実行した場合、build/binフォルダに実行ファイルが作成されているはずです。
<>内は適切なパスに置き換えてください。

#### Android
工事中
```sh
# clone
git clone https://github.com/Takotsubo9/ToHoToNIT.git -b develop --depth 1
git clone https://github.com/libsdl-org/SDL.git -b release-2.32.6 --depth 1
git clone https://github.com/libsdl-org/SDL_image.git -b release-2.8.8 --recursive --depth 1
git clone https://github.com/libsdl-org/SDL_mixer.git -b release-2.8.1 --recursive --depth 1
# 依存ライブラリの配置
mv SDL/android-project .
mv SDL android-project/app/jni
mv SDL_image android-project/app/jni
mv SDL_mixer android-project/app/jni
# ソースコードの配置
rm -rf android-project/app/jni/src
mv ToHoToNIT android-project/app/jni/src
# アセットの配置
mv ToHoToNIT/assets android-project/app/src/main
# CMakeLists.txtのadd_subdirectoryの SDL_image, SDL_mixer 箇所のコメントアウトを解除
sed -i -e 's/#add_subdirectory(SDL_image)/add_subdirectory(SDL_image)/g' android-project/app/jni/CMakeLists.txt
sed -i -e 's/#add_subdirectory(SDL_mixer)/add_subdirectory(SDL_mixer)/g' android-project/app/jni/CMakeLists.txt

# 以下、build.gradle
# ndkBuildの箇所をコメントアウト化
# cmakeの箇所のコメントアウトを解除
# cmakeのargumentsのとこを "-DANDROID_APP_PLATFORM=android-19", "-DANDROID_STL=c++_static", "-DOP_DISABLE_EXAMPLES=ON", "-DSDL2MIXER_VENDORED=ON", "-DSDL2IMAGE_VENDORED=ON", "-DSDL2MIXER_INSTALL=OFF", "-DSDL2IMAGE_INSTALL=OFF", "-DSDL2IMAGE_SAMPLES=OFF", "-DSDL2MIXER_SAMPLES=OFF", "-DWITH_ASM=OFF"

cd android-project
./gradlew build
```
