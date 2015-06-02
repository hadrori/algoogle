---
layout: post
title: "Typical DP Contest D - サイコロ"
date: 2014-05-13T17:18:00+09:00
comments: true
category: TDPC
tags: [dp]
---

[D - サイコロ](http://tdpc.contest.atcoder.jp/tasks/tdpc_dice)

#### 問題概要

****

#### 解法

****

dp[i][j][k][l] := i回サイコロを振って2^j 3^k 5^l
になる確率. ただし, j,k,lがDの素因数の指数部分より大きい場合は
Dの指数部分の大きさに合わせることで, Dの倍数の確率も合わせて見ることが出来る.

#### コード

****

{{< includeCode "/TDPC/D.cpp" "cpp" >}}
