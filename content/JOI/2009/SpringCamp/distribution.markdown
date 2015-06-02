---
layout: post
title: "JOI 春合宿 2009 Distribution"
date: 2014-09-09T00:38:00+09:00
comments: true
category: JOI
tags: [dp]
---

[Distribution](http://joisc2009.contest.atcoder.jp/tasks/joisc2009_distribution)

#### 問題概要

****

m冊の冊子があり, それを手にしたものは企画に参加する.  
冊子は上司から部下へのみ渡され, 一度読んだら手放して構わない.  
各人間にやる気が定められているとき, やる気の最大はいくらか

#### 解法

****

委員長から部下へ1冊の冊子を渡していくのを考える.  
この時のやる気の最大値を答えに足し, 得る経路上の人間のやる気を0にする.  
これをm回繰り替えれば良い

#### コード

****

{{< includeCode "/JOI/2009/Distribution.cpp" "cpp" >}}
