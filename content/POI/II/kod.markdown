---
layout: post
title: "POI II The Coding of Permutations"
date: 2014-11-02T13:03:00+09:00
comments: true
category: POI
tags: [binary-indexed-tree, binary-search]
---

[The Coding of Permutations](http://main.edu.pl/en/archive/oi/2/kod)

#### 問題概要

****

1からnまでの整数を並び替えた数列をaとする.  
`$b_{i}$`をj\<iとなるjのうち`$a_{j}$`\>`$a_{i}$`となる数とする数列bが与えられる.  
数列aとして考えられるものを出力せよ. 存在しない場合はNIEと出せ.

#### 解法

****

数列を後ろから特定していく.  
値の候補の集合をSとし, i番目を見ているとき  
候補のうち`$b_{i}$`番目に大きい数を`$a_{i}$`とすればよい.  
その後候補から`$a_{i}$`を削除する.  
  
あとは値の候補のうちk番目を見つけ, 削除できるようなデータ構造を考えれば良い.  
  
今回はBITを使ってやることにした.  
簡単のため値は0からn-1で考える.  
値vを使ったら位置vに1を足す.  
すると位置jについてそれ以降に使われた値の個数というのがsum(j,n)でわかる.  
つまりj以降でまだ使われていない数はn-j-sum(j,n)個となる.  
あとは使われてない個数が`$b_{i}+1$`個になるような位置の最右端を二分探索すればよい.  
計算量は`$O(n\log^{2}n)$`になる.  
  
#### コード

****

{{< includeCode "/POI/II/kod.cpp" "cpp" >}}
