---
type: algorithm
title: "凸包"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 | `$O(n\log n)$`

#### 解説

***

[Andrew's monotone chain](http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain)による実装.  
求まる凸包は反時計回りの順になっている.

#### コード

***

{{< includeCode "/algorithm/convex_hull.cpp" "cpp" >}}


