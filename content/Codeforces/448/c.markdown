---
layout: post
title: "Codeforces 448C Painting Fence"
date: 2014-07-18T15:21:00+09:00
comments: true
category: Codeforces
tags: [divide-and-conquer]
---

[Painting Fence](http://codeforces.com/contest/448/problem/C)

#### 問題概要

****

n個のフェンスが並んであって, それぞれ幅1, 高さがa\[i\]になっている.  
これらをすべて塗りつぶしたい.  
連続する縦か横に一気に塗ることができるとき, 最小何回でぬれるか

#### 解法

****

分割統治する.  
区間\[l,r)を塗るとき, そのなかで最小の高さ以下の部分は横に一気に塗りつぶせる.  
そこでその高さの部分で分割していく.  
分割された左右の結果と最小の高さの和(つまりこの区間で横に塗る回数)と, その区間全てを縦に塗る回数(つまりr-l)の最小がその区間を塗るのにかかる最小回数.  
また分割していくとき, 下の部分は塗ってあると仮定するのでその高さを床にする.  
あとはコードを見ればわかるはず.  
  
ちなみに今回は毎回区間を舐めて最小の高さを求めているので`$O(n^2)$`になるが, Segment Treeを用いれば`$O(n\log n)$`に落とせる

#### コード

****

{{< includeCode "/Codeforces/448C.cpp" "cpp" >}}
