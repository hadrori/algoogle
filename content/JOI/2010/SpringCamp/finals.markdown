---
layout: post
title: "JOI 春合宿 2010 Finals"
date: 2014-09-17T01:55:00+09:00
comments: true
category: JOI
tags: [spanning-tree, union-find]
---

[Finals](http://joisc2010.contest.atcoder.jp/tasks/joisc2010_finals)

#### 問題概要

****

辺にコストのある無向グラフが与えられる.  
各頂点からK個の頂点を選んだとき, どの頂点もそのいずれかに到達できるように辺を選ぶ.  
使う辺のコストの和の最小を求めよ.

#### 解法

****

Kruskal法で最小全域木を求める要領でやる.  
今回は全域木ではなくてK個の木からなる全域森を考えれば良い.  
コストの小さい辺から選んでコストを足していき, 連結成分がK個になったら終了

#### コード

****

{{< includeCode "/JOI/2010/finals.cpp" "cpp" >}}
