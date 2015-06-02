---
layout: post
title: "JOI 春合宿 2007 Fermat"
date: 2014-08-26T21:31:00+09:00
comments: true
category: JOI
tags: [dp]
---

[Fermat](http://joisc2007.contest.atcoder.jp/tasks/joisc2007_fermat)

#### 問題概要

****

nとpが与えられたとき以下の式を満たす(x,y,z)の組はいくつあるか(`$0\leq x,y,x \leq p-1$`)

<div> $ {\displaystyle

x^{n}+y^{n} \equiv z^{n} (mod p)

} $</div>

#### 解法

****

0からp-1までのn乗(mod p)を列挙して各値の個数を数える.  
あとはxとyの組を列挙してその和(mod p)との組合せを求める.

#### コード

****

{{< includeCode "/JOI/2007/Fermat.cpp" "cpp" >}}
