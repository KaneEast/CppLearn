// GCCを使ってhello.cppをコンパイルするには以下のようにする。
// $ g++ -o hello hello.cpp

#include <iostream>
using namespace std;

extern void input_redirect();
extern void step00_standardInput_test();
extern void step01_lammda_test();
extern void step02_recursion_test();
extern void step03_vector_test();
extern void step04_std_algorithm();
extern void step05_struct_test();
extern void step06_operator_overloading_test();
extern void step07_template_array_test();
extern void step08_excption_test();
extern void step09_pointer_test();
extern void step10_memory_allocate_test();
extern void step11_string_test();

int main(int argc, const char * argv[]) {
    
//    step00_standardInput_test();            // 標準入力テスト
//    step01_lammda_test();                   // ラムダテスト
//    step02_recursion_test();                // 再帰関数テスト
//    step03_vector_test();                   // Vectorテスト
    step04_std_algorithm();                 // std algorithmのテスト
//    step05_struct_test();                   // 構造体テスト
//    step06_operator_overloading_test();     // オペレーター　オーバーロード　テスト
//    step07_template_array_test();           // テンプレート 配列 テスト
//    step08_excption_test();                 // 例外処理　テスト
//    step09_pointer_test();                  // ポインター　テスト
//    step10_memory_allocate_test();          //
//    step11_string_test();                   //
    
    
    // TODO: chapter 33
    
    
    // コンパイラのバージョンを確認
    cout << "cplusplus compiler version is: " <<  __cplusplus << endl;
    
    return 0;
}
