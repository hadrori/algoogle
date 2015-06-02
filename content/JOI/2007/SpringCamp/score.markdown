---
layout: post
title: "JOI 春合宿 2007 Score"
date: 2014-08-26T01:46:00+09:00
comments: true
category: JOI
tags: [implementation]
---

[Score](http://joisc2007.contest.atcoder.jp/tasks/joisc2007_score)

#### 問題概要

****

得点のリストが与えられるので, それぞれの順位を答えよ

#### 解法

****

値に対してidを持ってソート.  
ソートした値を順にみてi番目の順位は前の順位から変動したらi位, そうでなければ前と同じ.  
これを各人に対して保存したらそれぞれの人を順に見ていく.  

#### コード

****

{{< includeCode "/JOI/2007/Score.cpp" "cpp" >}}
