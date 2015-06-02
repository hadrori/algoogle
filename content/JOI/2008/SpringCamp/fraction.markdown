---
layout: post
title: "JOI 春合宿 2008 Fraction"
date: 2014-09-04T03:36:00+09:00
comments: true
category: JOI
tags: [math]
---

[Fraction](http://joisc2008.contest.atcoder.jp/tasks/joisc2008_fraction)

#### 問題概要

****

分母がM以下で1未満になる既約分数全てのなかでk番目の分数を求めよ

#### 解法

****

[Farey数列](http://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A1%E3%83%AC%E3%82%A4%E6%95%B0%E5%88%97)というそうです.  
2つの分数a/b, c/dの間の分数が(a+c)/(b+d)になる.  
これを左側から詰めていくように求めていけば良い.  


#### コード

****

{{< includeCode "/JOI/2008/Fraction.cpp" "cpp" >}}
