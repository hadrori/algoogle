---
layout: post
title: "Typical DP Contest A - コンテスト"
date: 2014-05-13T17:48:00+09:00
comments: true
category: TDPC
tags: [dp]
---

[A - コンテスト](http://tdpc.contest.atcoder.jp/tasks/tdpc_contest)

#### 問題概要

****

#### 解法

****

点数の情報を追加するたびにそれまでのの点数の情報から出来るパターンに  
新しい点数を足したものを追加する.
dp[i + p] |= dp[i]  
みたいにする. 上書きしていってるので, iは大きい方から処理していく.  


#### コード

****

{{< includeCode "/TDPC/A.d" "d" >}}

