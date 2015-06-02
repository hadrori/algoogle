---
layout: post
title: "JOI 春合宿 2008 Origami"
date: 2014-09-04T03:10:00+09:00
comments: true
category: JOI
tags: [compress]
---

[Origami](http://joisc2008.contest.atcoder.jp/tasks/joisc2008_origami)

#### 問題概要

****

折り紙を重ねておいていくので, 一番かぶっている厚さとその面積を求めよ

#### 解法

****

座標圧縮っぽくやる.  
折り紙の幅と高さはそれぞれ高々20なので全ての位置をmapでカウントしても問題ない.  

#### コード

****

{{< includeCode "/JOI/2008/Origami.cpp" "cpp" >}}
