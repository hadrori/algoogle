---
layout: post
title: "Codeforces 425A Sereja and Swaps"
date: 2014-08-25T01:43:00+09:00
comments: true
category: Codeforces
tags: [brute-force]
---

[Sereja and Swaps](http://codeforces.com/contest/425/problem/A)

#### 問題概要

****

長さnの数列aのうち連続する要素の和の最大値を考える.  
k回要素の位置をswapできるとき, 最大はいくらになるか.

#### 解法

****

足し合わせる区間を決めたとき, swapするのはその区間の小さいものとその区間の外の大きいもの.  
よって区間を全てみて, それぞれ外と中でpriority_queueをもってやるとよい.  
入れ替えるのは内側の最小値が外側の最大値より小さいときに起こることに注意する.

#### コード

****

{{< includeCode "/Codeforces/425A.cpp" "cpp" >}}
