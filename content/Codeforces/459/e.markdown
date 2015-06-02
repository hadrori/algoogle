---
layout: post
title: "Codeforces 459E Pashmak and Graph"
date: 2014-08-16T04:17:00+09:00
comments: true
category: Codeforces
tags: [dp]
---

[Pashmak and Graph](http://codeforces.com/contest/459/problem/E)

#### 問題概要

****

有向グラフ上で, 辺の重みが単調増加になるような最長のパスの長さを求めよ

#### 解法

****

重さの小さい有向辺から見ていく.  
pw\[v\] := vが最後使われた有向辺の重さ  
dp\[v\]\[0\] := 頂点vまで重さpw[v]を使って作る題意のパスの最長の長さ  
dp\[v\]\[1\] := 頂点vまで重さpw[v]未満の辺を使って作る題意のパスの最長の長さ  
とすると  
有向辺(u->v)で  
dp\[v\]\[0\] = max(dp\[v\]\[0\], dp\[u\]\[1\]+1)  
となる(同じ重さの辺は使えないため)  
また, dp\[v\]\[1\]はvがpw[v]より重い辺で参照されたらすぐ更新する(当然pw[v]も).  
  
これで最後にdp\[v\]\[i\]の最大を求めれば良い.

#### コード

****

{{< includeCode "/Codeforces/459E.cpp" "cpp" >}}
