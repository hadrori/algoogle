---
layout: post
title: "Codeforces 375D Tree and Queries"
date: 2014-07-11T00:03:00+09:00
comments: true
category: Codeforces
tags: [tree, sqrt-decomposition, data-structure]
---

[Tree and Queries](http://codeforces.com/problemset/problem/375/D)

#### 問題概要

****

N(<=100000)頂点の木の各頂点に色が塗られている. このとき以下のクエリに答えろ.  
頂点vの部分木にk個以上に塗られている色はいくつあるか


#### 解法

****

オイラーツアーして平方分割する.  
部分木の開始点を平方分割の各バケットの要素数Bごとに区切る.  
クエリをその開始点順にソートし, 同じバケットでは終了点順でソートしておくと開始点の各バケットでの移動は高々B回(オイラーツアーをしているので).  
また各バケットでのクエリの終了点の移動は高々N回になる.  
よって全体では`$O(N\sqrt{M})$`になる.  
  
データ構造をマージする一般的なテクも使えるらしいのでコードを載せておいた.  
深い順にクエリを処理することで順にマージしていけるようにする.  
マージは大きいものを選んでそれに小さい方を愚直に突っ込んでいるだけ(直感的にはすごくTLEしそうな感じだ).  
マージ後の小さい方はclearしておかないとたぶんMLEする.  

#### コード

****

{{< includeCode "/Codeforces/375D.cpp" "cpp" >}}

{{< includeCode "/Codeforces/375D1.cpp" "cpp" >}}
