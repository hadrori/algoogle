---
layout: post
title: "JOI 春合宿 2007 Lines"
date: 2014-08-28T02:32:00+09:00
comments: true
category: JOI
tags: [geometory]
---

[Lines](http://joisc2007.contest.atcoder.jp/tasks/joisc2007_lines)

#### 問題概要

****

直線のリストが与えられるので, それらの直線によって分割された平面の数を求めよ.

#### 解法

****

平面グラフにおいて, 面の数fは頂点数vと辺数eと以下の関係をもつ


<div> $ {\displaystyle

v-e+f=1

} $</div>

各直線から作られる辺の数は各直線が持つ交点数+1に等しいのでこれを求める.  
頂点数は交点数.

#### コード

****

{{< includeCode "/JOI/2007/Lines.cpp" "cpp" >}}
