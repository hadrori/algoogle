---
layout: post
title: "Codeforces 383C Propagating tree"
date: 2014-07-06T08:44:00+09:00
comments: true
category: Codeforces
tags: [binary-indexed-tree, tree]
---

[Propagating tree](http://codeforces.com/problemset/problem/383/C)

#### 問題概要

****

頂点数Nの根付き木で, 各頂点には重みがある.  
そのとき以下のクエリを捌け  

* 頂点xにvalを足し, その子に-valを, さらにその子にvalを, ...と足していく
* 頂点xの重さを答えよ

#### 解法

****

深さの偶奇でそれぞれBITを用意する.  
深さの偶奇で分けてオイラーツアーして各頂点に番号を振る.  
1つ目のクエリは指定された頂点の部分木にvalを, 子供の各部分木に-valを足せばよい.

#### コード

****

{{< includeCode "/Codeforces/383C.cpp" "cpp" >}}
