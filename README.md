*This project has been created as part of the 42 curriculum by dakobaya.*

# ft_printf

A re-implementation of part of the C standard library `printf` function.

## Description

The goal of this project is to understand how `printf` reads a format string,
dispatches each conversion, and consumes a variable number of arguments with
`va_list`.

This implementation builds a static library named `libftprintf.a` and provides:

```c
int	ft_printf(const char *format, ...);
```

The project does not implement the original `printf` buffer management. Output is
written directly with `write(2)`.

The supported mandatory conversions are:

| Specifier | Description |
| --- | --- |
| `%c` | Prints one character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal format |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned hexadecimal number in lowercase |
| `%X` | Prints an unsigned hexadecimal number in uppercase |
| `%%` | Prints a percent sign |

## Instructions

Compile the library:

```sh
make
```

This creates `libftprintf.a` at the root of the repository.

To use it in another project, include the header and link the library:

```c
#include "ft_printf.h"

ft_printf("Hello %s, you are %d years old.\n", name, age);
```

Useful Makefile rules:

```sh
make        # build libftprintf.a
make clean  # remove object files
make fclean # remove object files and libftprintf.a
make re     # rebuild from scratch
```

## Project Structure

| File | Role |
| --- | --- |
| `ft_printf.c` | Main loop, format-string scanning, and conversion dispatch |
| `utils.c` | Character, string, signed decimal, and unsigned decimal output |
| `utils_hex.c` | Hexadecimal and pointer output |
| `ft_printf.h` | Public prototype and internal helper prototypes |
| `Makefile` | Builds `libftprintf.a` with `cc -Wall -Wextra -Werror` and `ar` |
| `liblib/` | Copied libft sources kept in the repository |

## Chosen Algorithm and Data Structure

The main data structure is `va_list`, which is used to read the variable-length
arguments in order. Since variadic arguments do not include type or count
information, the format string is used to decide which type should be extracted
with `va_arg`.

The algorithm scans the format string from left to right. Ordinary characters are
written directly, and when `%` is found, the next character is used to call the
matching helper function. Each helper prints one value and returns the number of
characters written.

Decimal and hexadecimal numbers are printed recursively by dividing the value by
the target base. This keeps the implementation simple while supporting all
mandatory numeric conversions. The `format` argument is expected to be a valid
C string; passing `NULL` as the format string is undefined behavior.

## Resources

- `man 3 printf` - reference for the behavior and contract of the original
  `printf` function.
- [Variable-length arguments (Qiita)](https://qiita.com/keitean/items/fd2be6710efe681cc516)
- [Variable-length arguments (Qiita)](https://qiita.com/subaruf/items/657c67a1809515589a7c)
- [Default argument promotions](https://www.menonfled.com/%E6%97%A2%E5%AE%9A%E3%81%AE%E5%AE%9F%E5%BC%95%E6%95%B0%E6%8B%A1%E5%BC%B5/)
- [ft_printf notes](https://gist.github.com/n01e0/dd8b95a2cf1cd461d466031386df1bc2)
- [Base number converter](https://hogehoge.tk/tool/number.html)

AI assistance was used to review the subject requirements, organize personal
notes about variadic arguments, and draft this README. The implementation should
still be understood and explained by the author during peer evaluation.

---

# ft_printf 日本語版

C標準ライブラリの `printf` 関数の一部を再実装したプロジェクトです。

## 概要

このプロジェクトの目的は、`printf` がどのようにフォーマット文字列を
読み取り、各変換指定子に処理を振り分け、`va_list` を使って可変長引数を
扱っているのかを理解することです。

この実装では、`libftprintf.a` という静的ライブラリを作成し、次の関数を
提供します。

```c
int	ft_printf(const char *format, ...);
```

本家 `printf` のバッファ管理は実装していません。出力は `write(2)` を使って
直接行います。

対応している必須変換指定子は次の通りです。

| 指定子 | 説明 |
| --- | --- |
| `%c` | 1文字を出力する |
| `%s` | 文字列を出力する |
| `%p` | ポインタアドレスを16進数形式で出力する |
| `%d` | 符号付き10進整数を出力する |
| `%i` | 符号付き10進整数を出力する |
| `%u` | 符号なし10進整数を出力する |
| `%x` | 符号なし16進整数を小文字で出力する |
| `%X` | 符号なし16進整数を大文字で出力する |
| `%%` | パーセント記号を出力する |

## 使い方

ライブラリをコンパイルします。

```sh
make
```

これにより、リポジトリ直下に `libftprintf.a` が作成されます。

別のプロジェクトで使う場合は、ヘッダを include し、ライブラリをリンクします。

```c
#include "ft_printf.h"

ft_printf("Hello %s, you are %d years old.\n", name, age);
```

主な Makefile ルールは次の通りです。

```sh
make        # libftprintf.a を作成する
make clean  # オブジェクトファイルを削除する
make fclean # オブジェクトファイルと libftprintf.a を削除する
make re     # 最初から作り直す
```

## プロジェクト構成

| ファイル | 役割 |
| --- | --- |
| `ft_printf.c` | メインループ、フォーマット文字列の走査、変換指定子の振り分け |
| `utils.c` | 文字、文字列、符号付き10進数、符号なし10進数の出力 |
| `utils_hex.c` | 16進数とポインタの出力 |
| `ft_printf.h` | 公開プロトタイプと内部ヘルパー関数のプロトタイプ |
| `Makefile` | `cc -Wall -Wextra -Werror` と `ar` で `libftprintf.a` を作成 |
| `liblib/` | リポジトリ内に置いている libft のソース |

## 選んだアルゴリズムとデータ構造

中心となるデータ構造は `va_list` です。可変長引数には型情報や個数情報が
含まれていないため、フォーマット文字列を読みながら、各変換指定子に応じて
`va_arg` で取り出す型を決めています。

アルゴリズムは、フォーマット文字列を左から右へ走査する形です。通常の文字は
そのまま出力し、`%` が見つかった場合は次の文字を見て対応するヘルパー関数へ
処理を振り分けます。各ヘルパー関数は1つの値を出力し、出力した文字数を返します。

10進数と16進数は、対象の基数で割る再帰処理によって出力します。この方法により、
必須の数値変換をシンプルに実装できます。第1引数の `format` は有効なC文字列で
あることを前提としており、`NULL` を渡すことは未定義動作です。

## 参考資料

- `man 3 printf` - 本家 `printf` の挙動と契約の確認に使用。
- [Variable-length arguments (Qiita)](https://qiita.com/keitean/items/fd2be6710efe681cc516)
- [Variable-length arguments (Qiita)](https://qiita.com/subaruf/items/657c67a1809515589a7c)
- [Default argument promotions](https://www.menonfled.com/%E6%97%A2%E5%AE%9A%E3%81%AE%E5%AE%9F%E5%BC%95%E6%95%B0%E6%8B%A1%E5%BC%B5/)
- [ft_printf notes](https://gist.github.com/n01e0/dd8b95a2cf1cd461d466031386df1bc2)
- [Base number converter](https://hogehoge.tk/tool/number.html)

AIは、課題要件の確認、可変長引数に関するメモの整理、このREADMEの下書き作成に
使用しました。実装内容については、作者自身がpeer evaluationで説明できるように
理解しておく必要があります。
