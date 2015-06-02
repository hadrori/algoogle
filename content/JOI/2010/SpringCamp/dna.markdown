---
layout: post
title: "JOI 春合宿 2010 DNA Synthesizer"
date: 2014-09-15T02:44:00+09:00
comments: true
category: JOI
tags: [aho-corasick, dp]
---

[DNA Synthesizer](http://joisc2010.contest.atcoder.jp/tasks/joisc2010_dna)

#### 問題概要

****

DNAはATGCの4つの文字から成る.  
今N個の素DNAがある(長さはそれぞれ高々20).  
あるDNAを作りたいとき, 素DNA同士を長さ1以上重なるようにつなげることで作ることができる.  
素DNAはそれぞれ何個でも使える.  
最小何個の素DNAで目的のDNAを作れるか.  


#### 解法

****

Aho-Corasick法で目的のDNAの各位置でパターン(素DNA)とマッチするかみる.  
このときマッチするもののうち, 最長のものだけ見れば良い.  
あとはDPすればよい.  
dp[i] := i文字目までつくるのに必要な最小の素DNAの数  
更新はマッチした部分の中でdpが最小になっている部分+1でできる.  
これはSegment-Treeを用いることで効率的にできるが, 今回はパターンの長さが高々20なので愚直に更新してもよい.

#### コード

****

{{< includeCode "/JOI/2010/dna.cpp" "cpp" >}}
