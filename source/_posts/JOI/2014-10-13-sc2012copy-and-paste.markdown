---
layout: post
title: "JOI 春合宿 2012 Copy and Paste"
date: 2014-10-13 18:11:49 +0900
comments: true
category: JOI
tags: [data-structure]
---

[Copy and Paste](http://joisc2012.contest.atcoder.jp/tasks/joisc2012_copypaste)

#### 問題概要

****

文字列を\[l,r)をコピーして, 場所kに挿入するというクエリがN(<=1000000)回くる.  
ただし毎回長さがM(<=1000000)を超える場合はそれ以降は切り捨てる.  
最終的に作られる文字列を答えよ

#### 解法

****

永続赤黒木を使ってやる.  
[解説スライド](http://www.ioi-jp.org/camp/2012/2012-sp-tasks/2012-sp-day4-copypaste-slides.pdf)  
メモリが足りなくなったら木を再構築する.  
木を構築するときは文字列を半分にして右と左でできた木をマージする.  
ノードを再利用するのでノードのメモリ確保にnewするのではなく, 予め配列で用意しておいてそれを割り当てる.  
この配列から溢れる前に再構築する.

#### コード

****

{% include_code JOI/2012/copy-and-paste.cpp %}
