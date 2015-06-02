---
layout: post
title: "JOI 春合宿 2009 Ski"
date: 2014-09-08T18:33:00+09:00
comments: true
category: JOI
tags: [dp, binary-search]
---

[Ski](http://joisc2009.contest.atcoder.jp/tasks/joisc2009_ski)

#### 問題概要

****

各地点に高さの降順に番号がふられている.  
またリフトで行ける地点が指定されている.  
地点同士を結ぶコースがあり, それぞれ距離と速さが決まっている.  
ある場所から一番下の地点まで平均速度が一番小さいものを求め, その速度を答えよ.

#### 解法

****

平均の最小化.  
ある地点から一番下までいく複数のコースからなるルートRについて,  
平均速度x以下で行けるかどうかは以下で判断できる


<div> $ {\displaystyle

   \frac{\sum_{i\in R}d_{i}}{\sum_{i\in R} \frac{d_{i}}{s_{i}}} \leq x\\
   \sum_{i\in R}(d_{i}-x*d_{i}/s_{i}) \leq 0

} $</div>


全ルートの最小値はDPで求めることができる.  
dp\[i\] := 地点iまでの上の式の最小  
リフトで行ける地点は最大で0, 他は初期値を適当に大きな数をとる.  
あとは辺が上から下にしか伸びていないのと, 番号が高い方から振られていることからfor文を回してminを取るだけで更新できる.  

#### コード

****

{{< includeCode "/JOI/2009/Ski.cpp" "cpp" >}}
