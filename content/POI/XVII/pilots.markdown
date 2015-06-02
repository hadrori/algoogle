---
layout: post
title: "POI XVII Pilots"
date: 2014-10-29T23:57:00+09:00
comments: true
category: POI
tags: [slide-min-max, inchworm-method]
---

[Pilots](http://main.edu.pl/en/archive/oi/17/pil)

#### 問題概要

****

長さnの数列aの連続する部分列で最大値と最小値の差がt以下になるものの最大の長さを求めよ

#### 解法

****

Segment Treeでやるとlogがついて計算量的に厳しい.  
スライド最小値と最大値をしゃくとりしながらやる.  
最大値-最小値がt以下ならまだ伸ばせるかもしれないので1つ伸ばす.  
そうでないなら1つ縮める.

#### コード

****

{{< includeCode "/POI/XVII/pilots.cpp" "cpp" >}}
