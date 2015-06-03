---
type: algorithm
title: "円"
comments: true
sharing: true
---

#### 基本情報
  
***

#### 解説

***

円クラス  
  
各関数名は以下の規則に従っている.  

* 接頭辞(1文字, 動作)
  - i: 交差判定
  - c: 交点
  - d: 距離
  
* 接尾辞(2文字, 引数)
  - c: 円
  - l: 直線
  - s: 線分
  - p: 点 

* tangent: 円の中心から伸びる角度thの半直線と垂直に交わる円の接線
* common_tangent: 2円の共通接線(最大4本)


#### コード

***

{{< includeCode "/algorithm/circle.cpp" "cpp" >}}


