---
layout: post
title: "Codeforces 258 D Little Elephant and Broken Sorting"
date: 2014-05-04T23:56:00+09:00
comments: true
category: Codeforces
tags: [dp, probabilities]
---

[Little Elephant and Broken Sorting](http://codeforces.com/contest/258/problem/D)

#### 問題概要

****

長さnの数列をm回スワップして昇順にソートしたい(各ステップでスワップする組は決まっている).  
しかし各ステップスワップするかどうかは半々の確率である.  
m回のステップが終了した時, 数列にある順序が正しくない組の個数の期待値を求めよ.

#### 解法

****

DP  
dp[i][j] := i番目がj番目より大きい確率  
として入れ替える場所をa, bとする.   
まずa, bの位置を入れ替えるかどうかなので2つの大小関係は1/2の確率でどちらにもなりうる.  
またiとa, iとbの大小関係が1/2の確率でそれぞれ入れ替わってiとb, iとaの大小関係になるので  
dp[i][a] = dp[i][b] = (dp[i][a] + dp[i][b]) / 2  
dp[a][i] = dp[b][i] = (dp[a][i] + dp[b][i]) / 2  
となる.  
最後に全ての組の確率を足し合わせれば求める期待値になる.  

#### コード

****

{{< includeCode "/Codeforces/258D.cpp" "cpp" >}}

