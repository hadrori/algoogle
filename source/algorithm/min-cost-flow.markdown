---
layout: page
title: "最小費用流"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 | {% m %}O(FE\log V){% em %}
用途| 最大流を求める
  
E := 辺の数
V := 頂点数
F := 流量

#### 解説

***

#### コード

***

{% include_code algorithm/min-cost-flow.cpp %}


#### 問題

***  

{% for post in site.tags['min-cost-flow'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}
