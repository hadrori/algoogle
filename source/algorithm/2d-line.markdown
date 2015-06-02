---
layout: page
title: "直線と線分"
comments: true
sharing: true
---

#### 基本情報
  
***

illとcllとそれに関するものだけverified


#### 解説

***

直線クラス. 線分も兼ねている.


* vec: 方向ベクトル
* norm: ノルム
* abs: 原点からの距離
* proj: 正射影
* refl: 線対称な点


各関数名は以下の規則に従っている.  

* 接頭辞(1文字, 動作)  
  - i: 交差判定   
  - c: 交点
  - d: 距離 
  
* 接尾辞(2文字, 引数)
  - l: 直線  
  - s: 線分  
  - p: 点  


#### コード

***

{% include_code algorithm/line.cpp %}


