---
layout: post
title: "Codeforces 343C Read Time"
date: 2014-05-15T00:56:00+09:00
comments: true
category: Codeforces
tags: [binary-search]
---

[Read Time](http://codeforces.com/problemset/problem/343/C)

#### 問題概要

****

#### 解法

****

かかる時間を二分探索する.  
ある時間を決めて, その時間以下になるようにheadを動かしていく.  
順にheadを見ていって, 左側にまだ読み取ってない場所があるならそれを読み取る.  
そのとき時間オーバーなら失敗.  
次にできるだけ右側を見ていく.  
はじめ左側を見た場合、往復を挟むので順に右側を見ていく時の時間の比較は  
はじめに右側を見たと仮定した場合も考慮する(どちらの往復のほうが得か考える).  

#### コード

****

{{< includeCode "/Codeforces/343C.cpp" "cpp" >}}
