---
layout: post
title: "Typical DP Contest G - 辞書順"
date: 2014-05-13T16:56:00+09:00
comments: true
category: TDPC
tags: [dp]
---

[G - 辞書順](http://tdpc.contest.atcoder.jp/tasks/tdpc_lexicographical)

#### 問題概要

****

#### 解法

****

dp[i][c]: i 文字目以降の部分列で文字 c から始まるものの個数  
というテーブルを用意してから復元  
復元の仕方は, i文字目以降でcから始まる部分文字列の数というのを考えると  
一番左側を見ている時, aから順にzまで見ていって, aから始まる場合の数+bから始める場合の数+…とした時に初めてKを超える文字が答えの一番左側の文字になる. Kはその前までの場合の数分引いておく.  
つぎはその文字が現れる位置の次の位置に移動して, 場合の数がKを超える文字をまた探す.  
この再帰で復元できる.  

#### コード

****

{{< includeCode "/TDPC/G.cpp" "cpp" >}}

