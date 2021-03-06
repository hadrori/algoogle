---
layout: page
title: "Dijkstra法"
comments: true
sharing: true
---
  
#### 基本情報
  
***

計算量 | {% m %}O(E \log V){% em %}
用途| 負辺のないグラフで単一始点最短路を求める.
  
E := 辺の数  
V := 頂点の数  

#### 解説

***

負辺の無いグラフで始点が決まっている時, その点からグラフ上の各頂点までの最短距離を求めることができる.  
Dijkstra法ではまだ調べていない頂点のうち, 始点から一番近い点を順に見ていき, その点からいける点の最短距離を更新していく.  
負辺がないのですでに調べている点はこれによって更新されることはなく, したがって順に最短路を求めることができる.  
  
まだ調べていない頂点のうち一番近い点というのは, 到達したかどうかのメモとpriority_queueなどのデータ構造を使うことで効率よく求めることができる.  
  
またpriority_queueは値が大きいものが基本的に優先されるので, greaterを指定して小さい方から取ってこさせるか, コードのように比較の不等号の意味を逆に定義させる.  

#### コード

{% include_code algorithm/dijkstra.cpp %}


#### 問題

***  

{% for post in site.tags['dijkstra'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}
