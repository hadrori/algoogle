---
layout: post
title: "Typical DP Contest E - 数"
date: 2014-05-13T17:10:00+09:00
comments: true
category: TDPC
tags: [dp]
---

[E - 数](http://tdpc.contest.atcoder.jp/tasks/tdpc_number)

#### 問題概要

****

#### 解法

****

len : Nの桁数  
一番左の桁から数を0~9までまわしてそれまでの合計をDでmodとったものを保存していく.  
dp[i][j][k] : 左からi桁目まででDでmodをとったものがjになる数. kは数がN未満かどうか.  
数がN以上かは, 前の状態がN以上かつ, 回してる数字がNのその桁の数以上.  
それらは基本的に無視するが, すべての桁が同じ場合は答えに含めるので,  
例外として同じ数字の時はカウントしておく. (テストケース弱いのでカウントしなくても通りはする)  
dp[len][0][1] + dp[len][0][0] - 1  
が答えになる. -1は倍数として0もカウントしてるから.  

#### コード

****

{{< includeCode "/TDPC/E.cpp" "cpp" >}}
