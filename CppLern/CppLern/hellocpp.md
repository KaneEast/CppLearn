#### GCCを使ってhello.cppをコンパイルするには以下のようにする。
$ g++ -o hello hello.cpp


#### C++コンパイラーとしては、GCC(GNU Compiler Collection)とClang(クラン)がある。使い方はどちらもほぼ同じだ。
C言語コンパイラーは              gcc
ClangのC++コンパイラーは    clang++


#### 実行
./hello


#### GCCの基本的な使い方は以下のとおり。

g++ その他のオプション -o 出力するファイル名 ソースファイル名
ソースファイル名は複数指定することができる。

$ g++ -o abc a.cpp b.cpp c.cpp

#### コンパイラーオプション
GCCのコンパイラーオプションをいくつか学んでいこう。

-std=はC++の規格を選択するオプションだ。C++17に準拠したいのであれば-std=c++17を指定する。読者が本書を読むころには、C++20や、あるいはもっと未来の規格が発行されているかもしれない。常に最新のC++規格を選択するオプションを指定するべきだ。

-Wallはコンパイラーの便利な警告メッセージのほとんどすべてを有効にするオプションだ。コンパイラーによる警告メッセージはプログラムの不具合を未然に発見できるので、このオプションは指定すべきだ。

--pedantic-errorsはC++の規格を厳格に守るオプションだ。規格に違反しているコードがコンパイルエラー扱いになる。

これをまとめると、GCCは以下のように使う。

g++ -std=c++17 -Wall --pedantic-errors -o 出力ファイル名 入力ファイル名

#### GCCのマニュアル
$ man gcc

手元にマニュアルがない場合、GCCのWebサイトにあるオンラインマニュアルも閲覧できる。
https://gcc.gnu.org/
https://gcc.gnu.org/onlinedocs/


time: output comple time 
time g++ -std=c++17 -Wall --pedantic-errors -include all.h -o program hello.cpp



```shell
$ ls
all.h hello.cpp
$ g++ -std=c++17 -Wall --pedantic-errors -x c++-header -o all.h.gch all.h
$ ls
all.h all.h.gch hello.cpp
$ time g++ -std=c++17 -Wall --pedantic-errors -include all.h -o program hello.cpp
```


#### 出力リダイレクト
./hello > output.txt

#### 入力リダイレクト
./hello < input.txt
