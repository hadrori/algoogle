---
layout: post
title: "JOI 春合宿 2007 Building"
date: 2014-08-26T21:27:00+09:00
comments: true
category: JOI
tags: [dp]
---

[Building](http://joisc2007.contest.atcoder.jp/tasks/joisc2007_buildi)

#### 問題概要

****

最長増加部分列の長さを求めよ.

#### 解法

****

DPする.  
制約の関係上O(n^2)でも通るがO(n log n)の有名なDP.  

#### コード

****

{{< includeCode "/JOI/2007/Building.cpp" "cpp" >}}
