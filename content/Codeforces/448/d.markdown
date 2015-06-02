---
layout: post
title: "Codeforces 448D Multiplication Table"
date: 2014-07-18T13:49:00+09:00
comments: true
category: Codeforces
tags: [binary-search]
---

[Multiplication Table](http://codeforces.com/problemset/problem/448/D)

#### 問題概要

****

n*mの九九表で, k番目に小さい数を求めよ

#### 解法

****

値を二分探索する.  
ある値p以下になる数がk個以上存在するかを判定する.  
判定は九九表を縦にみて, 上からi番目の段の最大値(m*i)がp以下ならm個, そうでないならp/i個その段にp以下の数が存在する.  
なぜならその段はi, 2i, 3i, 4i...となっているから  
  
#### コード

****

{{< includeCode "/Codeforces/448D.cpp" "cpp" >}}
