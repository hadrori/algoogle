---
layout: post
title: "Codeforces 453A Little Pony and Expected Maximum"
date: 2014-08-03T00:36:00+09:00
comments: true
category: Codeforces
tags: [probabilities]
---

[Little Pony and Expected Maximum](http://codeforces.com/problemset/problem/453/A)

#### 問題概要

****

m面サイコロをn回投げた時の最大値の期待値

#### 解法

****

<div> $ {\displaystyle

\sum^{m}_{k=1}k\frac{k^{n}-(k-1)^{n}}{m^{n}}

} $</div>

#### コード

****

{{< includeCode "/Codeforces/453A.cpp" "cpp" >}}
