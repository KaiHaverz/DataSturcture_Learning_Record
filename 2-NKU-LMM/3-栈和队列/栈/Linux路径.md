# 1_linux 路径

## 1 问题描述

- 将给定的非最简的 linux 路径,化简为标准的 linux 绝对路径

- .表示当前目录

- ..表示上一级目录

- 标准linux绝对路径的特点

  1. 第一个字符为斜杠 / ,表示根目录
  2. 两个目录名称直接有且仅有一个斜杠 / 
  3. 除根目录外，路径结尾不能为斜杠 / 
  4. 不会出现一个英文句号 . 或者两个连续的英文句号 ..

  

## 2 Input Format

- input:非最简的 linux 绝对路径




## 3 Output Format

- output:最简化的 linux 绝对路径
- eg:
  - input: /aaa/../../bbb/ccc/..///./..
  - output: /

