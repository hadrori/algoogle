---
layout: post
title: "JOI 春合宿 2009 Territory"
date: 2014-09-08T03:49:00+09:00
comments: true
category: JOI
tags: [implementation]
---

[Territory](http://joisc2009.contest.atcoder.jp/tasks/joisc2009_territory)

#### 問題概要

****

ジョイ君が歩いた経路に囲まれる部分の面積の総和を求めよ

#### 解法

****

経路を右手法で回りながら西に進むときはy座標の大きさを足して, 東に進むときはy座標の大きさを引いていくことで面積の総和を求める.  

#### コード

****

{{< includeCode "/JOI/2009/Territory.cpp" "cpp" >}}
