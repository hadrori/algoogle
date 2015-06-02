---
layout: post
title: "Codeforces 459D Pashmak and Parmida's problem"
date: 2014-08-16T17:03:00+09:00
comments: true
category: Codeforces
tags: [binary-indexed-tree]
---

[Pashmak and Parmida's problem](http://codeforces.com/problemset/problem/459/D)

#### 問題概要

****

長さn数列bについて以下を満たすi, jの組の個数を求めよ.  

* `$ 0 \leq i < j < n $`
* 区間\[0,i\]に出現するb\[i\]の個数 > 閉区間\[j,n\)に出現するb\[j\]の個数

#### 解法

****

区間\[j,n\)に存在するb\[j\]の個数はj=n-1からmapでカウントしていけば求められる.  
これをg\[j\]とする.  
同様に\[0,i\]に存在するb\[i\]の個数も求められるのでf\[i\]とする.  
  
fを予め求めておく.  
f\[i\]に対してそれより小さいg\[j\](i<j)の数は区間[i+1,n)でg\[j\]の値をインデックスとしてその個数をもつbitをつくればlognで求められる.  
よってi=n-1から順次bitを更新しながらf\[i\]未満になるg\[j\]の個数の総和を足し合わせれば良い.

#### コード

****

{{< includeCode "/Codeforces/459D.cpp" "cpp" >}}
