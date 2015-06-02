---
layout: post
title: "JOI 春合宿 2008 Committee"
date: 2014-09-04T01:55:00+09:00
comments: true
category: JOI
tags: [dp]
---

[Committee](http://joisc2008.contest.atcoder.jp/tasks/joisc2008_committee)

#### 問題概要

****

上司が親の根付き木が与えられる.  
連結な部分を取り出したときの各ノードのやる気の総和の最大を求めよ.  
ただし頂点はかならず1つ以上含むこと.

#### 解法

****

簡単な木DP  
木の葉の子から親にやる気を順に足していけば良い. ただし子のやる気が負の時は足さない方がいいので足さない.  


#### コード

****

{{< includeCode "/JOI/2008/Committee.cpp" "cpp" >}}
