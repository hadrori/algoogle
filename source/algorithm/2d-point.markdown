---
layout: page
title: "点"
comments: true
sharing: true
---

#### 基本情報
  
***


#### 解説

***

complexではなくpointクラスを作った.  


* norm: ノルム
* abs: 原点からの距離
* arg: 角度({% m %}-\pi{% em %}から{% m %}\pi{% em %})
* dot: 内積
* cross,det: 外積(行列式)
* proj: 直線(0,0),(x,y)への正射影


ccwはa->b->cの順で進むとき  
1ならccw(反時計回り), -1ならcw(時計回り), 2なら折り返し, -2なら直進, 0なら線分上に折り返し  


#### コード

***

{% include_code algorithm/point.cpp %}


