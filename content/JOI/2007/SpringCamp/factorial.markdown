---
layout: post
title: "JOI 春合宿 2007 Factorial"
date: 2014-08-26T01:54:00+09:00
comments: true
category: JOI
tags: [math]
---

[Fctorial](http://joisc2007.contest.atcoder.jp/tasks/joisc2007_factor)

#### 問題概要

****

入力としてnが与えられる.  
このnで割り切れる最小の値mを求めよ.

#### 解法

****

nを素因数分解する. 素因数分解は`$sqrt{n}$`までの各値で順に割り切れる限り割る. 最後に残った数は1より大きければ素数. 割った回数を保存しておけば素因数分解ができる.  
  
必要な素数とその個数が出たので, その個数分その素数pを用意するために必要な個数を満たすまでpにpを足していく.  
これでできた数のmaxが答え.

#### コード

****

{{< includeCode "/JOI/2007/Factorial.cpp" "cpp" >}}
